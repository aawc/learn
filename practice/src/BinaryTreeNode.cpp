#include <cstdlib>
#include "../include/BinaryTreeNode.h"
using namespace std;

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(void) : left(NULL), right(NULL)
{
}

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(const BinaryTreeNode<T>& b) : info(b.info), left(b.left), right(b.right)
{
}

template <typename T>
BinaryTreeNode<T>& BinaryTreeNode<T>::operator=(const BinaryTreeNode<T>& b)
{
	if (this == &b) return *this; // handle self assignment
	this->info = b.info;
	this->left = b.left;
	this->right = b.right;
	return *this;
}

template <typename T>
BinaryTreeNode<T>::~BinaryTreeNode(void)
{
}

template <typename T>
T BinaryTreeNode<T>::getInfo()
{
	return this->info;
}

template <typename T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getLeft()
{
	return this->left;
}

template <typename T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getRight()
{
	return this->right;
}

template <typename T>
void BinaryTreeNode<T>::setInfo(T value)
{
	this->info = value;
}

template <typename T>
void BinaryTreeNode<T>::setLeft(BinaryTreeNode<T>* value)
{
	this->left = value;
}

template <typename T>
void BinaryTreeNode<T>::setRight(BinaryTreeNode<T>* value)
{
	this->right = value;
}
