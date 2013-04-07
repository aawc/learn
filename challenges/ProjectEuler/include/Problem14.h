#ifndef PROBLEM14_H
#define PROBLEM14_H
#include <vector>

class Problem14
{
	public:
		Problem14(long long);
		virtual ~Problem14();
		Problem14(const Problem14& other);
		Problem14& operator=(const Problem14& other);

		long long getLongestChainSeed();
	protected:
	private:
		long long numLimit;
		std::vector<long long> solvedLength;
		long long get(long long index);
		void set(long long index, long long value);
		long long getChainLengthForSeed(long long n);
};

#endif // PROBLEM14_H
