/*
 */

#include "../include/Problem67.h"
#include <iostream>
using namespace std;

Problem67::Problem67(unsigned numRows, std::string inFile) : numRows(numRows)
{
	unsigned totalPositions = numRows*(numRows+1)/2;
	fin.open(inFile.c_str(), ios::in);
	unsigned value;
	for (unsigned i = 0; i < totalPositions; i++)
	{
		fin >> value;
		this->input.push_back(value);
	}
	this->solution.insert(this->solution.begin(), totalPositions, 0);
}

Problem67::~Problem67()
{
}

Problem67::Problem67(const Problem67& other)
{
	this->numRows = other.numRows;
	this->input = other.input;
	this->solution = other.solution;
}

Problem67& Problem67::operator=(const Problem67& other)
{
	if (this == &other) return *this; // handle self assignment
	this->numRows = other.numRows;
	this->input = other.input;
	this->solution = other.solution;
	return *this;
}

unsigned Problem67::getLargestSum()
{
	return this->getLargestSum(0, 0);
}

unsigned Problem67::getLargestSum(unsigned x, unsigned y)
{
	unsigned priorSolution = this->get(this->solution, x, y);
	if (priorSolution > 0)
	{
		return priorSolution;
	}

	unsigned thisCellValue = this->get(this->input, x, y);
	unsigned leftChildTree = 0, rightChildTree = 0;
	if ((x+1) < this->numRows)
	{
		leftChildTree = this->getLargestSum(x+1, y);
		if ((y+1) < this->numRows)
		{
			rightChildTree = this->getLargestSum(x+1, y+1);
		}
	}

	unsigned finalValue = thisCellValue + ((leftChildTree > rightChildTree) ? leftChildTree : rightChildTree);
	this->set(this->solution, x, y, finalValue);

	return finalValue;
}

unsigned Problem67::get(std::vector<unsigned> array, unsigned x, unsigned y)
{
	unsigned index = x*(x+1)/2 + y;
	return array[index];
}

void Problem67::set(std::vector<unsigned> array, unsigned x, unsigned y, unsigned value)
{
	unsigned index = x*(x+1)/2 + y;
	array[index] = value;
}
