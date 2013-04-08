#include "../include/Date.h"
#include <iostream>
using namespace std;

const unsigned Date::NumMonths;
const unsigned Date::NumOfDaysEachMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() : year(0), month(0), day(0), weekday(0)
{}

Date::Date(unsigned year, unsigned month, unsigned day, unsigned weekday) : year(year), month(month), day(day), weekday(weekday)
{}

Date::Date(unsigned year, unsigned month, unsigned day) : year(year), month(month), day(day), weekday(0)
{}

Date::Date(unsigned year, unsigned month, unsigned day, const Date& base) : year(year), month(month), day(day)
{
	int numDays = *this - base;
	this->weekday = (numDays + base.weekday) % 7;
}

Date::~Date()
{}

Date::Date(const Date& other)
{
	this->year = other.year;
	this->month = other.month;
	this->day = other.day;
	this->weekday = other.weekday;
}

Date& Date::operator=(const Date& other)
{
	if (this == &other) return *this; // handle self assignment
	this->year = other.year;
	this->month = other.month;
	this->day = other.day;
	this->weekday = other.weekday;
	return *this;
}

bool Date::operator==(const Date& other)
{
	return (this->year == other.year && this->month == other.month && this->day == other.day);
}

bool Date::operator>(const Date& other)
{
	return
		((this->year > other.year) ||
			((this->year == other.year) &&
  			((this->month > other.month) ||
				((this->month == other.month) && (this->day > other.day))
	 		))
  		);
}

unsigned Date::operator-(const Date& other)
{
	Date a = (*this > other) ? *this : other;
	Date b = (*this > other) ? other : *this;
	// a > b
	cout << "A: " << a.year << "/" << a.month << "/" << a.day << endl;
	cout << "B: " << b.year << "/" << b.month << "/" << b.day << endl;

	unsigned totalDaysOfDifference = 0;
	for (unsigned year = b.year; year < a.year; year++)
	{
		unsigned daysThisYear = Date::GetDaysForYear(year);
		cout << "Year: " << year << "; daysThisYear: " << daysThisYear << endl;
		totalDaysOfDifference += daysThisYear;
	}
	//cout << "totalDaysOfDifference: " << totalDaysOfDifference << endl;

	for (unsigned month = 1; month < a.month; month++)
	{
		unsigned daysThisMonth = Date::GetDaysForMonth(a.year, month);
		cout << "Month: " << month << "; daysThisMonth: " << daysThisMonth << endl;
		totalDaysOfDifference += daysThisMonth;
	}
	//cout << "totalDaysOfDifference: " << totalDaysOfDifference << endl;

	unsigned dateDifference = a.day - b.day;
	cout << "dateDifference: " << dateDifference << endl;
	totalDaysOfDifference += dateDifference;
	cout << "totalDaysOfDifference: " << totalDaysOfDifference << endl;

	return totalDaysOfDifference;
}

Date& Date::operator++()
{
	this->moveToNextDate();
	return *this;
}

unsigned Date::getYear()
{
	return this->year;
}

unsigned Date::getMonth()
{
	return this->month;
}

unsigned Date::getDay()
{
	return this->day;
}

unsigned Date::getWeekday()
{
	return this->weekday;
}

void Date::setYear(unsigned year)
{
	this->year = year;
}

void Date::setMonth(unsigned month)
{
	this->month = month;
}

void Date::setDay(unsigned day)
{
	this->day = day;
}

void Date::setWeekday(unsigned weekday)
{
	this->weekday = weekday;
}

bool Date::isLeapYear(unsigned year)
{
	return ((year%4 == 0) && ((year%100 != 0) || (year%400 == 0)));
}

unsigned Date::GetDaysForMonth(unsigned year, unsigned month)
{
	if (month == 2 && Date::isLeapYear(year)) // February
	{
		return Date::NumOfDaysEachMonth[month-1]+1;
	}
	else return Date::NumOfDaysEachMonth[month-1];
}

unsigned Date::GetDaysForYear(unsigned year)
{
	static unsigned numDays = 0;
	if (numDays == 0)
	{
		for (unsigned i = 0; i < Date::NumMonths; i++)
		{
			numDays += Date::NumOfDaysEachMonth[i];
		}
	}

	if (Date::isLeapYear(year))
		return numDays+1;
	else return numDays;
}

void Date::moveToNextDate()
{
	if (this->day == Date::GetDaysForMonth(this->year, this->month))
	{
		this->day = 1;

		if (this->month == Date::NumMonths)
		{
			this->month = 1;
			this->year++;
		}
		else this->month++;
	}
	else this->day++;
	this->weekday = (this->weekday + 1) % 7;
}
