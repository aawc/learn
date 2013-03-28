#ifndef PROBLEM9_H
#define PROBLEM9_H
#include <string>
using namespace std;

class Problem9
{
	public:
		Problem9();
		virtual ~Problem9();
		Problem9(const Problem9& other);
		Problem9& operator=(const Problem9& other);

		int getSpecialPythagoreanTriplet();
	protected:
	private:
};

#endif // PROBLEM9_H
