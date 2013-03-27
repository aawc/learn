/*
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include "../include/Problem4.h"
#include "cmath"
using namespace std;

Problem4::Problem4(unsigned int numDigits) : numDigits(numDigits), largestPalindromeProduct(1)
{
}

Problem4::~Problem4()
{
}

Problem4::Problem4(const Problem4& other)
{
    this->numDigits = other.numDigits;
    this->largestPalindromeProduct = other.largestPalindromeProduct;
}

Problem4& Problem4::operator=(const Problem4& other)
{
    if (this == &other) return *this; // handle self assignment
    this->numDigits = other.numDigits;
    this->largestPalindromeProduct = other.largestPalindromeProduct;
    return *this;
}

bool Problem4::isPalindrome(long long n)
{
	if (n < 10) return true;

	unsigned int maxLength = 2*this->numDigits;
	unsigned int *digits = new unsigned int [maxLength];
	unsigned int length = 0;
	while (n > 0)
	{
		digits[length] = n%10;
		length++;
		n /= 10;
	}

	return isPalindrome(digits, length);
}

bool Problem4::isPalindrome(unsigned int digits[], unsigned int length)
{
	unsigned int mid = (length + 1)/2;
	unsigned int i, j;
	for (i = 0, j = length-1; i <= mid && j >= mid && digits[i] == digits[j]; i++, j--);

	return (i > j);
}

long long Problem4::getLargestPalindromeProduct()
{
    this->isPalindrome(9009);

	unsigned long maxNum = pow(10, this->numDigits) - 1;
	for (unsigned long i = maxNum; i >= 1; i--)
	{
		for (unsigned long j = maxNum; j >= 1; j--)
		{
			long long product = i * j;
			if (product > this->largestPalindromeProduct && this->isPalindrome(product))
			{
				this->largestPalindromeProduct = product;
			}
		}
	}

	return this->largestPalindromeProduct;
}
