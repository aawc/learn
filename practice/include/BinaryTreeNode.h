#ifndef _BinaryTreeNode_H
#define _BinaryTreeNode_H

template <typename T>
class BinaryTreeNode
{
	private:
		T info;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

	public:
		BinaryTreeNode(void);
		virtual ~BinaryTreeNode();
		BinaryTreeNode(const BinaryTreeNode& b);
		BinaryTreeNode& operator=(const BinaryTreeNode& b);

		T getInfo();
		BinaryTreeNode* getLeft();
		BinaryTreeNode* getRight();
		void setInfo(T);
		void setLeft(BinaryTreeNode*);
		void setRight(BinaryTreeNode*);
};

#endif //_BinaryTreeNode_H