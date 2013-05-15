#include <iostream>
#include <cstdlib>
#include <time.h>
#include "../include/ThreadedBinaryTreeNode.h"
#include "../include/ThreadedBinaryTree.h"
using namespace std;

ThreadedBinaryTree::ThreadedBinaryTree(void) : root(NULL)
{
    Init();
    this->Build();
	this->BuildThreads();
	this->Display();
}

ThreadedBinaryTree::ThreadedBinaryTree(const ThreadedBinaryTree& b) : root(b.root)
{
    Init();
}

ThreadedBinaryTree& ThreadedBinaryTree::operator=(const ThreadedBinaryTree& b)
{
    if (this == &b) return *this; // handle self assignment
    this->root = b.root;
    return *this;
}

ThreadedBinaryTree::~ThreadedBinaryTree(void)
{
    this->Free(this->root);
}

void ThreadedBinaryTree::Init(void)
{
    if (!initialized)
    {
        srand((unsigned)time(NULL));
        initialized = true;
    }
}

void ThreadedBinaryTree::Build(void)
{
    int numberOfElements = rand() % MAX_ELEMENTS + 1;
    cout << "Number of elements: " << numberOfElements << endl;
    for (int i = 0; i < numberOfElements; i++)
    {
        ThreadedBinaryTreeNode* node = new ThreadedBinaryTreeNode();
        if (node == NULL)
        {
            cout << "Memory allocation failed!" << endl;
            this->Free(this->root);
            return;
        }
        node->setInfo(rand());
        node->setLeft(NULL);
        node->setRight(NULL);
        node->setPrevious(NULL);
        node->setNext(NULL);

        this->InsertNode(node);
    }
}

ThreadedBinaryTreeNode* ThreadedBinaryTree::FindPreOrderParent(int info, ThreadedBinaryTreeNode* node)
{
    if (node == NULL)
    {
        return NULL;
    }

    ThreadedBinaryTreeNode* next = NULL;
    if (node->getInfo() < info)
    {
        next = this->FindPreOrderParent(info, node->getRight());
    }
    else if (node->getInfo() > info)
    {
        next = this->FindPreOrderParent(info, node->getLeft());
    }

    return (next == NULL) ? node : next;
}

void ThreadedBinaryTree::DisplayPreOrder(ThreadedBinaryTreeNode* node)
{
    if (node == this->root)
    {
        cout << "DisplayPreOrder:" << endl;
    }
    if (node == NULL)
    {
        return;
    }

    ThreadedBinaryTreeNode* previous = node->getPrevious();
    ThreadedBinaryTreeNode* next = node->getNext();
    cout << node->getInfo();
    cout << " | Previous: " << (previous == NULL? -1 : previous->getInfo());
    cout << " | Next: " << (next == NULL? -1 : next->getInfo());
    cout << endl;

    this->DisplayPreOrder(node->getLeft());
    this->DisplayPreOrder(node->getRight());
}

void ThreadedBinaryTree::DisplayInOrder(ThreadedBinaryTreeNode* node)
{
    if (node == this->root)
    {
        cout << "DisplayInOrder:" << endl;
    }
    if (node == NULL)
    {
        return;
    }

    this->DisplayInOrder(node->getLeft());

    ThreadedBinaryTreeNode* previous = node->getPrevious();
    ThreadedBinaryTreeNode* next = node->getNext();
    cout << node->getInfo();
    cout << " | Previous: " << (previous == NULL? -1 : previous->getInfo());
    cout << " | Next: " << (next == NULL? -1 : next->getInfo());
    cout << endl;

    this->DisplayInOrder(node->getRight());
}

void ThreadedBinaryTree::DisplayPostOrder(ThreadedBinaryTreeNode* node)
{
    if (node == this->root)
    {
        cout << "DisplayPostOrder:" << endl;
    }
    if (node == NULL)
    {
        return;
    }
    this->DisplayPostOrder(node->getLeft());
    this->DisplayPostOrder(node->getRight());

    ThreadedBinaryTreeNode* previous = node->getPrevious();
    ThreadedBinaryTreeNode* next = node->getNext();
    cout << node->getInfo();
    cout << " | Previous: " << (previous == NULL? -1 : previous->getInfo());
    cout << " | Next: " << (next == NULL? -1 : next->getInfo());
    cout << endl;
}

