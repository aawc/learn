/*
 * The following iterative sequence is defined for the set of positive integers:
 	n -> n/2 (n is even)
	n -> 3n + 1 (n is odd)
 * Using the rule above and starting with 13, we generate the following sequence: 13  40  20  10  5  16  8  4  2  1
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
 * Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 * Which starting number, under one million, produces the longest chain?
 */

#include "../include/Problem15.h"
#include <iostream>
using namespace std;

Problem15::Problem15(unsigned numBoxes) : numBoxes(numBoxes)
{
	this->solution = new long long* [numBoxes+1];
	for (unsigned i = 0; i <= numBoxes; i++)
	{
		this->solution[i] = new long long [numBoxes+1];
	}

	for (unsigned i = 0; i <= numBoxes; i++)
	{
		for (unsigned j = 0; j <= numBoxes; j++)
		{
			this->solution[i][j] = 0;
		}
	}
}

Problem15::~Problem15()
{
}

Problem15::Problem15(const Problem15& other)
{
	this->numBoxes = other.numBoxes;
	this->solution = other.solution;
}

Problem15& Problem15::operator=(const Problem15& other)
{
	if (this == &other) return *this; // handle self assignment
	this->numBoxes = other.numBoxes;
	this->solution = other.solution;
	return *this;
}

long long Problem15::getLatticePaths()
{
	return this->getLatticePaths(0, 0);
}

long long Problem15::getLatticePaths(unsigned x, unsigned y)
{
	long long priorSolution = this->solution[x][y];
	if (priorSolution != 0)
	{
		return priorSolution;
	}

	//cout << "(" << x << ", " << y << ")" << endl;
	bool reachedBottom = (x == this->numBoxes);
	bool reachedRight = (y == this->numBoxes);
	if (reachedBottom && reachedRight)
	{
		// We've reached!
		return 1;
	}

	long long bottom = 0;
	if (!reachedBottom)
	{
		bottom = this->getLatticePaths(x+1, y);
	}
	long long right = 0;
	if (!reachedRight)
	{
		right = this->getLatticePaths(x, y+1);
	}

	this->solution[x][y] = (bottom + right);
	return this->solution[x][y];
}
