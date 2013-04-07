#ifndef PROBLEM15_H
#define PROBLEM15_H
#include <vector>

class Problem15
{
	public:
		Problem15(unsigned);
		virtual ~Problem15();
		Problem15(const Problem15& other);
		Problem15& operator=(const Problem15& other);

		long long getLatticePaths();
	protected:
	private:
		unsigned numBoxes;
		long long ** solution;
		long long getLatticePaths(unsigned x, unsigned y);
};

#endif // PROBLEM15_H
