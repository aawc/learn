#ifndef PROBLEM4_H
#define PROBLEM4_H

class Problem4
{
	public:
		Problem4(unsigned int);
		virtual ~Problem4();
		Problem4(const Problem4& other);
		Problem4& operator=(const Problem4& other);

		long long getLargestPalindromeProduct();
	protected:
	private:
		unsigned int numDigits;
		long long largestPalindromeProduct;
		bool isPalindrome(long long n);
		bool isPalindrome(unsigned int digits[], unsigned int length);
};

#endif // PROBLEM4_H
