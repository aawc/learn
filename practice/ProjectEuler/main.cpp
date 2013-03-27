#include <iostream>
#include "include/Problem2.h"
#include "include/Problem3.h"
#include "include/Problem4.h"
#include "include/Problem5.h"
#include "include/Problem7.h"

using namespace std;

int main()
{
	/*
	const long long int n2 = 4000000;
	Problem2* p2 = new Problem2(n2);
	long long a2 = p2->getSumUptoLimit();
	cout << "Answer2: " << a2 << endl;
	*/

	/*
	const long long int n3 = 600851475143;
	Problem3* p3 = new Problem3(n3);
	long long a3 = p3->getLargestPrime();
	cout << "Answer3: " << a3 << endl;
	*/

	/*
	const unsigned int n4 = 3;
	Problem4* p4 = new Problem4(n4);
	long long a4 = p4->getLargestPalindromeProduct();
	cout << "Answer4: " << a4 << endl;
	*/

	/*
	const unsigned int n5 = 20;
	Problem5* p5 = new Problem5(n5);
	long long a5 = p5->getSmallestMultiple();
	cout << "Answer5: " << a5 << endl;
	*/

	const unsigned int n7 = 10001;
	Problem7* p7 = new Problem7(n7);
	long long a7 = p7->getPrimeSeqNumber();
	cout << "Answer7: " << a7 << endl;

	return 0;
}
