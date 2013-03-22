#include <cstdlib>
#include "../include/ThreadedBinaryTreeNode.h"
using namespace std;

ThreadedBinaryTreeNode::ThreadedBinaryTreeNode(void) : previous(NULL), next(NULL)
{
}

ThreadedBinaryTreeNode::ThreadedBinaryTreeNode(const ThreadedBinaryTreeNode& b) : BinaryTreeNode(b), previous(b.previous), next(b.next)
{
}

ThreadedBinaryTreeNode& ThreadedBinaryTreeNode::operator=(const ThreadedBinaryTreeNode& b)
{
    this->previous = b.previous;
	this->next = b.next;
    return *this;
}

ThreadedBinaryTreeNode::~ThreadedBinaryTreeNode(void)
{
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
