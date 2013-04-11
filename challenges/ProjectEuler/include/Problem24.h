#ifndef PROBLEM24_H
#define PROBLEM24_H
#include <vector>
using namespace std;

class Problem24
{
	public:
		Problem24(std::vector<unsigned> &);
		virtual ~Problem24();
		Problem24(const Problem24& other);
		Problem24& operator=(const Problem24& other);

		std::vector<unsigned> getPermutationNumber(unsigned limit);
	protected:
	private:
		std::vector<unsigned> input, answer;
		void getPermutationsAtLevel(unsigned level, std::vector<unsigned>current, unsigned limit);
		unsigned currentCount;
};

#endif // PROBLEM24_H
