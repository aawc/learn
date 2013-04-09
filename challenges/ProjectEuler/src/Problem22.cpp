/*
 * Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order.
 * Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
 * For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list.
 * So, COLIN would obtain a score of 938 x 53 = 49714.
 *
 * What is the total of all the name scores in the file?
 *
 * "sort Problem22.txt > Problem22Sorted.txt"
 */

#include "../include/Problem22.h"
#include <iostream>
#include <cmath>
using namespace std;

Problem22::Problem22()
{
}

Problem22::~Problem22()
{
}

Problem22::Problem22(const Problem22& other)
{
}

Problem22& Problem22::operator=(const Problem22& other)
{
	if (this == &other) return *this; // handle self assignment
	return *this;
}

unsigned long long Problem22::getSortedWeightedSum()
{
	unsigned long long sum = 0;
	unsigned count = 0;
	std::string name;

	while(getline(cin, name))
	{
		count++;
		unsigned individualSum = Problem22::getNameValue(name);
		//cout << "Name: " << name << "; Sum: " << individualSum << endl;
		sum += (individualSum * count);
	}
	return sum;
}

unsigned Problem22::getNameValue(string name)
{
	unsigned sum = 0;
	for (unsigned i = 0; i < name.size(); i++)
	{
		sum += (toupper(name[i]) - 'A' + 1);
	}
	return sum;
}
