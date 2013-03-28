#ifndef PROBLEM8_H
#define PROBLEM8_H
#include <string>
using namespace std;

class Problem8
{
	public:
		Problem8(std::string, int);
		virtual ~Problem8();
		Problem8(const Problem8& other);
		Problem8& operator=(const Problem8& other);

		int getLargestSubProduct();
	protected:
	private:
		std::string input;
		int lengthOfSubstring;
		int product;
		int atoi(char c);
};

#endif // PROBLEM8_H
