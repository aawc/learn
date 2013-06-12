#include <iostream>
#include "../include/IntBinaryTreeNodeContent.h"
using namespace std;

IntBinaryTreeNodeContent::IntBinaryTreeNodeContent(int info) : info(info), count(1)
{
	if (MostFrequentItem == NULL)
	{
		MostFrequentItem = this;
	}
}

void IntBinaryTreeNodeContent::Display()
{
	cout << "{Info: " << this->info << "; Count: " << this->count << "}";
}

bool IntBinaryTreeNodeContent::operator<(const IBinaryTreeNodeContent& other)
{
	const IntBinaryTreeNodeContent& otherIntContent = static_cast<const IntBinaryTreeNodeContent&>(other);
	return this->info < otherIntContent.info;
}

bool IntBinaryTreeNodeContent::operator==(const IBinaryTreeNodeContent& other)
{
	const IntBinaryTreeNodeContent& otherIntContent = static_cast<const IntBinaryTreeNodeContent&>(other);
	return this->info == otherIntContent.info;
}

bool IntBinaryTreeNodeContent::operator>(const IBinaryTreeNodeContent& other)
{
	const IntBinaryTreeNodeContent& otherIntContent = static_cast<const IntBinaryTreeNodeContent&>(other);
	return !(*this < otherIntContent);
}

void IntBinaryTreeNodeContent::nodeAlreadyPresentAction(void)
{
	this->count++;
	if (MostFrequentItem->count < this->count)
	{
		MostFrequentItem = this;
	}
}

IBinaryTreeNodeContent* IntBinaryTreeNodeContent::CreateIntBinaryTreeNodeContent()
{
	return new IntBinaryTreeNodeContent(rand());
}

IntBinaryTreeNodeContent* IntBinaryTreeNodeContent::MostFrequentItem = NULL;