#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include "../include/BinaryTreeNode.h"
#include "../include/BinaryTree.h"
#include "../include/IBinaryTreeNodeContent.h"
using namespace std;

BinaryTree::BinaryTree(unsigned maxElements, IBinaryTreeNodeContent* (*generator)()) : root(NULL), maxElements(maxElements)
{
	Init();
	this->Build(generator);
	this->Display();
}

BinaryTree::BinaryTree(const BinaryTree& b) : root(b.root)
{
	Init();
}

BinaryTree& BinaryTree::operator=(const BinaryTree& b)
{
	if (this == &b) return *this; // handle self assignment
	this->root = b.root;
	return *this;
}

BinaryTree::~BinaryTree(void)
{
	this->Free(this->root);
}

void BinaryTree::Init(void)
{
	if (!initialized)
	{
		srand((unsigned)time(NULL));
		initialized = true;
	}
}

void BinaryTree::Build(IBinaryTreeNodeContent* (*generator)())
{
	unsigned failedInsertions = 0;
	this->numberOfElements = rand() % this->maxElements + 1;
	cout << "Number of elements: " << this->numberOfElements << endl;
	for (unsigned i = 0; i < this->numberOfElements; i++)
	{
		BinaryTreeNode* node = new BinaryTreeNode();
		if (node == NULL)
		{
			cout << "Memory allocation failed!" << endl;
			this->Free(this->root);
			return;
		}
		node->setInfo(generator());
		node->setLeft(NULL);
		node->setRight(NULL);

		if (!this->InsertNode(node))
		{
			failedInsertions++;
		}
	}

	this->numberOfElements -= failedInsertions;
	this->Display();

	this->GeneratePreOrder(this->root);
	this->GenerateInOrder(this->root);
	this->GeneratePostOrder(this->root);

	for (unsigned i = 0; i < this->numberOfElements; i++)
	{
		this->rebuiltPreOrder.push_back(NULL);
		this->rebuiltInOrder.push_back(NULL);
		this->rebuiltPostOrder.push_back(NULL);
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

void BinaryTree::RebuildPreOrder(unsigned startPreOrder, unsigned endPreOrder, unsigned startInOrder, unsigned endInOrder, unsigned startPostOrder, unsigned endPostOrder)
{
	if (endPreOrder < startPreOrder || endPreOrder >= this->numberOfElements)
	{
		return;
	}
	IBinaryTreeNodeContent* lastPostValue = this->postOrder[endPostOrder];

	unsigned indexOfLastPostInInOrder = std::find(this->inOrder.begin(), this->inOrder.end(), lastPostValue) - this->inOrder.begin();
	int leftSpan = (indexOfLastPostInInOrder - 1) - startInOrder;
	int rightSpan = endInOrder - (indexOfLastPostInInOrder + 1);

	this->rebuiltPreOrder[startPreOrder] = lastPostValue;
	this->RebuildPreOrder(startPreOrder + 1, startPreOrder + 1 + leftSpan, startInOrder, startInOrder + leftSpan, startPostOrder, startPostOrder + leftSpan);
	this->RebuildPreOrder(endPreOrder - rightSpan, endPreOrder, endInOrder - rightSpan, endInOrder, (endPostOrder - 1) - rightSpan, endPostOrder - 1);
}

void BinaryTree::RebuildInOrder(unsigned startPreOrder, unsigned endPreOrder, unsigned startInOrder, unsigned endInOrder, unsigned startPostOrder, unsigned endPostOrder)
{
	if (endInOrder < startInOrder || endInOrder >= this->numberOfElements)
	{
		return;
	}
	IBinaryTreeNodeContent* lastPostValue = this->postOrder[endPostOrder];
	assert ((startPreOrder+1) < this->numberOfElements);
	assert (endPostOrder > 0);

	IBinaryTreeNodeContent* secondInPreOrder = this->preOrder[startPreOrder + 1];
	IBinaryTreeNodeContent* secondLastInPostOrder = this->postOrder[endPostOrder - 1];
	unsigned indexOfSecondPreOrderInPostOrder = std::find(this->postOrder.begin(), this->postOrder.end(), secondInPreOrder) - this->postOrder.begin();
	unsigned indexOfSecondLastPostOrderInPreOrder = std::find(this->preOrder.begin(), this->preOrder.end(), secondLastInPostOrder) - this->preOrder.begin();

	int leftSpan  = indexOfSecondPreOrderInPostOrder - startPostOrder;
	int rightSpan = endPreOrder - indexOfSecondLastPostOrderInPreOrder;

	this->RebuildInOrder(startPreOrder + 1, startPreOrder + 1 + leftSpan, startInOrder, startInOrder + leftSpan, startPostOrder, startPostOrder + leftSpan);
	this->rebuiltInOrder[startInOrder + leftSpan + 1] = lastPostValue;
	this->RebuildInOrder(endPreOrder - rightSpan, endPreOrder, endInOrder - rightSpan, endInOrder, endPostOrder - 1 - rightSpan, endPostOrder - 1);
}

void BinaryTree::RebuildPostOrder(unsigned startPreOrder, unsigned endPreOrder, unsigned startInOrder, unsigned endInOrder, unsigned startPostOrder, unsigned endPostOrder)
{
	if (endPostOrder < startPostOrder || endPostOrder >= this->numberOfElements)
	{
		return;
	}
	IBinaryTreeNodeContent* firstPreValue = this->preOrder[startPreOrder];

	unsigned indexOfFirstPreInInOrder = std::find(this->inOrder.begin(), this->inOrder.end(), firstPreValue) - this->inOrder.begin();
	int leftSpan = (indexOfFirstPreInInOrder - 1) - startInOrder;
	int rightSpan = endInOrder - (indexOfFirstPreInInOrder + 1);

	this->rebuiltPostOrder[endPostOrder] = firstPreValue;
	this->RebuildPostOrder(startPreOrder + 1, startPreOrder + 1 + leftSpan, startInOrder, startInOrder + leftSpan, startPostOrder, startPostOrder + leftSpan);
	this->RebuildPostOrder(endPreOrder - rightSpan, endPreOrder, endInOrder - rightSpan, endInOrder, (endPostOrder - 1) - rightSpan, endPostOrder - 1);
}

void BinaryTree::Display(void)
{
	this->DisplayPreOrder(this->root);
	this->DisplayInOrder(this->root);
	this->DisplayPostOrder(this->root);
}

BinaryTreeNode* BinaryTree::FindPreOrderParent(IBinaryTreeNodeContent* info, BinaryTreeNode* node)
{
	if (node == NULL)
	{
		return NULL;
	}

	BinaryTreeNode* next = NULL;
	if (node->getInfo() < *info)
	{
		next = this->FindPreOrderParent(info, node->getRight());
	}
	else if (node->getInfo() > *info)
	{
		next = this->FindPreOrderParent(info, node->getLeft());
	}

	return (next == NULL) ? node : next;
}

void BinaryTree::GeneratePreOrder(BinaryTreeNode* node)
{
	unsigned index = 0;

	this->GeneratePreOrder(node, index);
}

void BinaryTree::GeneratePreOrder(BinaryTreeNode* node, unsigned& index)
{
	if (node == NULL)
	{
		return;
	}
	for (unsigned i = this->preOrder.size(); i <= index; i++)
	{
		this->preOrder.push_back(NULL);
	}
	IBinaryTreeNodeContent& value = node->getInfo();
	this->preOrder[index] = &value;
	index += 1;
	this->GeneratePreOrder(node->getLeft(), index);
	this->GeneratePreOrder(node->getRight(), index);
}

void BinaryTree::GenerateInOrder(BinaryTreeNode* node)
{
	unsigned index = 0;

	this->GenerateInOrder(node, index);
}

void BinaryTree::GenerateInOrder(BinaryTreeNode* node, unsigned& index)
{
	if (node == NULL)
	{
		return;
	}

	this->GenerateInOrder(node->getLeft(), index);

	for (unsigned i = this->inOrder.size(); i <= index; i++)
	{
		this->inOrder.push_back(NULL);
	}
	IBinaryTreeNodeContent& value = node->getInfo();
	this->inOrder[index] = &value;
	index += 1;

	this->GenerateInOrder(node->getRight(), index);
}

void BinaryTree::GeneratePostOrder(BinaryTreeNode* node)
{
	unsigned index = 0;

	this->GeneratePostOrder(node, index);
}

void BinaryTree::GeneratePostOrder(BinaryTreeNode* node, unsigned& index)
{
	if (node == NULL)
	{
		return;
	}

	this->GeneratePostOrder(node->getLeft(), index);
	this->GeneratePostOrder(node->getRight(), index);

	for (unsigned i = this->postOrder.size(); i <= index; i++)
	{
		this->postOrder.push_back(NULL);
	}
	IBinaryTreeNodeContent& value = node->getInfo();
	this->postOrder[index] = &value;
	index += 1;
}

void BinaryTree::DisplayPreOrder(BinaryTreeNode* node)
{
	if (node == this->root)
	{
		cout << "DisplayPreOrder:" << endl;
	}
	if (node == NULL)
	{
		return;
	}
	node->getInfo().Display();
	cout << endl;
	this->DisplayPreOrder(node->getLeft());
	this->DisplayPreOrder(node->getRight());
}

void BinaryTree::DisplayInOrder(BinaryTreeNode* node)
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
	node->getInfo().Display();
	cout << endl;
	this->DisplayInOrder(node->getRight());
}

void BinaryTree::DisplayPostOrder(BinaryTreeNode* node)
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
	node->getInfo().Display();
	cout << endl;
}

