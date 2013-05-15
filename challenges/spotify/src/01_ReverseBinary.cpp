/*
Task
Your task will be to write a program for reversing numbers in binary. For instance, the binary representation of 13 is 1101, and reversing it gives 1011, which corresponds to number 11.

Input
The input contains a single line with an integer N, 1 ≤ N ≤ 1000000000.

Output
Output one line with one integer, the number we get by reversing the binary representation of N.
*/
#include<iostream>
using namespace std;

class ReverseBinary
{
public:
	unsigned long long getReverseBinary(unsigned long long numberToReverse)
	{
		unsigned long long reversed = 0;
		while (numberToReverse > 0)
		{
			unsigned bit = numberToReverse % 2;
			numberToReverse = numberToReverse >> 1;
			reversed = (reversed << 1) + bit;
		}

		return reversed;
	}
};

int main (int argc, char* argv[])
{
	unsigned long long numberToReverse;
	cin >> numberToReverse;
	ReverseBinary * reverseBinary = new ReverseBinary;
	cout << reverseBinary->getReverseBinary(numberToReverse) << endl;
}