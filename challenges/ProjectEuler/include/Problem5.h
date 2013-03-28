#ifndef PROBLEM5_H
#define PROBLEM5_H
#include <vector>

class Problem5
{
	public:
		Problem5(unsigned int);
		virtual ~Problem5();
		Problem5(const Problem5& other);
		Problem5& operator=(const Problem5& other);

		long long getSmallestMultiple();
	protected:
	private:
		unsigned int maxNum;
		std::vector<unsigned int> primes;
		std::vector<unsigned int> recurrence;

		void generatePrimes();
		void generatePrimeRecurrences();
		long long generateProduct();
		bool isPrime(long long n);
};

#endif // PROBLEM5_H
