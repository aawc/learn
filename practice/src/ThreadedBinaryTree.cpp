#include <iostream>
#include <cstdlib>
#include "../include/ThreadedBinaryTreeNode.h"
#include "../include/ThreadedBinaryTree.h"
using namespace std;

ThreadedBinaryTree::ThreadedBinaryTree(void) : BinaryTree()
{
}

ThreadedBinaryTree::ThreadedBinaryTree(const ThreadedBinaryTree& b) : BinaryTree(b)
{
}

ThreadedBinaryTree& ThreadedBinaryTree::operator=(const ThreadedBinaryTree& b)
{
    if (this == &b) return *this; // handle self assignment
	BinaryTree::operator=(b);
    return *this;
}

ThreadedBinaryTree::~ThreadedBinaryTree(void)
{
}

void ThreadedBinaryTree::BuildThreads(void)
{
	ThreadedBinaryTreeNode *first, *last;
	BuildThreadsForNode(this->root, NULL, NULL, &first, &last);
}

void ThreadedBinaryTree::BuildThreadsForNode(ThreadedBinaryTreeNode* node, ThreadedBinaryTreeNode* subTreePredecessor, ThreadedBinaryTreeNode* subTreeSuccessor, ThreadedBinaryTreeNode** first, ThreadedBinaryTreeNode** last)
{
	ThreadedBinaryTreeNode *leftFirst, *leftLast, *rightFirst, *rightLast;
	if (node->getLeft() != NULL && node->getRight() != NULL)
	{
		this->BuildThreadsForNode(node->getLeft(), subTreePredecessor, node, &leftFirst, &leftLast);
		this->BuildThreadsForNode(node->getRight(), node, subTreeSuccessor, &rightFirst, &rightLast);

		//subTreePredecessor->setNext(leftFirst);
		//subTreeSuccessor->setPrevious(rightLast);
		node->setPrevious(leftLast);
		node->setNext(rightFirst);

		leftLast->setNext(node);
		rightFirst->setPrevious(node);

		first = &leftFirst;
		last = &rightLast;
	}
	else if (node->getLeft() == NULL && node->getRight() == NULL)
	{
		//subTreePredecessor->setNext(node);
		//subTreeSuccessor->setPrevious(node);
		node->setPrevious(subTreePredecessor);
		node->setNext(subTreeSuccessor);

		first = &node;
		last = &node;
	}
	else if (node->getLeft() != NULL)
	{
		this->BuildThreadsForNode(node->getLeft(), subTreePredecessor, node, &leftFirst, &leftLast);

		//subTreePredecessor->setNext(leftFirst);
		//subTreeSuccessor->setPrevious(node);
		node->setPrevious(leftLast);
		node->setNext(subTreeSuccessor);

		leftLast->setNext(node);
		subTreeSuccessor->setPrevious(node);

		first = &leftFirst;
		last = &node;
	}
	else
	{
		this->BuildThreadsForNode(node->getRight(), node, subTreeSuccessor, &rightFirst, &rightLast);

		//subTreePredecessor->setNext(leftFirst);
		//subTreeSuccessor->setPrevious(node);
		node->setPrevious(subTreePredecessor);
		node->setNext(rightFirst);

		rightFirst->setPrevious(node);
		subTreePredecessor->setNext(node);

		first = &node;
		last = &rightLast;
	}
}

/*
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
    cout << node->getInfo() << endl;
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
    cout << node->getInfo() << endl;
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
    cout << node->getInfo() << endl;
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
bool ThreadedBinaryTree::initialized;
const int ThreadedBinaryTree::MAX_ELEMENTS;
*/
