/*
  The Cue Programming Challenge

  Level 2

  ----------------------------------------

  Congratulations.  You have reached level 2.

  To get the password for level 3, write code to find the first prime
  fibonacci number larger than a given minimum.  For example, the first
  prime fibonacci number larger than 10 is 13.

  When you are ready, go here or call this automated
  number (415) 799-9454.

  You will receive additional instructions at that time.  For the second portion
  of this task, note that for the number 12 we consider the sum of the prime divisors
  to be 2 + 3 = 5.  We do not include 2 twice even though it divides 12 twice.

  Additional instructions:
  	Step 1. Use your code to compute the smallest prime fibonacci number
	        greater than 227,000.  Call this number X.
	
	Step 2. The password for level 3 is the sum of prime divisors of X + 1.
	
	Note: If you call the number instead, it will check your answer for step 1.

  Enter the password to access level 3: 
*/

#include <cmath>

class PrimeFibonacci
{
private:
	unsigned getPrimeFibonacciLargerThan(unsigned lowerLimit)
	{
		unsigned lastTerm = 1, currentTerm = 1;
		while(currentTerm <= lowerLimit || !this->isPrime(currentTerm))
		{
			unsigned nextTerm = currentTerm + lastTerm;
			lastTerm = currentTerm;
			currentTerm = nextTerm;
		}
		
		return currentTerm;
	}

	bool isPrime (unsigned number)
	{
		if (number == 2)
			return true;

		if (number % 2 == 0)
			return false;

		double sqRoot = sqrt(number);
		for (unsigned i = 3; i <= sqRoot; i += 2)
		{
			if (number % i == 0)
				return false;
		}
		return true;
	}

public:
	unsigned getSumOfPrimeDivisorsOfFibinacciAfter(unsigned lowerLimit)
	{
		unsigned numberToGetPrimedDivisorsOf = this->getPrimeFibonacciLargerThan(lowerLimit) + 1;
		double sqRoot = sqrt(numberToGetPrimedDivisorsOf);
		unsigned sum = 0;
		for (unsigned i = 2; i <= sqRoot; i++)
		{
			if ((numberToGetPrimedDivisorsOf % i == 0) && this->isPrime(i))
			{
				sum += i;
				if (i != sqRoot)
				{
					unsigned otherTerm = numberToGetPrimedDivisorsOf / i;
					if (this->isPrime(otherTerm))
					{
						sum += otherTerm;
					}
				}
			}
		}
		return sum;
	}
};