/*
 * A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
 * If all of the permutations are listed numerically or alphabetically, we call it lexicographic order.
 * The lexicographic permutations of 0, 1 and 2 are: 012 021 102 120 201 210
 *
 * What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 */

#include "../include/Problem24.h"
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

Problem24::Problem24(std::vector<unsigned> &input) : input(input), currentCount(0)
{
}

Problem24::~Problem24()
{
}

Problem24::Problem24(const Problem24& other)
{
	this->input = other.input;
	this->currentCount = 0;
}

Problem24& Problem24::operator=(const Problem24& other)
{
	if (this == &other) return *this; // handle self assignment
	this->input = other.input;
	return *this;
}

std::vector<unsigned> Problem24::getPermutationNumber(unsigned limit)
{
	this->answer.clear();
	this->currentCount = 0;
	std::vector<unsigned> current (this->input.size(), -1);
	this->getPermutationsAtLevel(0, current, limit);
	return this->answer;
}

void Problem24::getPermutationsAtLevel(unsigned level, std::vector<unsigned>current, unsigned limit)
{
	if (level == this->input.size())
	{
		this->currentCount++;
		if (this->currentCount == limit)
		{
			this->answer = current;
		}
		return;
	}

	for (unsigned i = 0; i < this->input.size(); i++)
	{
		std::vector<unsigned>::iterator it = std::find(current.begin(), current.end(), this->input[i]);
		if (it == current.end())
		{
			unsigned a = this->input[i];
			// Not present in the array already.
			current[level] = a;
			this->getPermutationsAtLevel(level+1, current, limit);

			if (this->answer.size() != 0)
			{
				return;
			}
		}
	}
}
