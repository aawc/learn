/*
 * By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

	3
	7 4
	2 4 6
	8 5 9 3
 * That is, 3 + 7 + 4 + 9 = 23.
 * Find the maximum total from top to bottom of the triangle below:

75 00 00 00 00 00 00 00 00 00 00 00 00 00 00
95 64 00 00 00 00 00 00 00 00 00 00 00 00 00
17 47 82 00 00 00 00 00 00 00 00 00 00 00 00
18 35 87 10 00 00 00 00 00 00 00 00 00 00 00
20 04 82 47 65 00 00 00 00 00 00 00 00 00 00
19 01 23 75 03 34 00 00 00 00 00 00 00 00 00
88 02 77 73 07 63 67 00 00 00 00 00 00 00 00
99 65 04 28 06 16 70 92 00 00 00 00 00 00 00
41 41 26 56 83 40 80 70 33 00 00 00 00 00 00
41 48 72 33 47 32 37 16 94 29 00 00 00 00 00
53 71 44 65 25 43 91 52 97 51 14 00 00 00 00
70 11 33 28 77 73 17 78 39 68 17 57 00 00 00
91 71 52 38 17 14 91 43 58 50 27 29 48 00 00
63 66 04 68 89 53 67 30 73 16 69 87 40 31 00
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
 */

#include "../include/Problem18.h"
#include <iostream>
using namespace std;

Problem18::Problem18(unsigned numRows) : numRows(numRows)
{
	unsigned totalPositions = numRows*(numRows+1)/2;
	unsigned inputArray[] = {
		75,
		95,64,
		17,47,82,
		18,35,87,10,
		20,04,82,47,65,
		19,01,23,75,03,34,
		88,02,77,73,07,63,67,
		99,65,04,28,06,16,70,92,
		41,41,26,56,83,40,80,70,33,
		41,48,72,33,47,32,37,16,94,29,
		53,71,44,65,25,43,91,52,97,51,14,
		70,11,33,28,77,73,17,78,39,68,17,57,
		91,71,52,38,17,14,91,43,58,50,27,29,48,
		63,66,04,68,89,53,67,30,73,16,69,87,40,31,
		04,62,98,27,23, 9,70,98,73,93,38,53,60,04,23
	};
	this->input.insert(this->input.begin(), inputArray, inputArray + totalPositions);

	std::vector<unsigned>::iterator it = this->solution.begin();
	this->solution.insert(it, totalPositions, 0);
}

Problem18::~Problem18()
{
}

Problem18::Problem18(const Problem18& other)
{
	this->numRows = other.numRows;
	this->input = other.input;
	this->solution = other.solution;
}

Problem18& Problem18::operator=(const Problem18& other)
{
	if (this == &other) return *this; // handle self assignment
	this->numRows = other.numRows;
	this->input = other.input;
	this->solution = other.solution;
	return *this;
}

unsigned Problem18::getLargestSum()
{
	return this->getLargestSum(0, 0);
}

unsigned Problem18::getLargestSum(unsigned x, unsigned y)
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

unsigned Problem18::get(std::vector<unsigned> array, unsigned x, unsigned y)
{
	unsigned index = x*(x+1)/2 + y;
	return array[index];
}

void Problem18::set(std::vector<unsigned> array, unsigned x, unsigned y, unsigned value)
{
	unsigned index = x*(x+1)/2 + y;
	array[index] = value;
}
