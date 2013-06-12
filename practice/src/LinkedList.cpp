#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
#include "../include/LinkedList.h"
using namespace std;

LinkedList::LinkedList (const unsigned maxElements)
{
	this->construct(maxElements, (rand() % 2 == 1));
}

LinkedList::LinkedList (const unsigned maxElements, bool isCircular)
{
	this->construct(maxElements, isCircular);
}

void LinkedList::construct (const unsigned maxElements, bool isCircular)
{
	this->root = NULL; this->last = NULL;
	this->isCircular = isCircular;

	if (!initialized)
	{
		srand((unsigned)time(NULL));
		initialized = true;
	}

	int numberOfElements = rand() % maxElements + 1;
	cout << "Number of elements: " << numberOfElements << endl;
	for (int i = 0; i < numberOfElements; i++)
	{
		int info = rand();
		LinkedListNode* node = new LinkedListNode();
		if (node == NULL)
		{
			cout << "Memory allocation failed!" << endl;
			this->Free();
			return;
		}
		node->info = info;
		node->next = NULL;

		if (this->last == NULL)
		{
			this->root = this->last = node;
		}
		else
		{
			this->last->next = node;
		}

		this->last = node;

		cout << "Added: " << info << endl;
	}

	if (this->isCircular)
	{
		this->last->next = this->root;
		cout << endl << "The list is circular!" << endl;
	}

	this->Display();
}

LinkedList::~LinkedList (void)
{
	this->Free();
}

void LinkedList::Display (void)
{
	LinkedListNode* ptr = this->root;
	cout << endl << "The list is:" << endl;
	bool rootShown = false;
	while ((ptr != NULL && ptr != this->root) || (!rootShown))
	{
		rootShown = true;
		cout << ptr->info << endl;
		ptr = ptr->next;
	}
	cout << endl;
}

bool LinkedList::LoopExpectationMatches (void)
{
	bool loopDetected = this->HasLoop();
	if (loopDetected)
	{
		cout << "Loop detected!" << endl;
	}

	return this->isCircular == loopDetected;
}

void LinkedList::Free (void)
{
	if (this->last == NULL)
	{
		return;
	}
	this->last->next = NULL;

	cout << endl << "Clearing list:" << endl;
	LinkedListNode* ptr = this->root;
	while (ptr != NULL)
	{
		this->root = ptr->next;

		cout << "Deleting: " << ptr->info << endl;
		delete ptr;
		ptr = this->root;
	}
}

bool LinkedList::HasLoop (void)
{
	if (this->root == NULL)
	{
		return false;
	}

	LinkedListNode* ptr1 = this->root, *ptr2 = this->root->next;
	while (ptr1 != NULL && ptr2 != NULL && ptr2->next != NULL)
	{
		if (ptr1 == ptr2)
		{
			return true;
		}

		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
	}
	return false;
}

LinkedListNode* LinkedList::FindFromBack(unsigned numberOfElementToFindFromBack)
{
	if (this->root == NULL)
	{
		return NULL;
	}

	LinkedListNode* nodeAhead = this->root;
	unsigned i = 0;
	while (i < numberOfElementToFindFromBack)
	{
		if (nodeAhead->next == NULL)
		{
			return NULL;
		}

		nodeAhead = nodeAhead->next;
		i++;
	}

	LinkedListNode* nodeBehind = this->root;
	while (nodeAhead->next != NULL)
	{
		nodeBehind = nodeBehind->next;
		nodeAhead = nodeAhead->next;
	}
	return nodeBehind;;
}

bool LinkedList::initialized;