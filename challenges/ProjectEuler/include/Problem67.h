#ifndef PROBLEM67_H
#define PROBLEM67_H
#include <fstream>
#include <vector>

class Problem67
{
	public:
		Problem67(unsigned, std::string);
		virtual ~Problem67();
		Problem67(const Problem67& other);
		Problem67& operator=(const Problem67& other);

		unsigned getLargestSum();
	protected:
	private:
		unsigned numRows;
		std::ifstream fin;
		std::vector<unsigned> input;
		std::vector<unsigned> solution;
		unsigned getLargestSum(unsigned x, unsigned y);
		unsigned get(std::vector<unsigned>, unsigned, unsigned);
		void set(std::vector<unsigned>, unsigned, unsigned, unsigned);
};

#endif // PROBLEM67_H
