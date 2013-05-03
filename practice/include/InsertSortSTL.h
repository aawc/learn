#ifndef INSERTSORTSTL_H
#define INSERTSORTSTL_H
#include <string>
#include <vector>
using namespace std;

class InsertSortSTL
{
	private:
		vector<int> numbers;

		void Sort ();
		void Insert (vector<int>::iterator start, vector<int>::iterator mid, vector<int>::iterator end);
		void Display (void);
		void Display (std::string header);
		void SortRecursively (std::vector<int>::iterator current);

	public:
		InsertSortSTL(int n);
};

#endif //INSERTSORTSTL_H
