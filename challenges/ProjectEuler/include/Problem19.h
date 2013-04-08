#ifndef PROBLEM19_H
#define PROBLEM19_H
#include "../include/Date.h"

class Problem19
{
	public:
		Problem19();
		virtual ~Problem19();
		Problem19(const Problem19& other);
		Problem19& operator=(const Problem19& other);

		unsigned getNumberOfSundays(Date date1, Date date2);
	protected:
	private:
};

#endif // PROBLEM19_H
