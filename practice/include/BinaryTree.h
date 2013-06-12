#ifndef _BinaryTree_H
#define _BinaryTree_H

#include "BinaryTreeNode.h"
#include <vector>
using namespace std;

class BinaryTree
{
	protected:
		BinaryTreeNode* root;
		static bool initialized;
		unsigned maxElements;
		unsigned numberOfElements;
		vector<IBinaryTreeNodeContent*> preOrder;
		vector<IBinaryTreeNodeContent*> inOrder;
		vector<IBinaryTreeNodeContent*> postOrder;
		vector<IBinaryTreeNodeContent*> rebuiltPreOrder;
		vector<IBinaryTreeNodeContent*> rebuiltInOrder;
		vector<IBinaryTreeNodeContent*> rebuiltPostOrder;

	public:
		BinaryTree(unsigned, IBinaryTreeNodeContent* (*generator)());
		BinaryTree(const BinaryTree& b);
		BinaryTree& operator=(const BinaryTree& b);

		void GeneratePreOrder(BinaryTreeNode* node);
		void GenerateInOrder(BinaryTreeNode* node);
		void GeneratePostOrder(BinaryTreeNode* node);

		void RebuildPreOrder(unsigned startPreOrder, unsigned endPreOrder, unsigned startInOrder, unsigned endInOrder, unsigned startPostOrder, unsigned endPostOrder);
		void RebuildInOrder(unsigned startPreOrder, unsigned endPreOrder, unsigned startInOrder, unsigned endInOrder, unsigned startPostOrder, unsigned endPostOrder);
		void RebuildPostOrder(unsigned startPreOrder, unsigned endPreOrder, unsigned startInOrder, unsigned endInOrder, unsigned startPostOrder, unsigned endPostOrder);

		virtual ~BinaryTree(void);

	protected:
		static void Init(void);
		void Build(IBinaryTreeNodeContent* (*generator)());
		void Display(void);
		BinaryTreeNode* FindPreOrderParent(IBinaryTreeNodeContent* info, BinaryTreeNode* node);
		void DisplayPreOrder(BinaryTreeNode* node);
		void DisplayInOrder(BinaryTreeNode* node);
		void DisplayPostOrder(BinaryTreeNode* node);
		bool InsertNode(BinaryTreeNode* parent, BinaryTreeNode* node);
		bool InsertNode(BinaryTreeNode* node);
		void Free(BinaryTreeNode* node);
		void GeneratePreOrder(BinaryTreeNode* node, unsigned& index);
		void GenerateInOrder(BinaryTreeNode* node, unsigned& index);
		void GeneratePostOrder(BinaryTreeNode* node, unsigned& index);
};

#endif //_BinaryTree_H