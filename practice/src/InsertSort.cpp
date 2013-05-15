#include <iostream>
#include <cstdlib>
#include <time.h>
#include "../include/InsertSort.h"

void InsertSort::SortRecursively (int length)
{
	if (length <= 1)
	{
		return;
	}

	this->SortRecursively(length - 1);

	int key = this->A[length - 1];
	int j = length - 2;
	while (j >= 0 && this->A[j] > key)
	{
		this->A[j+1] = this->A[j];
		j--;
	}
	this->A[j+1] = key;
}

void InsertSort::Sort (void)
{
	for (int i = 1; i < this->length; i++)
	{
		int key = this->A[i];
		int j = i-1;
		while (j >= 0 && this->A[j] > key)
		{
			this->A[j+1] = this->A[j];
			j--;
		}
		this->A[j+1] = key;

		std::cout << "After iteration " << i << ":" << std::endl;
		this->Display();
	}
}

void InsertSort::Display (void)
{
	this->Display("");
}

void InsertSort::Display (std::string header)
{
	if (header != "")
	{
		std::cout << header << std::endl;
	}
	for (int i = 0; i < this->length; i++)
	{
		std::cout << this->A[i] << std::endl;
	}
	std::cout << std::endl;
}

InsertSort::InsertSort(int n)
{
	if (n <= 0)
	{
		return;
	}

	/* initialize random seed: */
	srand((unsigned)time(NULL));

	this->length = n;
	this->A = new int [this->length];

	for (int i = 0; i < this->length; i++)
	{
		this->A[i] = rand();
	}

	this->Display("Before:");
	this->SortRecursively(n);
	//this->Sort();
	this->Display("After:");
}