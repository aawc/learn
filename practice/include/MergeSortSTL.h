#ifndef MERGESORTSTL_H
#define MERGESORTSTL_H
#include <string>
#include <vector>
using namespace std;

class MergeSortSTL
{
	private:
		vector<int> A;

		void Sort(vector<int>::iterator start, vector<int>::iterator end);
		void Merge (vector<int>::iterator start, vector<int>::iterator mid, vector<int>::iterator end);
		void Display (void);
		void Display (std::string header);

	public:
		MergeSortSTL(int n);
};

#endif //MERGESORTSTL_H
