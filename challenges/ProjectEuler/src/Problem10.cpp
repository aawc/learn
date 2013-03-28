/*
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
 */

#include "../include/Problem10.h"
#include <iostream>
#include <cmath>
using namespace std;

Problem10::Problem10(unsigned long upperLimit) : upperLimit(upperLimit)
{
}

Problem10::~Problem10()
{
}

Problem10::Problem10(const Problem10& other)
{
	this->upperLimit = other.upperLimit;
}

Problem10& Problem10::operator=(const Problem10& other)
{
	if (this == &other) return *this; // handle self assignment
	this->upperLimit = other.upperLimit;
	return *this;
}

long long Problem10::getPrimeSum()
{
	unsigned long i = 2;
	unsigned long long sum = 0;
	while (i < this->upperLimit)
	{
		if (this->isPrime(i))
		{
		    //cout << i << endl;
			sum += i;
		}
		i++;
	}

	return sum;
}

bool Problem10::isPrime(long long n)
{
	long long root = sqrt(n);
	for (long long i = root; i > 1; i--)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
