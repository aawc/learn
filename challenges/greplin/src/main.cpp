#include <cstdio>
#include <iostream>
//#include "01_LongestPalindromeSubstring.cpp"
//#include "02_PrimeFibonacci.cpp"
#include "03_SubArrayLargestTermIsSum.cpp"
using namespace std;

int main (int argc, char* argv[])
{
	/*
	LongestPalindromeSubstring* longestPalindromeSubstring = new LongestPalindromeSubstring;
	cout << longestPalindromeSubstring->getLongestPalindromeSubstring() << endl;
	delete longestPalindromeSubstring;
	*/
	/*
	unsigned lowerLimit = 217000;
	PrimeFibonacci* primeFibonacci = new PrimeFibonacci;
	cout << primeFibonacci->getSumOfPrimeDivisorsOfFibinacciAfter(lowerLimit) << endl;
	delete primeFibonacci;
	*/
	SubArrayLargestTermIsSum* subArrayLargestTermIsSum = new SubArrayLargestTermIsSum;
	cout << subArrayLargestTermIsSum->getTheNumberOfSumSubsets() << endl;
	delete subArrayLargestTermIsSum;

	return 0;
}