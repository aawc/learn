#include <iostream>
#include <cstdlib>
#include <time.h>
#include "../include/BinaryTreeNode.h"
#include "../include/BinaryTree.h"
using namespace std;

BinaryTree::BinaryTree(void) : root(NULL)
{
    Init();
    this->Build();
}

BinaryTree::BinaryTree(const BinaryTree& b) : root(b.root)
{
    Init();
}

BinaryTree& BinaryTree::operator=(const BinaryTree& b)
{
    if (this == &b) return *this; // handle self assignment
    this->root = b.root;
    return *this;
}

BinaryTree::~BinaryTree(void)
{
    this->Free(this->root);
}

void BinaryTree::Init(void)
{
    if (!initialized)
    {
        srand((unsigned)time(NULL));
        initialized = true;
    }
}

void BinaryTree::Build(void)
{
    int numberOfElements = rand() % MAX_ELEMENTS + 1;
    cout << "Number of elements: " << numberOfElements << endl;
    for (int i = 0; i < numberOfElements; i++)
    {
        BinaryTreeNode* node = new BinaryTreeNode();
        if (node == NULL)
        {
            cout << "Memory allocation failed!" << endl;
            this->Free(this->root);
            return;
        }
        node->setInfo(rand());
        node->setLeft(NULL);
        node->setRight(NULL);

        this->InsertNode(node);
    }

    this->DisplayPreOrder(this->root);
    this->DisplayInOrder(this->root);
    this->DisplayPostOrder(this->root);
}

BinaryTreeNode* BinaryTree::FindPreOrderParent(int info, BinaryTreeNode* node)
{
    if (node == NULL)
    {
        return NULL;
    }

    BinaryTreeNode* next = NULL;
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

void BinaryTree::DisplayPreOrder(BinaryTreeNode* node)
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

void BinaryTree::DisplayInOrder(BinaryTreeNode* node)
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

void BinaryTree::DisplayPostOrder(BinaryTreeNode* node)
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

void BinaryTree::InsertNode(BinaryTreeNode* parent, BinaryTreeNode* node)
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

void BinaryTree::InsertNode(BinaryTreeNode* node)
{
    if (this->root == NULL)
    {
        this->root = node;
        cout << "Added as root: " << node->getInfo() << endl;
        return;
    }
    this->InsertNode(this->root, node);
}

void BinaryTree::Free(BinaryTreeNode* node)
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

bool BinaryTree::initialized;
const int BinaryTree::MAX_ELEMENTS;
