#ifndef _IntBinaryTreeNodeContent_H
#define _IntBinaryTreeNodeContent_H

#include "IBinaryTreeNodeContent.h"

class IntBinaryTreeNodeContent : public IBinaryTreeNodeContent
{
private:
	int info;
	int count;
	IntBinaryTreeNodeContent(int);
	static IntBinaryTreeNodeContent* MostFrequentItem;

public:
	static IBinaryTreeNodeContent* CreateIntBinaryTreeNodeContent();

	void Display(void);

	bool operator< (const IBinaryTreeNodeContent& other);
	bool operator== (const IBinaryTreeNodeContent& other);
	bool operator> (const IBinaryTreeNodeContent& other);

	void nodeAlreadyPresentAction(void);
};

#endif //_IntBinaryTreeNodeContent_H