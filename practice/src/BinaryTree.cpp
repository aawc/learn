#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include "../include/BinaryTreeNode.h"
#include "../include/BinaryTree.h"
#include "../src/BinaryTreeNode.cpp"
using namespace std;

template <typename T>
BinaryTree<T>::BinaryTree(unsigned maxElements) : root(NULL), maxElements(maxElements)
{
	Init();
	this->Build();
	this->Display();
}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& b) : root(b.root)
{
	Init();
}

template <typename T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& b)
{
	if (this == &b) return *this; // handle self assignment
	this->root = b.root;
	return *this;
}

template <typename T>
BinaryTree<T>::~BinaryTree(void)
{
	this->Free(this->root);
}

template <typename T>
void BinaryTree<T>::Init(void)
{
	if (!initialized)
	{
		srand((unsigned)time(NULL));
		initialized = true;
	}
}

template <typename T>
void BinaryTree<T>::Build(void)
{
	this->numberOfElements = rand() % this->maxElements + 1;
	cout << "Number of elements: " << this->numberOfElements << endl;
	for (int i = 0; i < this->numberOfElements; i++)
	{
		BinaryTreeNode<T>* node = new BinaryTreeNode<T>();
		if (node == NULL)
		{
			cout << "Memory allocation failed!" << endl;
			this->Free(this->root);
			return;
		}
		node->setInfo(rand());
		node->setLeft(NULL);
		node->setRight(NULL);

		this->InsertNode(node);
	}
	this->Display();

	this->GeneratePreOrder(this->root);
	this->GenerateInOrder(this->root);
	this->GeneratePostOrder(this->root);

	for (unsigned i = 0; i < this->numberOfElements; i++)
	{
		this->rebuiltPreOrder.push_back(-1);
		this->rebuiltInOrder.push_back(-1);
		this->rebuiltPostOrder.push_back(-1);
	}

	this->RebuildPreOrder(0, this->numberOfElements - 1, 0, this->numberOfElements - 1, 0, this->numberOfElements - 1);
	//this->RebuildInOrder(0, this->numberOfElements - 1, 0, this->numberOfElements - 1, 0, this->numberOfElements - 1);
	this->RebuildPostOrder(0, this->numberOfElements - 1, 0, this->numberOfElements - 1, 0, this->numberOfElements - 1);

	for (unsigned i = 0; i < this->numberOfElements; i++)
	{
		assert(this->rebuiltPreOrder[i] == this->preOrder[i]);
		//assert(this->rebuiltInOrder[i] == this->inOrder[i]);
		assert(this->rebuiltPostOrder[i] == this->postOrder[i]);
	}
}

template <typename T>
void BinaryTree<T>::RebuildPreOrder(unsigned startPreOrder, unsigned endPreOrder, unsigned startInOrder, unsigned endInOrder, unsigned startPostOrder, unsigned endPostOrder)
{
	if (endPreOrder < startPreOrder || endPreOrder >= this->numberOfElements)
	{
		return;
	}
	T lastPostValue = this->postOrder[endPostOrder];

	unsigned indexOfLastPostInInOrder = std::find(this->inOrder.begin(), this->inOrder.end(), lastPostValue) - this->inOrder.begin();
	int leftSpan = (indexOfLastPostInInOrder - 1) - startInOrder;
	int rightSpan = endInOrder - (indexOfLastPostInInOrder + 1);

	this->rebuiltPreOrder[startPreOrder] = lastPostValue;
	this->RebuildPreOrder(startPreOrder + 1, startPreOrder + 1 + leftSpan, startInOrder, startInOrder + leftSpan, startPostOrder, startPostOrder + leftSpan);
	this->RebuildPreOrder(endPreOrder - rightSpan, endPreOrder, endInOrder - rightSpan, endInOrder, (endPostOrder - 1) - rightSpan, endPostOrder - 1);
}

