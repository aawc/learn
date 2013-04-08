#ifndef DATE_H
#define DATE_H

class Date
{
public:
	Date();
	Date(unsigned, unsigned, unsigned, unsigned);
	Date(unsigned, unsigned, unsigned);
	Date(unsigned, unsigned, unsigned, const Date& base);
	virtual ~Date();
	Date(const Date& other);
	Date& operator=(const Date& other);
	bool operator==(const Date& other);
	bool operator>(const Date& other);
	unsigned operator-(const Date& other);
	Date& operator++();

private:
	unsigned year;
	unsigned month;
	unsigned day;
	unsigned weekday;

public:
	unsigned getYear();
	unsigned getMonth();
	unsigned getDay();
	unsigned getWeekday();
	void setYear(unsigned year);
	void setMonth(unsigned month);
	void setDay(unsigned day);
	void setWeekday(unsigned weekday);

	static bool isLeapYear(unsigned year);
	static unsigned GetDaysForYear(unsigned year);
	static unsigned GetDaysForMonth(unsigned year, unsigned month);
	
	void moveToNextDate();

	static const unsigned NumMonths = 12;
	static const unsigned NumOfDaysEachMonth[Date::NumMonths];
};

#endif // DATE_H
