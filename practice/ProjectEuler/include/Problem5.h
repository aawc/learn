#ifndef PROBLEM5_H
#define PROBLEM5_H

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
		unsigned int numDigits;
		long long largestPalindromeProduct;
		bool isPalindrome(long long n);
		bool isPalindrome(unsigned int digits[], unsigned int length);
};

#endif // PROBLEM5_H
