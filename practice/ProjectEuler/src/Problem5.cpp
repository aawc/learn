/*
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */

#include "../include/Problem5.h"
#include <iostream>
#include <cmath>
using namespace std;

Problem5::Problem5(unsigned int maxNum) : maxNum(maxNum)
{

}

Problem5::~Problem5()
{
}

Problem5::Problem5(const Problem5& other)
{
	this->maxNum = other.maxNum;
	this->primes = other.primes;
	this->recurrence = other.recurrence;
}

Problem5& Problem5::operator=(const Problem5& other)
{
	if (this == &other) return *this; // handle self assignment
	this->maxNum = other.maxNum;
	this->primes = other.primes;
	this->recurrence = other.recurrence;
	return *this;
}

long long Problem5::getSmallestMultiple()
{
	this->generatePrimes();
	this->generatePrimeRecurrences();
	return this->generateProduct();
}

void Problem5::generatePrimes()
{
	for (unsigned int i = 2; i <= this->maxNum; i++)
	{
		if (this->isPrime(i))
		{
			cout << i << endl;
			this->primes.push_back(i);
			this->recurrence.push_back(0);
		}
	}
}

void Problem5::generatePrimeRecurrences()
{
	for (unsigned int i = 2; i < maxNum; i++)
	{
		cout << "Processing: " << i << endl;
		for (unsigned int index_prime = 0; index_prime < this->primes.size(); index_prime++)
		{
			unsigned int count = 0, copy = i, prime = this->primes[index_prime];
			while (copy % prime == 0)
			{
				count++;
				copy /= prime;
			}
			cout << i << " has " << count << " occurences of " << prime << endl;

			if (count > this->recurrence[index_prime])
			{
				this->recurrence[index_prime] = count;
				cout << i << " has pushed the occurences of " << prime << " to " << count << endl;
			}
		}
	}
}

long long Problem5::generateProduct()
{
	int product = 1;
	for (unsigned int i = 0; i < this->primes.size(); i++)
	{
		while (this->recurrence[i] > 0)
		{
			product *= this->primes[i];
			this->recurrence[i] --;
		}
	}
	return product;
}

bool Problem5::isPrime(long long n)
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
