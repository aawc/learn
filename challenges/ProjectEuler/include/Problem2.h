#ifndef PROBLEM2_H
#define PROBLEM2_H

class Problem2
{
	public:
		Problem2(long long upperLimit);
		virtual ~Problem2();
		Problem2(const Problem2& other);
		Problem2& operator=(const Problem2& other);

		long long getSumUptoLimit();
	protected:
	private:
		long long upperLimit;
		long long sum;
		long long *terms;
		void updateSumAndTerms(long long next);
};

#endif // PROBLEM2_H