template <typename T>
void BinaryTree<T>::RebuildInOrder(unsigned startPreOrder, unsigned endPreOrder, unsigned startInOrder, unsigned endInOrder, unsigned startPostOrder, unsigned endPostOrder)
{
	if (endInOrder < startInOrder || endInOrder >= this->numberOfElements)
	{
		return;
	}
	T lastPostValue = this->postOrder[endPostOrder];
	assert ((startPreOrder+1) < this->numberOfElements);
	assert (endPostOrder > 0);

	T secondInPreOrder = this->preOrder[startPreOrder + 1];
	T secondLastInPostOrder = this->postOrder[endPostOrder - 1];
	unsigned indexOfSecondPreOrderInPostOrder = std::find(this->postOrder.begin(), this->postOrder.end(), secondInPreOrder) - this->postOrder.begin();
	unsigned indexOfSecondLastPostOrderInPreOrder = std::find(this->preOrder.begin(), this->preOrder.end(), secondLastInPostOrder) - this->preOrder.begin();

	int leftSpan  = indexOfSecondPreOrderInPostOrder - startPostOrder;
	int rightSpan = endPreOrder - indexOfSecondLastPostOrderInPreOrder;

	this->RebuildInOrder(startPreOrder + 1, startPreOrder + 1 + leftSpan, startInOrder, startInOrder + leftSpan, startPostOrder, startPostOrder + leftSpan);
	this->rebuiltInOrder[startInOrder + leftSpan + 1] = lastPostValue;
	this->RebuildInOrder(endPreOrder - rightSpan, endPreOrder, endInOrder - rightSpan, endInOrder, endPostOrder - 1 - rightSpan, endPostOrder - 1);
}

template <typename T>
void BinaryTree<T>::RebuildPostOrder(unsigned startPreOrder, unsigned endPreOrder, unsigned startInOrder, unsigned endInOrder, unsigned startPostOrder, unsigned endPostOrder)
{
	if (endPostOrder < startPostOrder || endPostOrder >= this->numberOfElements)
	{
		return;
	}
	T firstPreValue = this->preOrder[startPreOrder];

	unsigned indexOfFirstPreInInOrder = std::find(this->inOrder.begin(), this->inOrder.end(), firstPreValue) - this->inOrder.begin();
	int leftSpan = (indexOfFirstPreInInOrder - 1) - startInOrder;
	int rightSpan = endInOrder - (indexOfFirstPreInInOrder + 1);

	this->rebuiltPostOrder[endPostOrder] = firstPreValue;
	this->RebuildPostOrder(startPreOrder + 1, startPreOrder + 1 + leftSpan, startInOrder, startInOrder + leftSpan, startPostOrder, startPostOrder + leftSpan);
	this->RebuildPostOrder(endPreOrder - rightSpan, endPreOrder, endInOrder - rightSpan, endInOrder, (endPostOrder - 1) - rightSpan, endPostOrder - 1);
}

template <typename T>
void BinaryTree<T>::Display(void)
{
	this->DisplayPreOrder(this->root);
	this->DisplayInOrder(this->root);
	this->DisplayPostOrder(this->root);
}

template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::FindPreOrderParent(T info, BinaryTreeNode<T>* node)
{
	if (node == NULL)
	{
		return NULL;
	}

	BinaryTree<T>* next = NULL;
	if (node->getInfo() < info)
	{
		next = this->FindPreOrderParent(info, node->getRight());
	}
	else if (node->getInfo() > info)
	{
		next = this->FindPreOrderParent(info, node->getLeft());
	}

	return (next == NULL) ? node : next;
}

template <typename T>
void BinaryTree<T>::GeneratePreOrder(BinaryTreeNode<T>* node)
{
	unsigned index = 0;

	this->GeneratePreOrder(node, index);
}

template <typename T>
void BinaryTree<T>::GeneratePreOrder(BinaryTreeNode<T>* node, unsigned& index)
{
	if (node == NULL)
	{
		return;
	}
	for (unsigned i = this->preOrder.size(); i <= index; i++)
	{
		this->preOrder.push_back(-1);
	}
	int value = node->getInfo();;
	this->preOrder[index] = value;
	index += 1;
	this->GeneratePreOrder(node->getLeft(), index);
	this->GeneratePreOrder(node->getRight(), index);
}

