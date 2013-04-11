/*
 * A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
 * For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 * A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
 *
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24.
 * By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers.
 * However, this upper limit cannot be reduced any further by analysis even though it is known that
 * the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
 *
 * Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
 */

#include "../include/Problem23.h"
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

Problem23::Problem23(unsigned upperLimit) : upperLimit(upperLimit)
{
}

Problem23::~Problem23()
{
}

Problem23::Problem23(const Problem23& other)
{
	this->upperLimit = other.upperLimit;
	this->abundantNumbers = other.abundantNumbers;
}

Problem23& Problem23::operator=(const Problem23& other)
{
	if (this == &other) return *this; // handle self assignment
	this->upperLimit = other.upperLimit;
	this->abundantNumbers = other.abundantNumbers;
	return *this;
}

unsigned Problem23::getSumOfNotSumsOfAbundantNumbers()
{
	this->buildListOfAbundantNumbers();

	unsigned count = this->abundantNumbers.size(), sum = 0;
	for (unsigned n = 1; n <= this->upperLimit; n++)
	{
		bool isSumOfAbundantNumbers = false;
		unsigned i = 0;
		while (!isSumOfAbundantNumbers && i <= count/2)
		{
			unsigned difference = n - this->abundantNumbers[i];
			std::vector<unsigned>::iterator it = std::find(this->abundantNumbers.begin(), this->abundantNumbers.end(), difference);
			if (it != this->abundantNumbers.end())
			{
				//cout << n << " = " << (n-difference) << " + " << difference << endl;
				isSumOfAbundantNumbers = true;
			}
			i++;
		}

		if (!isSumOfAbundantNumbers)
		{
			//cout << n << " is not a sum of abundant numbers." << endl;
			sum += n;
		}
	}

	return sum;
}

void Problem23::buildListOfAbundantNumbers()
{
	for (unsigned i = 1; i <= this->upperLimit; i++)
	{
		unsigned sumOfProperDivisors = Problem23::getSumOfProperDivisors(i);
		if (sumOfProperDivisors > i)
		{
			//cout << "i: " << i << "; Sum: " << sumOfProperDivisors << endl;
			this->abundantNumbers.push_back(i);
		}
	}
}

unsigned Problem23::getSumOfProperDivisors(unsigned n)
{
	if (n == 1)
	{
		return 1;
	}

	double sqrtDouble = sqrt(n);
	unsigned sqrtInt = sqrtDouble;

	unsigned i = 1, sum = 0;
	while (i < sqrtDouble)
	{
		if (n%i==0)
		{
			sum += (i + n/i);
		}
		i++;
	}
	sum -= n;
	if (sqrtDouble == sqrtInt)
	{
		sum += sqrtInt;
	}

	//cout << "getSumOfProperDivisors: n: " << n << "; Sum: " << sum << endl;
	return sum;
}
