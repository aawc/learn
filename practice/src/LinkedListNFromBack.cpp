#include <iostream>
#include <cstdlib>
#include <vector>
#include "../include/LinkedListNFromBack.h"
using namespace std;

LinkedListNFromBack::LinkedListNFromBack(const unsigned maxElements)
{
	this->list = new LinkedList(maxElements, false);
	unsigned numberOfElementToFindFromBack = rand() % maxElements;
	LinkedListNode *node = this->list->FindFromBack(numberOfElementToFindFromBack);
}

LinkedListNFromBack::~LinkedListNFromBack(void)
{
	delete this->list;
	this->list = NULL;
}