template <typename T>
void BinaryTree<T>::GenerateInOrder(BinaryTreeNode<T>* node)
{
	unsigned index = 0;

	this->GenerateInOrder(node, index);
}

template <typename T>
void BinaryTree<T>::GenerateInOrder(BinaryTreeNode<T>* node, unsigned& index)
{
	if (node == NULL)
	{
		return;
	}

	this->GenerateInOrder(node->getLeft(), index);

	for (unsigned i = this->inOrder.size(); i <= index; i++)
	{
		this->inOrder.push_back(-1);
	}
	int value = node->getInfo();;
	this->inOrder[index] = value;
	index += 1;

	this->GenerateInOrder(node->getRight(), index);
}

template <typename T>
void BinaryTree<T>::GeneratePostOrder(BinaryTreeNode<T>* node)
{
	unsigned index = 0;

	this->GeneratePostOrder(node, index);
}

template <typename T>
void BinaryTree<T>::GeneratePostOrder(BinaryTreeNode<T>* node, unsigned& index)
{
	if (node == NULL)
	{
		return;
	}

	this->GeneratePostOrder(node->getLeft(), index);
	this->GeneratePostOrder(node->getRight(), index);

	for (unsigned i = this->postOrder.size(); i <= index; i++)
	{
		this->postOrder.push_back(-1);
	}
	int value = node->getInfo();;
	this->postOrder[index] = value;
	index += 1;
}

template <typename T>
void BinaryTree<T>::DisplayPreOrder(BinaryTreeNode<T>* node)
{
	if (node == this->root)
	{
		cout << "DisplayPreOrder:" << endl;
	}
	if (node == NULL)
	{
		return;
	}
	cout << node->getInfo() << endl;
	this->DisplayPreOrder(node->getLeft());
	this->DisplayPreOrder(node->getRight());
}

template <typename T>
void BinaryTree<T>::DisplayInOrder(BinaryTreeNode<T>* node)
{
	if (node == this->root)
	{
		cout << "DisplayInOrder:" << endl;
	}
	if (node == NULL)
	{
		return;
	}
	this->DisplayInOrder(node->getLeft());
	cout << node->getInfo() << endl;
	this->DisplayInOrder(node->getRight());
}

template <typename T>
void BinaryTree<T>::DisplayPostOrder(BinaryTreeNode<T>* node)
{
	if (node == this->root)
	{
		cout << "DisplayPostOrder:" << endl;
	}
	if (node == NULL)
	{
		return;
	}
	this->DisplayPostOrder(node->getLeft());
	this->DisplayPostOrder(node->getRight());
	cout << node->getInfo() << endl;
}

template <typename T>
void BinaryTree<T>::InsertNode(BinaryTreeNode<T>* parent, BinaryTreeNode<T>* node)
{
	if (node->getInfo() == parent->getInfo())
	{
		cout << "Dropping: " << node->getInfo() << endl;
		return;
	}

	if (node->getInfo() < parent->getInfo())
	{
		if (parent->getLeft() == NULL)
		{
			parent->setLeft(node);
			cout << "Added: " << node->getInfo() << " to the left of: " << parent->getInfo() <<endl;
		}
		else
		{
		this->InsertNode(parent->getLeft(), node);
		}
	}
	else
	{
		if (parent->getRight() == NULL)
		{
			parent->setRight(node);
			cout << "Added: " << node->getInfo() << " to the right of: " << parent->getInfo() <<endl;
		}
		else
		{
		this->InsertNode(parent->getRight(), node);
		}
	}
}

template <typename T>
void BinaryTree<T>::InsertNode(BinaryTreeNode<T>* node)
{
	if (this->root == NULL)
	{
		this->root = node;
		cout << "Added as root: " << node->getInfo() << endl;
		return;
	}
	this->InsertNode(this->root, node);
}

template <typename T>
void BinaryTree<T>::Free(BinaryTreeNode<T>* node)
{
	if (node != NULL)
	{
		this->Free(node->getLeft());
		cout << "Deleting: " << node->getInfo() << endl;
		this->Free(node->getRight());

		delete node;
		node = NULL;
	}
}

template <typename T>
bool BinaryTree<T>::initialized;