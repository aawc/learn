/*
 * You are given the following information, but you may prefer to do some research for yourself.
 * 1 Jan 1900 was a Monday.
 * Thirty days has September,
 * April, June and November.
 * All the rest have thirty-one,
 * Saving February alone,
 * Which has twenty-eight, rain or shine.
 * And on leap years, twenty-nine.
 * A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
 * How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 */

#include "../include/Problem19.h"
#include "../include/Date.h"
#include <iostream>
using namespace std;

Problem19::Problem19()
{
}

Problem19::~Problem19()
{
}

Problem19::Problem19(const Problem19& other)
{
}

Problem19& Problem19::operator=(const Problem19& other)
{
	if (this == &other) return *this; // handle self assignment
	return *this;
}

unsigned Problem19::getNumberOfSundays(Date date1, Date date2)
{
	Date d(date1);
	unsigned count = 0;

	while (date2 > d || date2 == d)
	{
		if (d.getWeekday() == 0 && d.getDay() == 1)
		{
			count++;
		}
		++d;
	}

	return count;
}
