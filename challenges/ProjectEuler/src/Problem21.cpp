/*
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
 * If d(a) = b and d(b) = a, where a  b, then a and b are an amicable pair and each of a and b are called amicable numbers.
 
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
 * Evaluate the sum of all the amicable numbers under 10000.
 */

#include "../include/Problem21.h"
#include <iostream>
#include <cmath>
using namespace std;

Problem21::Problem21(unsigned upperLimit) : upperLimit(upperLimit)
{
	this->sumOfProperDivisors = new unsigned[upperLimit];
}

Problem21::~Problem21()
{
	delete []this->sumOfProperDivisors;
}

Problem21::Problem21(const Problem21& other)
{
	this->upperLimit = other.upperLimit;
	this->sumOfProperDivisors = other.sumOfProperDivisors;
}

Problem21& Problem21::operator=(const Problem21& other)
{
	if (this == &other) return *this; // handle self assignment
	this->upperLimit = other.upperLimit;
	this->sumOfProperDivisors = other.sumOfProperDivisors;
	return *this;
}

unsigned Problem21::getSumOfAmicablePairs()
{
	for (unsigned i = 0; i < this->upperLimit; i++)
	{
		this->sumOfProperDivisors[i] = Problem21::getSumOfProperDivisors(i+1);
	}

	unsigned sum = 0;
	for (unsigned i = 1; i <= this->upperLimit; i++)
	{
		unsigned other = this->sumOfProperDivisors[i-1];
		if ((other <= this->upperLimit) && (other > i) && (this->sumOfProperDivisors[other-1] == i))
		{
			cout << i << " and " << other << endl;
			sum += (i + other);
		}
	}
	return sum;
}

unsigned Problem21::getSumOfProperDivisors(int n)
{
	if (n == 1)
	{
		//cout << "n: " << n << "; sumOfProperDivisors: 1" << endl;
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

	//cout << "n: " << n << "; sumOfProperDivisors: " << sum << endl;
	return sum;
}
