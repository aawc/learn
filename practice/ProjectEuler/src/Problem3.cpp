/*
 * http://projecteuler.net/problem=3
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
 */

#include "../include/Problem3.h"
#include "cmath"
using namespace std;

Problem3::Problem3(long long number)
{
    this->number = number;
}

Problem3::~Problem3()
{
}

Problem3::Problem3(const Problem3& other)
{
    this->number = other.number;
}

Problem3& Problem3::operator=(const Problem3& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    this->number = rhs.number;
    return *this;
}

long long Problem3::getLargestPrime()
{
    long long root = sqrt(this->number);
    for (long long i = root; i > 1; i--)
    {
        if (this->number % i == 0 && this->isPrime(i))
        {
            return i;
        }
    }
    return 1;
}

bool Problem3::isPrime(long long n)
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
