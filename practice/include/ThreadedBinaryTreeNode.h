#include "BinaryTreeNode.h"

class ThreadedBinaryTreeNode : BinaryTreeNode
{
	private:
		// The pointers to previous and next nodes in-order.
		ThreadedBinaryTreeNode* previous;
		ThreadedBinaryTreeNode* next;

	public:
		ThreadedBinaryTreeNode();
		virtual ~ThreadedBinaryTreeNode();
		ThreadedBinaryTreeNode(const ThreadedBinaryTreeNode& b);
		ThreadedBinaryTreeNode& operator=(const ThreadedBinaryTreeNode& b);

		ThreadedBinaryTreeNode* getPrevious();
		ThreadedBinaryTreeNode* getNext();
		void setPrevious(ThreadedBinaryTreeNode*);
		void setNext(ThreadedBinaryTreeNode*);
};
