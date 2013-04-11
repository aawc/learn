#ifndef PROBLEM23_H
#define PROBLEM23_H
#include <vector>
using namespace std;

class Problem23
{
	public:
		Problem23(unsigned);
		virtual ~Problem23();
		Problem23(const Problem23& other);
		Problem23& operator=(const Problem23& other);

		unsigned getSumOfNotSumsOfAbundantNumbers();
	protected:
	private:
		unsigned upperLimit;
		std::vector<unsigned> abundantNumbers;
		static unsigned getSumOfProperDivisors(unsigned n);
		void buildListOfAbundantNumbers();
};

#endif // PROBLEM23_H
