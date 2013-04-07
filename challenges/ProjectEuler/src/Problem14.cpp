/*
 * The following iterative sequence is defined for the set of positive integers:
 	n -> n/2 (n is even)
	n -> 3n + 1 (n is odd)
 * Using the rule above and starting with 13, we generate the following sequence: 13  40  20  10  5  16  8  4  2  1
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
 * Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 * Which starting number, under one million, produces the longest chain?
 */

#include "../include/Problem14.h"
#include <iostream>
using namespace std;

Problem14::Problem14(long long numLimit) : numLimit(numLimit)
{
	int vectorLength = 4*this->numLimit;
	std::vector<long long>::iterator it = this->solvedLength.begin();
	this->solvedLength.insert(it, vectorLength, -1);
}

Problem14::~Problem14()
{
}

Problem14::Problem14(const Problem14& other)
{
	this->numLimit = other.numLimit;
}

Problem14& Problem14::operator=(const Problem14& other)
{
	if (this == &other) return *this; // handle self assignment
	this->numLimit = other.numLimit;
	return *this;
}

long long Problem14::get(long long index)
{
	if (this->solvedLength.size() > index)
	{
		return this->solvedLength[index];
	}
	return -1;
}

void Problem14::set(long long index, long long value)
{
	if (this->solvedLength.size() > index)
	{
		this->solvedLength[index] = value;
	}
}

long long Problem14::getChainLengthForSeed(long long n)
{
	long long stored = this->get(n);
	if (stored != -1)
	{
		//cout << "stored[" << n << "] = " << stored << endl;
		return stored;
	}

	long long thisLength;
	if (n == 1)
	{
		thisLength = 1;
	}
	else
	{
		long long nextTerm = (n%2 == 0) ? (n/2) : (3*n + 1);
		thisLength = (1 + this->getChainLengthForSeed(nextTerm));
	}

	this->set(n, thisLength);
	return thisLength;
}

long long Problem14::getLongestChainSeed()
{
	long long maxLength = 0;
	for (long long i = 1; i < this->numLimit; i++)
	{
		long long thisLength = this->getChainLengthForSeed(i);
		if (thisLength > maxLength)
		{
			maxLength = thisLength;
			cout << "i: " << i << "; maxLength: " << maxLength << endl;
		}
	}

	return maxLength;
}
