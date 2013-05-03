#ifndef INSERTSORT_H
#define INSERTSORT_H
#include<string>

class InsertSort
{
	private:
		int length;
		int *A;

		void Sort();
		void Display (void);
		void Display (std::string header);
		void SortRecursively (int length);

	public:
		InsertSort(int n);
};

#endif //INSERTSORT_H
