#include <cstdlib>
#include "../include/ThreadedBinaryTreeNode.h"
using namespace std;

ThreadedBinaryTreeNode::ThreadedBinaryTreeNode(void) : info(0), left(NULL), right(NULL), previous(NULL), next(NULL)
{
}

ThreadedBinaryTreeNode::ThreadedBinaryTreeNode(const ThreadedBinaryTreeNode& b)
	: info(b.info), left(b.left), right(b.right), previous(b.previous), next(b.next)
{
}

ThreadedBinaryTreeNode& ThreadedBinaryTreeNode::operator=(const ThreadedBinaryTreeNode& b)
{
	this->info = b.info;
    this->left = b.left;
	this->right = b.right;
    this->previous = b.previous;
	this->next = b.next;
    return *this;
}

ThreadedBinaryTreeNode::~ThreadedBinaryTreeNode(void)
{
}

int ThreadedBinaryTreeNode::getInfo()
{
	return this->info;
}

ThreadedBinaryTreeNode* ThreadedBinaryTreeNode::getLeft()
{
	return this->left;
}

ThreadedBinaryTreeNode* ThreadedBinaryTreeNode::getRight()
{
	return this->right;
}

void ThreadedBinaryTreeNode::setInfo(int value)
{
	this->info = value;
}

void ThreadedBinaryTreeNode::setLeft(ThreadedBinaryTreeNode* value)
{
	this->left = value;
}

void ThreadedBinaryTreeNode::setRight(ThreadedBinaryTreeNode* value)
{
	this->right = value;
}

ThreadedBinaryTreeNode* ThreadedBinaryTreeNode::getPrevious()
{
	return this->previous;
}

ThreadedBinaryTreeNode* ThreadedBinaryTreeNode::getNext()
{
	return this->next;
}

void ThreadedBinaryTreeNode::setPrevious(ThreadedBinaryTreeNode* value)
{
	this->previous = value;
}

void ThreadedBinaryTreeNode::setNext(ThreadedBinaryTreeNode* value)
{
	this->next = value;
}
