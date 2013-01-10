#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
using namespace std;

template <class T>
class QuickSortSTL
{
	private:
		vector<T> A;

		void Sort(typename vector<T>::iterator start, typename vector<T>::iterator end)
		{
			if (start >= end)
			{
				return;
			}

			const typename vector<T>::iterator pivot = end;

			typename vector<T>::iterator i = start, store = start;
			while(i <= end)
			{
				if (*i < *pivot)
				{
					this->Swap(store, i);
					store++;
				}
				i++;
			}
			this->Swap(store, pivot);
			
			this->Sort(start, store-1);
			this->Sort(store+1, end);
		}
		
		void Swap (typename vector<T>::iterator a, typename vector<T>::iterator b)
		{
			T k = *a;
			*a = *b;
			*b = k;
		}

		void Display (void)
		{
			this->Display("");
		}

		void Display (std::string header)
		{
			if (header != "")
			{
				std::cout << header << std::endl;
			}
			typename vector<T>::iterator begin = this->A.begin();
			for (typename vector<T>::iterator i = begin; i != this->A.end(); i++)
			{
				std::cout << *i << std::endl;
			}
			std::cout << std::endl;
		}

	public:
		QuickSortSTL(int n, T(*randomGenerator)())
		{
			if (n <= 0)
			{
				return;
			}

			/* initialize random seed: */
			srand(time(NULL));

			for (int i = 0; i < n; i++)
			{
				this->A.push_back((*randomGenerator)());
			}

			this->Display("Before:");
			this->Sort(this->A.begin(), this->A.end()-1);
			this->Display("After:");
		}
};

int randomNumberGenerator()
{
	return rand();
}

int main (int argc, char* argv[])
{
	QuickSortSTL<int> *sort = new QuickSortSTL<int>(10, randomNumberGenerator);
}
