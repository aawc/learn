/*
 * A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:
	1/2	= 	0.5
	1/3	= 	0.(3)
	1/4	= 	0.25
	1/5	= 	0.2
	1/6	= 	0.1(6)
	1/7	= 	0.(142857)
	1/8	= 	0.125
	1/9	= 	0.(1)
	1/10= 	0.1

 * Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.
 * Find the value of d  1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
 */

#include "../include/Problem26.h"
#include <cmath>
#include <iostream>
using namespace std;

Problem26::Problem26(unsigned limit) : limit(limit)
{
}

Problem26::~Problem26()
{
}

Problem26::Problem26(const Problem26& other)
{
	this->limit = other.limit;
}

Problem26& Problem26::operator=(const Problem26& other)
{
	if (this == &other) return *this; // handle self assignment
	this->limit = other.limit;
	return *this;
}

unsigned Problem26::getLongestRecurringCycle()
{
	unsigned longestSoFar = 0, longestSoFarSeed = 0;
	for (unsigned seed = 2; seed <= this->limit; seed++)
	{
		unsigned thisSeedRecurringLength = Problem26::getRecurringLength(seed);
		if (thisSeedRecurringLength > longestSoFar)
		{
			longestSoFar = thisSeedRecurringLength;
			longestSoFarSeed = seed;
		}
	}

	return longestSoFarSeed;
}

unsigned Problem26::getRecurringLength(unsigned seed)
{
	unsigned first = 0, second;
	long double inverse = 1.0/seed, tempFirst, tempSecond;
	long double difference;
	bool foundPair = false;

	while(!foundPair)
	{
		first++;
		tempFirst = inverse * pow(10, first);
		if (Problem26::isInt(tempFirst))
		{
			// Not a recurring value.
			second = first;
			foundPair = true;
			break;
		}

		for (second = 0; second < first; second++)
		{
			tempSecond = inverse * pow(10, second);
			difference = tempFirst - tempSecond;

			if(Problem26::isInt(difference))
			{
				foundPair = true;
				break;
			}
		}
	}

	cout << "Seed: " << seed << "; First: " << first << " - Second: " << second << " = " << (first-second) << endl;
	return (first-second);
}

bool Problem26::isInt(long double d)
{
	const long double EPSILON = 0.0000001;
	return (((d - (unsigned long)d)/d < EPSILON) || ((((unsigned long)d + 1) - d)/d < EPSILON));
}