void ThreadedBinaryTree::InsertNode(ThreadedBinaryTreeNode* parent, ThreadedBinaryTreeNode* node)
{
    if (node->getInfo() == parent->getInfo())
    {
        cout << "Dropping: " << node->getInfo() << endl;
        return;
    }

    if (node->getInfo() < parent->getInfo())
    {
        if (parent->getLeft() == NULL)
        {
            parent->setLeft(node);
            cout << "Added: " << node->getInfo() << " to the left of: " << parent->getInfo() <<endl;
        }
        else
        {
        this->InsertNode(parent->getLeft(), node);
        }
    }
    else
    {
        if (parent->getRight() == NULL)
        {
            parent->setRight(node);
            cout << "Added: " << node->getInfo() << " to the right of: " << parent->getInfo() <<endl;
        }
        else
        {
        this->InsertNode(parent->getRight(), node);
        }
    }
}

void ThreadedBinaryTree::InsertNode(ThreadedBinaryTreeNode* node)
{
    if (this->root == NULL)
    {
        this->root = node;
        cout << "Added as root: " << node->getInfo() << endl;
        return;
    }
    this->InsertNode(this->root, node);
}

void ThreadedBinaryTree::Free(ThreadedBinaryTreeNode* node)
{
    if (node != NULL)
    {
        this->Free(node->getLeft());
        cout << "Deleting: " << node->getInfo() << endl;
        this->Free(node->getRight());

        delete node;
        node = NULL;
    }
}

void ThreadedBinaryTree::BuildThreads(void)
{
	ThreadedBinaryTreeNode *first, *last;
	ThreadedBinaryTree::BuildThreadsForNode(this->root, NULL, NULL, &first, &last);
}

void ThreadedBinaryTree::BuildThreadsForNode(
		ThreadedBinaryTreeNode* node,
		ThreadedBinaryTreeNode* subTreePredecessor,
		ThreadedBinaryTreeNode* subTreeSuccessor,
		ThreadedBinaryTreeNode** first,
		ThreadedBinaryTreeNode** last)
{
	ThreadedBinaryTreeNode *leftFirst, *leftLast, *rightFirst, *rightLast;
	ThreadedBinaryTreeNode* left = node->getLeft();
	ThreadedBinaryTreeNode* right = node->getRight();

	if (left != NULL && right != NULL)
	{
		ThreadedBinaryTree::BuildThreadsForNode(left, subTreePredecessor, node, &leftFirst, &leftLast);
		ThreadedBinaryTree::BuildThreadsForNode(right, node, subTreeSuccessor, &rightFirst, &rightLast);

		node->setPrevious(leftLast);
		node->setNext(rightFirst);

		leftLast->setNext(node);
		rightFirst->setPrevious(node);

		*first = leftFirst;
		*last = rightLast;
	}
	else if (left == NULL && right == NULL)
	{
		node->setPrevious(subTreePredecessor);
		node->setNext(subTreeSuccessor);

		*first = node;
		*last = node;
	}
	else if (left != NULL)
	{
		ThreadedBinaryTree::BuildThreadsForNode(left, subTreePredecessor, node, &leftFirst, &leftLast);

		node->setPrevious(leftLast);
		node->setNext(subTreeSuccessor);

		leftLast->setNext(node);

		*first = leftFirst;
		*last = node;
	}
	else
	{
		ThreadedBinaryTree::BuildThreadsForNode(right, node, subTreeSuccessor, &rightFirst, &rightLast);

		node->setPrevious(subTreePredecessor);
		node->setNext(rightFirst);

		rightFirst->setPrevious(node);

		*first = node;
		*last = rightLast;
	}
}

void ThreadedBinaryTree::Display(void)
{
    this->DisplayPreOrder(this->root);
    this->DisplayInOrder(this->root);
    this->DisplayPostOrder(this->root);
}

bool ThreadedBinaryTree::initialized;
