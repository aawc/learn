/*
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 * What is the 10 001st prime number?
 */

#include "../include/Problem7.h"
#include <iostream>
#include <cmath>
using namespace std;

Problem7::Problem7(unsigned int primeSeqNumber) : primeSeqNumber(primeSeqNumber)
{

}

Problem7::~Problem7()
{
}

Problem7::Problem7(const Problem7& other)
{
	this->primeSeqNumber = other.primeSeqNumber;
}

Problem7& Problem7::operator=(const Problem7& other)
{
	if (this == &other) return *this; // handle self assignment
	this->primeSeqNumber = other.primeSeqNumber;
	return *this;
}

long long Problem7::getPrimeSeqNumber()
{
	long long count = 0, i = 2;
	while (true)
	{
		if (this->isPrime(i))
		{
			count ++;
		}

		if (count == this->primeSeqNumber)
		{
			return i;
		}
		i++;
	}
}

bool Problem7::isPrime(long long n)
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
