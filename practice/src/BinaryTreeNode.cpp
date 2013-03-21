#include "../include/BinaryTreeNodeNode.h"
using namespace std;

BinaryTreeNode::BinaryTreeNode(void) : root(NULL)
{
    Init();
    this->Build();
}

BinaryTreeNode::BinaryTreeNode(const BinaryTreeNode& b) : root(b.root)
{
    Init();
}

BinaryTreeNode& BinaryTreeNode::operator=(const BinaryTreeNode& b)
{
    this->root = b.root;
    return *this;
}

BinaryTreeNode::~BinaryTreeNode(void)
{
    this->Free(this->root);
}

void BinaryTreeNode::Init(void)
{
    if (!initialized)
    {
        srand(time(NULL));
        initialized = true;
    }
}

void BinaryTreeNode::Build(void)
{
    int numberOfElements = rand() % MAX_ELEMENTS + 1;
    cout << "Number of elements: " << numberOfElements << endl;
    for (int i = 0; i < numberOfElements; i++)
    {
        BinaryTreeNodeNode* node = new BinaryTreeNodeNode();
        if (node == NULL)
        {
            cout << "Memory allocation failed!" << endl;
            this->Free(this->root);
            return;
        }
        node->setInfo(rand());
        node->left = NULL;
        node->right = NULL;

        this->InsertNode(node);
    }

    this->DisplayPreOrder(this->root);
    this->DisplayInOrder(this->root);
    this->DisplayPostOrder(this->root);
}

BinaryTreeNodeNode* BinaryTreeNode::FindPreOrderParent(int info, BinaryTreeNodeNode* node)
{
    if (node == NULL)
    {
        return NULL;
    }

    BinaryTreeNodeNode* next = NULL;
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

void BinaryTreeNode::DisplayPreOrder(BinaryTreeNodeNode* node)
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

void BinaryTreeNode::DisplayInOrder(BinaryTreeNodeNode* node)
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

void BinaryTreeNode::DisplayPostOrder(BinaryTreeNodeNode* node)
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

void BinaryTreeNode::InsertNode(BinaryTreeNodeNode* parent, BinaryTreeNodeNode* node)
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

void BinaryTreeNode::InsertNode(BinaryTreeNodeNode* node)
{
    if (this->root == NULL)
    {
        this->root = node;
        cout << "Added as root: " << node->info << endl;
        return;
    }
    this->InsertNode(this->root, node);
}

void BinaryTreeNode::Free(BinaryTreeNodeNode* node)
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
bool BinaryTreeNode::initialized;
const int BinaryTreeNode::MAX_ELEMENTS;

