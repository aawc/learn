#ifndef PROBLEM10_H
#define PROBLEM10_H

class Problem10
{
	public:
		Problem10(unsigned long);
		virtual ~Problem10();
		Problem10(const Problem10& other);
		Problem10& operator=(const Problem10& other);

		long long getPrimeSum();
	protected:
	private:
		unsigned long upperLimit;
		bool isPrime(long long n);
};

#endif // PROBLEM10_H
