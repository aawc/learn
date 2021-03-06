#include <iostream>
#include <vector>
/*
#include "include/Problem2.h"
#include "include/Problem3.h"
#include "include/Problem4.h"
#include "include/Problem5.h"
#include "include/Problem7.h"
#include "include/Problem8.h"
#include "include/Problem9.h"
#include "include/Problem10.h"
#include "include/Problem11.h"
#include "include/Problem12.h"
#include "include/Problem14.h"
#include "include/Problem15.h"
#include "include/Problem18.h"
#include "include/Problem19.h"
#include "include/Problem21.h"
#include "include/Problem22.h"
#include "include/Problem23.h"
#include "include/Problem24.h"
#include "include/Problem67.h"
*/
#include "include/Problem26.h"

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

	/*
	const unsigned long n10 = 2000000;
	Problem10* p10 = new Problem10(n10);
	long long a10 = p10->getPrimeSum();
	cout << "Answer10: " << a10 << endl;
	*/

	/*
	Problem11* p11 = new Problem11();
	long long a11 = p11->getLargestSubSeqProduct();
	cout << "Answer11: " << a11 << endl;
	*/

	/*
	const unsigned long n12 = 500;
	Problem12* p12 = new Problem12(n12);
	long long a12 = p12->getTriangleNumberWithDivisors();
	cout << "Answer12: " << a12 << endl;
	*/

	/*
	const unsigned long n14 = 1000000;
	Problem14* p14 = new Problem14(n14);
	long long a14 = p14->getLongestChainSeed();
	cout << "Answer14: " << a14 << endl;
	*/

	/*
	unsigned long n15= 20;
	Problem15* p15 = new Problem15(n15);
	long long a15 = p15->getLatticePaths();
	cout << "Answer15: " << a15 << endl;
	*/

	/*
	unsigned long n18 = 15;
	Problem18* p18 = new Problem18(n18);
	long long a18 = p18->getLargestSum();
	cout << "Answer18: " << a18 << endl;
	*/

	/*
	Date baseDate(1900, 1, 1, 1), d191(1901, 1, 1, baseDate), d192(2000, 12, 31, baseDate);
	Problem19* p19 = new Problem19();
	unsigned a19 = p19->getNumberOfSundays(d191, d192);
	cout << "Answer19: " << a19 << endl;
	*/

	/*
	unsigned n21 = 10000;
	Problem21* p21 = new Problem21(n21);
	unsigned a21 = p21->getSumOfAmicablePairs();
	cout << "Answer21: " << a21 << endl;
	*/

	/*
	Problem22* p22 = new Problem22();
	unsigned long long a22 = p22->getSortedWeightedSum();
	cout << "Answer22: " << a22 << endl;
	*/

	/*
	unsigned n23 = 29000;
	Problem23* p23 = new Problem23(n23);
	unsigned a23 = p23->getSumOfNotSumsOfAbundantNumbers();
	cout << "Answer23: " << a23 << endl;
	*/

	/*
	const unsigned array24[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<unsigned> v24 (array24, array24 + sizeof(array24) / sizeof(array24[0]));
	Problem24* p24 = new Problem24(v24);
	const unsigned limit24 = 1000000;
	std::vector<unsigned> a24 = p24->getPermutationNumber(limit24);
	cout << "Answer for limit: " << limit24 << ": ";
	for (unsigned i = 0; i < a24.size(); i++)
	{
		cout << a24[i] << " ";
	}
	cout << endl;
	*/

	unsigned n26 = 10;
	Problem26* p26 = new Problem26(n26);
	unsigned a26 = p26->getLongestRecurringCycle();
	cout << "Answer26: " << a26 << endl;

	/*
	unsigned long n67 = 100;
	std::string s67 = "E:\\Varun\\GitHub\\learn\\challenges\\ProjectEuler\\text\\Problem67.txt";
	Problem67* p67 = new Problem67(n67, s67);
	long long a67 = p67->getLargestSum();
	cout << "Answer67: " << a67 << endl;
	cin >> n67;
	*/

	return 0;
}
