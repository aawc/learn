#ifndef _IBinaryTreeNodeContent_H
#define _IBinaryTreeNodeContent_H

class IBinaryTreeNodeContent
{
public:
	virtual void Display(void) = 0;
	virtual bool operator< (const IBinaryTreeNodeContent& other) = 0;
	virtual bool operator== (const IBinaryTreeNodeContent& other) = 0;
	virtual bool operator> (const IBinaryTreeNodeContent& other) = 0;
	virtual void nodeAlreadyPresentAction(void) = 0;
};

#endif //_IBinaryTreeNodeContent_H