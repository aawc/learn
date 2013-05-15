#include <iostream>
#include <cmath>
using namespace std;

class VAX_Random_Guess
{
public:
	unsigned long long VAXrand(unsigned long long seed)
	{
		unsigned long long s = ((69069 * seed + 1) % (unsigned long long)pow(2,32));
		return s;
	}

	VAX_Random_Guess()
	{
		unsigned long long seed = 6;
		for (unsigned n = 0; n < 10; n++)
		{
			unsigned long long result = this->VAXrand(seed);
			cout << "seed: " << seed << " | result: " << result << " | result%36: " << result%36 << endl;
			seed = result;
		}
	}
};

int main (int argc, char* argv[])
{
	VAX_Random_Guess* ptr = new VAX_Random_Guess();
	delete ptr;
	return 0;
}