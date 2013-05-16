#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class VAX_Random_Guess
{
private:
	unsigned long long seed;
	unsigned betsToGuess;
	static const unsigned cycleLength = 36;
	vector<unsigned> input;
	vector<unsigned long long> solution;
	unsigned inputSize;

public:
	VAX_Random_Guess()
	{
		unsigned long long seed = 6;

		this->solveForLevel2();
		this->solveForLevel5();
	}

private:
	unsigned long long VAXrand(unsigned long long seed)
	{
		static unsigned long long base = (unsigned long long)pow(2,32);
		unsigned long long s = ((69069 * seed + 1) % base);
		return s;
	}

	void init (void)
	{
		this->input.erase(this->input.begin(), this->input.end());
		this->solution.erase(this->solution.begin(), this->solution.end());
	}

	void setupForLevel2 (void)
	{
		this->seed = 6;
		this->betsToGuess = 2;

		this->input.push_back(19);
		this->input.push_back(16);
		this->inputSize = this->input.size();
	}

	void setupForLevel5 (void)
	{
		this->betsToGuess = 3;

		this->input.push_back(34);
		this->input.push_back(27);
		this->input.push_back(16);
		this->input.push_back(1);
		this->input.push_back(34);
		this->input.push_back(31);
		this->input.push_back(24);
		this->input.push_back(17);
		this->input.push_back(34);
		this->input.push_back(35);
		this->input.push_back(16);
		this->input.push_back(13);
		this->inputSize = this->input.size();
	}

	bool inputAndSolutionMatch (unsigned lengthToMatch)
	{
		unsigned solutionSize = this->solution.size();

		if (this->inputSize < lengthToMatch || solutionSize < lengthToMatch)
			return false;

		unsigned i = 0;
		while ((i < lengthToMatch) && (this->input[i] == this->solution[i]))
		{
			i++;
		}
		return i == lengthToMatch;
	}

	unsigned long long generateNextTerm (unsigned long long previousTerm)
	{
		unsigned long long nextTerm = this->VAXrand(previousTerm);
		this->solution.push_back(nextTerm % this->cycleLength);
		return nextTerm;
	}

	void solveForLevel2 (void)
	{
		this->init();
		this->setupForLevel2();

		unsigned long long previousTerm = seed;
		while (!this->inputAndSolutionMatch(this->inputSize))
		{
			previousTerm = this->generateNextTerm(previousTerm);
		}

		unsigned i = 0;
		cout << "Solving for 2:" << endl;
		while (i < this->betsToGuess)
		{
			previousTerm = this->generateNextTerm(previousTerm);
			cout << this->solution[this->solution.size() - 1] << endl;
			i++;
		}
	}

	void solveForLevel5 (void)
	{
		this->init();
		this->setupForLevel5();

		bool solutionFound = false;
		unsigned long long previousTerm;
		for (unsigned seed = 0; seed < seed + 1 && !solutionFound; seed++)
		{
			this->solution.erase(this->solution.begin(), this->solution.end());
			this->seed = seed;

			previousTerm = this->generateNextTerm(seed);
			while (this->inputAndSolutionMatch(this->solution.size()))
			{
				if (this->solution.size() == this->inputSize)
				{
					solutionFound = true;
					break;
				}
				previousTerm = this->generateNextTerm(previousTerm);
			}
		}

		unsigned i = 0;
		cout << "Solving for 5:" << endl;
		while (i < this->betsToGuess)
		{
			previousTerm = this->generateNextTerm(previousTerm);
			cout << this->solution[this->solution.size() - 1] << endl;
			i++;
		}
	}
};
/*
int main (int argc, char* argv[])
{
	VAX_Random_Guess* ptr = new VAX_Random_Guess();
	delete ptr;
	return 0;
}
*/
/*
#include <cstdio>
 
const unsigned long long m = 4294967296;
const unsigned long long a = 69069;
const unsigned long long c = 1;
const unsigned targets[] = {34, 27, 16, 1, 34, 31, 24, 17, 34, 35, 16, 13};
const unsigned targets_length = sizeof(targets) / sizeof(unsigned);
 
unsigned long long vax_random(const unsigned long long seed) {
  return (a * seed + c) % m;
}
 
int main(int argc, char **argv) {
  unsigned long long seed;
  unsigned last_percent = 0;
  for (unsigned long long initial_seed = 0; initial_seed < m; ++initial_seed) {
    unsigned percent = (int)((float)initial_seed / m * 100);
    if (last_percent < percent) {
      last_percent = percent;
      fprintf(stderr, "\b\b\b\b%3i%%", percent);
      fflush(stderr);
    }
    seed = initial_seed;
    bool seed_matched = true;
    for (unsigned i = 0; i < targets_length; ++i) {
      seed = vax_random(seed);
      if (seed % 36 != targets[i]) {
        seed_matched = false;
        break;
      }
    }
    if (seed_matched == true) {
      fprintf(stderr, "\b\b\b\bmatched with seed %llu\n", initial_seed);
      break;
    }
  }
  for (unsigned i = 0; i < 3; ++i) {
    seed = vax_random(seed);
    fprintf(stdout, "%llu\n", seed % 36);
  }
  return 0;
}
*/