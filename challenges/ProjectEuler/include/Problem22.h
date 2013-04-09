#ifndef PROBLEM22_H
#define PROBLEM22_H
#include <string>
using namespace std;

class Problem22
{
	public:
		Problem22();
		virtual ~Problem22();
		Problem22(const Problem22& other);
		Problem22& operator=(const Problem22& other);

		unsigned long long getSortedWeightedSum();
	protected:
	private:
		static unsigned getNameValue(std::string name);
};

#endif // PROBLEM22_H
