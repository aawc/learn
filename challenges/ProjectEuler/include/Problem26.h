#ifndef PROBLEM26_H
#define PROBLEM26_H
#include <vector>
using namespace std;

class Problem26
{
	public:
		Problem26(unsigned);
		virtual ~Problem26();
		Problem26(const Problem26& other);
		Problem26& operator=(const Problem26& other);

		unsigned getLongestRecurringCycle();
	protected:
	private:
		unsigned limit;
		static unsigned getRecurringLength(unsigned seed);
		static bool isInt(long double d);
};

#endif // PROBLEM26_H
