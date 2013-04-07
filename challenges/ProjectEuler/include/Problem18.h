#ifndef PROBLEM18_H
#define PROBLEM18_H
#include <vector>

class Problem18
{
	public:
		Problem18(unsigned);
		virtual ~Problem18();
		Problem18(const Problem18& other);
		Problem18& operator=(const Problem18& other);

		unsigned getLargestSum();
	protected:
	private:
		unsigned numRows;
		std::vector<unsigned> input;
		std::vector<unsigned> solution;
		unsigned getLargestSum(unsigned x, unsigned y);
		unsigned get(std::vector<unsigned>, unsigned, unsigned);
		void set(std::vector<unsigned>, unsigned, unsigned, unsigned);
};

#endif // PROBLEM18_H