bool BinaryTree::InsertNode(BinaryTreeNode* parent, BinaryTreeNode* node)
{
	if (node->getInfo() == parent->getInfo())
	{
		parent->getInfo().nodeAlreadyPresentAction();
		cout << "Dropping: "; node->getInfo().Display(); cout << endl;
		return false;
	}

	if (node->getInfo() < parent->getInfo())
	{
		if (parent->getLeft() == NULL)
		{
			parent->setLeft(node);
			cout << "Added: "; node->getInfo().Display(); cout << " to the left of: "; parent->getInfo().Display(); cout <<endl;
		}
		else
		{
			return this->InsertNode(parent->getLeft(), node);
		}
	}
	else
	{
		if (parent->getRight() == NULL)
		{
			parent->setRight(node);
			cout << "Added: "; node->getInfo().Display(); cout << " to the right of: "; parent->getInfo().Display(); cout <<endl;
		}
		else
		{
			return this->InsertNode(parent->getRight(), node);
		}
	}
	return true;
}

bool BinaryTree::InsertNode(BinaryTreeNode* node)
{
	if (this->root == NULL)
	{
		this->root = node;
		cout << "Added as root: "; node->getInfo().Display(); cout << endl;
		return true;
	}
	return this->InsertNode(this->root, node);
}

void BinaryTree::Free(BinaryTreeNode* node)
{
	if (node != NULL)
	{
		this->Free(node->getLeft());
		cout << "Deleting: "; node->getInfo().Display(); cout << endl;
		this->Free(node->getRight());

		delete node;
		node = NULL;
	}
}

bool BinaryTree::initialized;