#ifndef PROBLEM21_H
#define PROBLEM21_H

class Problem21
{
	public:
		Problem21(unsigned upperLimit);
		virtual ~Problem21();
		Problem21(const Problem21& other);
		Problem21& operator=(const Problem21& other);

		unsigned getSumOfAmicablePairs();
	protected:
	private:
		unsigned *sumOfProperDivisors;
		unsigned upperLimit;
		static unsigned getSumOfProperDivisors(int n);
};

#endif // PROBLEM21_H
