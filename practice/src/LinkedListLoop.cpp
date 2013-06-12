#include <iostream>
#include <cstdlib>
#include <vector>
#include "../include/LinkedListLoop.h"
using namespace std;

LinkedListLoop::LinkedListLoop(const unsigned maxElements)
{
	this->list = new LinkedList(maxElements);
	if (!this->list->LoopExpectationMatches())
	{
		cout << "We got a problem!" << endl;
	}
	else
	{
		cout << "All's well!" << endl;
	}
}

LinkedListLoop::~LinkedListLoop(void)
{
	delete this->list;
	this->list = NULL;
}