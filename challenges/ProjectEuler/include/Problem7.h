#ifndef PROBLEM7_H
#define PROBLEM7_H

class Problem7
{
	public:
		Problem7(unsigned int);
		virtual ~Problem7();
		Problem7(const Problem7& other);
		Problem7& operator=(const Problem7& other);

		long long getPrimeSeqNumber();
	protected:
	private:
		unsigned int primeSeqNumber;
		bool isPrime(long long n);
};

#endif // PROBLEM7_H
