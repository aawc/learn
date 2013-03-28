#include <iostream>
#include "include/Problem2.h"
#include "include/Problem3.h"
#include "include/Problem4.h"
#include "include/Problem5.h"
#include "include/Problem7.h"
#include "include/Problem8.h"
#include "include/Problem9.h"
#include "include/Problem10.h"

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

	/*
	const unsigned int n7 = 10001;
	Problem7* p7 = new Problem7(n7);
	long long a7 = p7->getPrimeSeqNumber();
	cout << "Answer7: " << a7 << endl;
	*/

	/*
	const unsigned int n8 = 5;
	std::string input = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
	Problem8* p8 = new Problem8(input, n8);
	int a8 = p8->getLargestSubProduct();
	cout << "Answer8: " << a8 << endl;
	*/

	/*
	Problem9* p9 = new Problem9();
	int a9 = p9->getSpecialPythagoreanTriplet();
	cout << "Answer9: " << a9 << endl;
	*/

	const unsigned long n10 = 2000000;
	Problem10* p10 = new Problem10(n10);
	long long a10 = p10->getPrimeSum();
	cout << "Answer10: " << a10 << endl;

	return 0;
}
