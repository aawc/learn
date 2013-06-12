#ifndef _BinaryTreeNode_H
#define _BinaryTreeNode_H

class IBinaryTreeNodeContent;

class BinaryTreeNode
{
	private:
		IBinaryTreeNodeContent* info;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

	public:
		BinaryTreeNode(void);
		virtual ~BinaryTreeNode();
		BinaryTreeNode(const BinaryTreeNode& b);
		BinaryTreeNode& operator=(const BinaryTreeNode& b);

		IBinaryTreeNodeContent& getInfo();
		BinaryTreeNode* getLeft();
		BinaryTreeNode* getRight();
		void setInfo(IBinaryTreeNodeContent*);
		void setLeft(BinaryTreeNode*);
		void setRight(BinaryTreeNode*);
};

#endif //_BinaryTreeNode_H