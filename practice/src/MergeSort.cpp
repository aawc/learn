#include <iostream>
#include <cstdlib>
#include <time.h>

class MergeSortSTL
{
	private:
		int length;
		int *A;

		void Sort(int start, int end)
		{
			if (start >= end)
			{
				return;
			}

			int mid = (start + end) / 2;
			this->Sort(start, mid);
			this->Sort(mid+1, end);

			this->Merge(start, mid, end);
		}
		
		void Merge (int start, int mid, int end)
		{
			int tempLength = end - start + 1;
			int *B = new int[tempLength];
			int k = 0, i = start, j = mid+1;
			while (i <= mid && j <= end)
			{
				if (A[i] <= A[j])
				{
					B[k] = A[i];
					i++;
				}
				else
				{
					B[k] = A[j];
					j++;
				}
				k++;
			}
			while (i <= mid)
			{
				B[k] = A[i];
				i++; k++;
			}
			while (j <= end)
			{
				B[k] = A[j];
				j++; k++;
			}
			
			i = start; k = 0;
			while (k < tempLength)
			{
				A[i] = B[k];
				i++; k++;
			}
			delete []B;
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
			for (int i = 0; i < this->length; i++)
			{
				std::cout << this->A[i] << std::endl;
			}
			std::cout << std::endl;
		}

	public:
		MergeSortSTL(int n)
		{
			if (n <= 0)
			{
				return;
			}

			/* initialize random seed: */
			srand(time(NULL));

			this->length = n;
			this->A = new int [this->length];
			
			for (int i = 0; i < this->length; i++)
			{
				this->A[i] = rand();
			}

			this->Display("Before:");
			this->Sort(0, n-1);
			this->Display("After:");
		}
};

int main (int argc, char* argv[])
{
	MergeSortSTL *sort = new MergeSortSTL(10);
}
