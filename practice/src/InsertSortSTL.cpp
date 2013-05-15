#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
#include "../include/InsertSortSTL.h"

void InsertSortSTL::SortRecursively (std::vector<int>::iterator current)
{
	std::vector<int>::iterator begin = this->numbers.begin();
	if (current == begin)
	{
		return;
	}

	this->SortRecursively(current - 1);

	int key = *current;
	std::vector<int>::iterator j = current - 1;
	while (j >= begin && *j > key)
	{
		*(j+1) = *j;
		j--;
	}
	*(j+1) = key;
}

void InsertSortSTL::Sort (void)
{
	std::vector<int>::iterator i;
	for (i = this->numbers.begin(); i != this->numbers.end(); i++)
	{
		int key = *i;
		std::vector<int>::iterator j = i-1;
		while (j >= this->numbers.begin() && *j > key)
		{
			*(j+1) = *j;
			j--;
		}
		*(j+1) = key;

		std::cout << "After iteration " << (i - this->numbers.begin() + 1) << ":" << std::endl;
		this->Display();
	}
}

void InsertSortSTL::Display (void)
{
	this->Display("");
}

void InsertSortSTL::Display (std::string header)
{
	if (header != "")
	{
		std::cout << header << std::endl;
	}
	for (unsigned i = 0; i < this->numbers.size(); i++)
	{
		std::cout << this->numbers[i] << std::endl;
	}
	std::cout << std::endl;
}

InsertSortSTL::InsertSortSTL(int n)
{
	if (n <= 0)
	{
		return;
	}

	/* initialize random seed: */
	srand((unsigned)time(NULL));

	for (int i = 0; i < n; i++)
	{
		this->numbers.push_back(rand());
	}

	this->Display("Before:");
	this->SortRecursively(this->numbers.end() - 1);
	//this->Sort();
	this->Display("After:");
}