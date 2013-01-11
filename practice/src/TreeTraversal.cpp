#include <iostream>
#include <cstdlib>
#include <time.h>
#include "../include/TreeTraversal.h"
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
        srand(time(NULL));
        initialized = true;
    }
}

void BinaryTree::Build(void)
{
    int numberOfElements = rand() % MAX_ELEMENTS + 1;
    cout << "Number of elements: " << numberOfElements << endl;
    for (int i = 0; i < numberOfElements; i++)
    {
        int info = rand();
        TreeNode* node = new TreeNode();
        if (node == NULL)
        {
            cout << "Memory allocation failed!" << endl;
            this->Free(this->root);
            return;
        }
        node->info = info;
        node->left = NULL;
        node->right = NULL;

        this->InsertNode(node);
    }

    this->DisplayPreOrder(this->root);
    this->DisplayInOrder(this->root);
    this->DisplayPostOrder(this->root);
}

TreeNode* BinaryTree::FindPreOrderParent(int info, TreeNode* node)
{
    if (node == NULL)
    {
        return NULL;
    }

    TreeNode* next = NULL;
    if (node->info < info)
    {
        next = this->FindPreOrderParent(info, node->right);
    }
    else if (node->info > info)
    {
        next = this->FindPreOrderParent(info, node->left);
    }

    return (next == NULL) ? node : next;
}

void BinaryTree::DisplayPreOrder(TreeNode* node)
{
    if (node == this->root)
    {
        cout << "DisplayPreOrder:" << endl;
    }
    if (node == NULL)
    {
        return;
    }
    cout << node->info << endl;
    this->DisplayPreOrder(node->left);
    this->DisplayPreOrder(node->right);
}

void BinaryTree::DisplayInOrder(TreeNode* node)
{
    if (node == this->root)
    {
        cout << "DisplayInOrder:" << endl;
    }
    if (node == NULL)
    {
        return;
    }
    this->DisplayInOrder(node->left);
    cout << node->info << endl;
    this->DisplayInOrder(node->right);
}

void BinaryTree::DisplayPostOrder(TreeNode* node)
{
    if (node == this->root)
    {
        cout << "DisplayPostOrder:" << endl;
    }
    if (node == NULL)
    {
        return;
    }
    this->DisplayPostOrder(node->left);
    this->DisplayPostOrder(node->right);
    cout << node->info << endl;
}

void BinaryTree::InsertNode(TreeNode* parent, TreeNode* node)
{
    if (node->info == parent->info)
    {
        cout << "Dropping: " << node->info << endl;
        return;
    }

    if (node->info < parent->info)
    {
        if (parent->left == NULL)
        {
            parent->left = node;
            cout << "Added: " << node->info << " to the left of: " << parent->info <<endl;
        }
        else
        {
        this->InsertNode(parent->left, node);
        }
    }
    else
    {
        if (parent->right == NULL)
        {
            parent->right = node;
            cout << "Added: " << node->info << " to the right of: " << parent->info <<endl;
        }
        else
        {
        this->InsertNode(parent->right, node);
        }
    }
}

void BinaryTree::InsertNode(TreeNode* node)
{
    if (this->root == NULL)
    {
        this->root = node;
        cout << "Added as root: " << node->info << endl;
        return;
    }
    this->InsertNode(this->root, node);
}

void BinaryTree::Free(TreeNode* node)
{
    if (node != NULL)
    {
        this->Free(node->left);
        cout << "Deleting: " << node->info << endl;
        this->Free(node->right);

        delete node;
        node = NULL;
    }
}
bool BinaryTree::initialized;
const int BinaryTree::MAX_ELEMENTS;
