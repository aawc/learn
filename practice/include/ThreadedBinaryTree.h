#include "BinaryTree.h"

class ThreadedBinaryTreeNode;

class ThreadedBinaryTree : BinaryTree
{
	public:
		ThreadedBinaryTree(void);
		ThreadedBinaryTree(const ThreadedBinaryTree& b);
		ThreadedBinaryTree& operator=(const ThreadedBinaryTree& b);

		virtual ~ThreadedBinaryTree(void);

		void BuildThreads(void);

	private:
		void BuildThreadsForNode(ThreadedBinaryTreeNode* node, ThreadedBinaryTreeNode* subTreePredecessor, ThreadedBinaryTreeNode* subTreeSuccessor, ThreadedBinaryTreeNode** first, ThreadedBinaryTreeNode** last);
};
