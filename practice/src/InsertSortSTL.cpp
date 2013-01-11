#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>

class InsertionSort
{
	private:
		std::vector<int> numbers;

		void SortRecursively (std::vector<int>::iterator current)
		{
			std::vector<int>::iterator begin = this->numbers.begin();
			if (current == begin)
			{
				return;
			}

			this->SortRecursively(current - 1);

			int key = *current;
			std::vector<int>::iterator j = current - 1;
			while (j >= begin && *j > key)
			{
				*(j+1) = *j;
				j--;
			}
			*(j+1) = key;
		}

		void Sort (void)
		{
			std::vector<int>::iterator i;
			for (i = this->numbers.begin(); i != this->numbers.end(); i++)
			{
				int key = *i;
				std::vector<int>::iterator j = i-1;
				while (j >= this->numbers.begin() && *j > key)
				{
					*(j+1) = *j;
					j--;
				}
				*(j+1) = key;

				std::cout << "After iteration " << (i - this->numbers.begin() + 1) << ":" << std::endl;
				this->Display();
			}
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
			for (int i = 0; i < this->numbers.size(); i++)
			{
				std::cout << this->numbers[i] << std::endl;
			}
			std::cout << std::endl;
		}

	public:
	InsertionSort(int n)
	{
		if (n <= 0)
		{
			return;
		}

		/* initialize random seed: */
 		srand(time(NULL));

		for (int i = 0; i < n; i++)
		{
			this->numbers.push_back(rand());
		}

		this->Display("Before:");
		this->SortRecursively(this->numbers.end() - 1);
		//this->Sort();
		this->Display("After:");
	}
};

int main (int argc, char* argv[])
{
	InsertionSort *sort = new InsertionSort(10);
}
