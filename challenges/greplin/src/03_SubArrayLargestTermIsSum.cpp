/*
  The Cue Programming Challenge

  Level 3

  ----------------------------------------

  Congratulations.  You have reached the final level.

  For the final task, you must find all subsets of an array
  where the largest number is the sum of the remaining numbers.
  For example, for an input of:

  (1, 2, 3, 4, 6)

  the subsets would be

  1 + 2 = 3
  1 + 3 = 4
  2 + 4 = 6
  1 + 2 + 3 = 6

  Here is the list of numbers you should run your code on.
  The password is the number of subsets.  In the above case the
  answer would be 4.

  Enter the password to complete the challenge: 
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class SubArrayLargestTermIsSum
{
private:
	vector<unsigned> solution;
	vector<unsigned> input;

	unsigned getNumberOfSeriesForSum (unsigned sum, unsigned level, unsigned startIndex)
	{
		unsigned answer = 0;
		for (unsigned i = startIndex; i < this->input.size(); i++)
		{
			unsigned thisElement = this->input[i];
			if (sum < thisElement)
			{
				break;
			}
			else
			{
				if (sum == thisElement)
				{
					if (level != 0)
					{
						this->solution[level] = thisElement;
						answer++;
					}
				}
				else
				{
					this->solution[level] = thisElement;
					answer += this->getNumberOfSeriesForSum(sum - thisElement, level+1, i+1);
				}
			}
		}

		return answer;
	}

public:
	unsigned getTheNumberOfSumSubsets()
	{
		unsigned numberOfTerms;
		cin >> numberOfTerms;

		while (numberOfTerms > 0)
		{
			unsigned in;
			cin >> in;
			input.push_back(in);
			solution.push_back(0);

			numberOfTerms--;
		}
		sort(input.begin(), input.end());

		unsigned sum = 0;
		for (int i = input.size()-1; i >= 0; i--)
		{
			unsigned count = this->getNumberOfSeriesForSum(input[i], 0, 0);
			sum += count;
		}

		return sum;
	}
};