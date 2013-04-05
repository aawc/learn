#ifndef PROBLEM12_H
#define PROBLEM12_H

class Problem12
{
	public:
		Problem12(unsigned int);
		virtual ~Problem12();
		Problem12(const Problem12& other);
		Problem12& operator=(const Problem12& other);

		long long getTriangleNumberWithDivisors();
	protected:
	private:
		unsigned int numDivisorsLimit;
		unsigned int numberOfDivisors(long long);
};

#endif // PROBLEM12_H
