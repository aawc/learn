#include <cstdlib>
#include "../include/BinaryTreeNode.h"
using namespace std;

BinaryTreeNode::BinaryTreeNode(void) : info(0), left(NULL), right(NULL)
{
}

BinaryTreeNode::BinaryTreeNode(const BinaryTreeNode& b) : info(b.info), left(b.left), right(b.right)
{
}

BinaryTreeNode& BinaryTreeNode::operator=(const BinaryTreeNode& b)
{
    if (this == &b) return *this; // handle self assignment
	this->info = b.info;
    this->left = b.left;
	this->right = b.right;
    return *this;
}

BinaryTreeNode::~BinaryTreeNode(void)
{
}

int BinaryTreeNode::getInfo()
{
	return this->info;
}

BinaryTreeNode* BinaryTreeNode::getLeft()
{
	return this->left;
}

BinaryTreeNode* BinaryTreeNode::getRight()
{
	return this->right;
}

void BinaryTreeNode::setInfo(int value)
{
	this->info = value;
}

void BinaryTreeNode::setLeft(BinaryTreeNode* value)
{
	this->left = value;
}

void BinaryTreeNode::setRight(BinaryTreeNode* value)
{
	this->right = value;
}
