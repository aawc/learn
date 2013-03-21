#include "BinaryTree.h"

class ThreadedBinaryTreeNode : TreeNode
{
	// The pointers to previous and next nodes in-order.
	tagThreadedBinaryTreeNode *previous;
	tagThreadedBinaryTreeNode *next;
};
/*
class ThreadedBinaryTree
{
	private:
		ThreadedBinaryTreeNode* root;
		static bool initialized;
		static const int MAX_ELEMENTS = 15;

	public:
		class ThreadedBinaryTree(void);
		ThreadedBinaryTree(const ThreadedBinaryTree& b);
		ThreadedBinaryTree& operator=(const ThreadedBinaryTree& b);

		~ThreadedBinaryTree(void);

	private:
	    static void Init(void);
		void Build(void);
		ThreadedBinaryTreeNode* FindPreOrderParent(int info, ThreadedBinaryTreeNode* node);
		void DisplayPreOrder(ThreadedBinaryTreeNode* node);
		void DisplayInOrder(ThreadedBinaryTreeNode* node);
		void DisplayPostOrder(ThreadedBinaryTreeNode* node);
		void InsertNode(ThreadedBinaryTreeNode* parent, ThreadedBinaryTreeNode* node);
		void InsertNode(ThreadedBinaryTreeNode* node);
		void Free(ThreadedBinaryTreeNode* node);
};
*/
