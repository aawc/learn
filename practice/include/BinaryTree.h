#ifndef _BinaryTree_H
#define _BinaryTree_H

#include "BinaryTreeNode.h"
#include <vector>
using namespace std;

template <typename T>
class BinaryTree
{
	protected:
		BinaryTreeNode<T>* root;
		static bool initialized;
		unsigned maxElements;
		unsigned numberOfElements;
		vector<T> preOrder;
		vector<T> inOrder;
		vector<T> postOrder;
		vector<T> rebuiltPreOrder;
		vector<T> rebuiltInOrder;
		vector<T> rebuiltPostOrder;

	public:
		BinaryTree(unsigned);
		BinaryTree(const BinaryTree& b);
		BinaryTree& operator=(const BinaryTree& b);

		void GeneratePreOrder(BinaryTreeNode<T>* node);
		void GenerateInOrder(BinaryTreeNode<T>* node);
		void GeneratePostOrder(BinaryTreeNode<T>* node);

		void RebuildPreOrder(unsigned startPreOrder, unsigned endPreOrder, unsigned startInOrder, unsigned endInOrder, unsigned startPostOrder, unsigned endPostOrder);
		void RebuildInOrder(unsigned startPreOrder, unsigned endPreOrder, unsigned startInOrder, unsigned endInOrder, unsigned startPostOrder, unsigned endPostOrder);
		void RebuildPostOrder(unsigned startPreOrder, unsigned endPreOrder, unsigned startInOrder, unsigned endInOrder, unsigned startPostOrder, unsigned endPostOrder);

		virtual ~BinaryTree(void);

	protected:
		static void Init(void);
		void Build(void);
		void Display(void);
		BinaryTreeNode<T>* FindPreOrderParent(T info, BinaryTreeNode<T>* node);
		void DisplayPreOrder(BinaryTreeNode<T>* node);
		void DisplayInOrder(BinaryTreeNode<T>* node);
		void DisplayPostOrder(BinaryTreeNode<T>* node);
		void InsertNode(BinaryTreeNode<T>* parent, BinaryTreeNode<T>* node);
		void InsertNode(BinaryTreeNode<T>* node);
		void Free(BinaryTreeNode<T>* node);
		void GeneratePreOrder(BinaryTreeNode<T>* node, unsigned& index);
		void GenerateInOrder(BinaryTreeNode<T>* node, unsigned& index);
		void GeneratePostOrder(BinaryTreeNode<T>* node, unsigned& index);
};

#endif //_BinaryTree_H