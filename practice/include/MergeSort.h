#ifndef MERGESORT_H
#define MERGESORT_H
#include<string>

class MergeSort
{
	private:
		int length;
		int *A;

		void Sort(int start, int end);
		void Merge (int start, int mid, int end);
		void Display (void);
		void Display (std::string header);

	public:
		MergeSort(int n);
};

#endif //MERGESORT_H
