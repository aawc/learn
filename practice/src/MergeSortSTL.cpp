#include <iostream>
#include <cstdlib>
#include <time.h>
#include "../include/MergeSortSTL.h"
using namespace std;

void MergeSortSTL::Sort(vector<int>::iterator start, vector<int>::iterator end)
{
	if (start >= end)
	{
		return;
	}

	const vector<int>::iterator begin = this->A.begin();
	int startIndex = start - begin;
	int endIndex = end - begin;
	int midIndex = (startIndex + endIndex) / 2;
	vector<int>::iterator mid = begin + midIndex;

	this->Sort(start, mid);
	this->Sort(mid+1, end);

	this->Merge(start, mid, end);
}

void MergeSortSTL::Merge(vector<int>::iterator start, vector<int>::iterator mid, vector<int>::iterator end)
{
	vector<int> B;
	vector<int>::iterator i = start, j = mid+1, k;
	while (i <= mid && j <= end)
	{
		if (*i <= *j)
		{
			B.push_back(*i);
			i++;
		}
		else
		{
			B.push_back(*j);
			j++;
		}
	}
	while (i <= mid)
	{
		B.push_back(*i);
		i++;
	}
	while (j <= end)
	{
		B.push_back(*j);
		j++;
	}

	i = start; k = B.begin();
	while (i <= end)
	{
		*i = *k;
		i++; k++;
	}
}

void MergeSortSTL::Display(void)
{
	this->Display("");
}

void MergeSortSTL::Display(std::string header)
{
	if (header != "")
	{
		std::cout << header << std::endl;
	}
	for (vector<int>::iterator i = this->A.begin(); i != this->A.end(); i++)
	{
		std::cout << *i << std::endl;
	}
	std::cout << std::endl;
}

MergeSortSTL::MergeSortSTL(int n)
{
	if (n <= 0)
	{
		return;
	}

	/* initialize random seed: */
	srand((unsigned)time(NULL));

	for (int i = 0; i < n; i++)
	{
		this->A.push_back(rand());
	}

	this->Display("Before:");
	this->Sort(this->A.begin(), this->A.end()-1);
	this->Display("After:");
}
