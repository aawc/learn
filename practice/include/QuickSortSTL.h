#ifndef QUICKSORTSTL_H
#define QUICKSORTSTL_H
#include <string>
#include <vector>
using namespace std;

template <class T>
class QuickSortSTL
{
	private:
		vector<T> A;

		void Sort(typename vector<T>::iterator start, typename vector<T>::iterator end);
		void Quick (typename vector<T>::iterator start, typename vector<T>::iterator mid, typename vector<T>::iterator end);
		void Display (void);
		void Display (std::string header);
		void Swap (typename vector<T>::iterator a, typename vector<T>::iterator b);

	public:
		QuickSortSTL(unsigned n, T(*randomGenerator)());
};

#endif //QUICKSORTSTL_H
