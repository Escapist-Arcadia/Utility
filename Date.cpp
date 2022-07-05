#include<Windows.h>
#include"Date.h"

namespace Escapist
{
	const short Date::MonthMaxDays[2][13] = {
		{0,31,28,31,30,31,30,31,31,30,31,30,31} ,
		{0,31,29,31,30,31,30,31,31,30,31,30,31}
	};

	Date::Date()
	{
		SYSTEMTIME time;
		::GetSystemTime(&time);
		y = time.wYear;
		m = time.wMonth;
		d = time.wDay;
		isLeapYear = Date::IsLeapYear(y);
	}

	Date::Date(const short& year, const short& month, const short& day)
		:y(year), isLeapYear(Date::IsLeapYear(y))
	{
		if (month >= 1 && month <= 12)
			m = month;

		if (day <= MonthMaxDays[isLeapYear][m])
			d = day;
	}

	Date::Date(const Date& date) :y(date.y), m(date.m), d(date.d), isLeapYear(Date::IsLeapYear(y)) {}

	bool Date::IsLeapYear(const short& year) { return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); }

	void Date::SetYear(const short& year)
	{
		y = year;
		isLeapYear = Date::IsLeapYear(year);

		// Wwhen the new year is not a leap year while the old month/day is 02/29, it will change to 03/01.
		if (!isLeapYear && m == 2 && d == 29)
			d = 28;
	}

	void Date::SetMonth(const short& month)
	{
		// The month can only be from 1 to 12.
		if (month >= 1 && month <= 12)
		{
			m = month;

			if (d > Date::MonthMaxDays[isLeapYear][m])
				d = Date::MonthMaxDays[isLeapYear][m];
		}
	}

	void Date::SetDay(const short& day)
	{
		// Range check~
		if (day >= 1 && day <= Date::MonthMaxDays[isLeapYear][m])
			d = day;
	}

	int Date::Compare(const short& leftYear, const short& leftMonth, const short& leftDay,
		const short& rightYear, const short& rightMonth, const short& rightDay)
	{
		if (leftYear == rightYear)
			if (leftMonth == rightMonth)
				if (leftDay == rightDay)
					return 0;
				else
					if (leftDay < rightDay)
						return 1;
					else
						return -1;
			else
				if (leftMonth < rightMonth)
					return 1;
				else
					return -1;
		else
			if (leftYear < rightYear)
				return 1;
			else
				return -1;
	}
	int Date::Compare(const Date& left, const Date& right)
	{
		return Date::Compare(left.y, left.m, left.d, right.y, right.m, right.d);
	}

	int Date::CompareTo(const short& year, const short& month, const short& day)const
	{
		return Date::Compare(y, m, d, year, month, day);
	}
	int Date::CompareTo(const Date& other)const
	{
		return Date::Compare(y, m, d, other.y, other.m, other.d);
	}

	void Date::AddDays(const short& days)
	{
		d += days;

		while (d > Date::MonthMaxDays[isLeapYear][m])
		{
			d -= Date::MonthMaxDays[isLeapYear][m];
			++m;

			if (m == 13)
			{
				m = 1;
				++y;
				isLeapYear = Date::IsLeapYear(y);
			}
		}
	}

	void Date::AddMonths(const short& months)
	{
		m += months;

		while (m > 12)
		{
			m -= 12;
			++y;
			isLeapYear = Date::IsLeapYear(y);
		}

		if (d > Date::MonthMaxDays[isLeapYear][m])
			d = Date::MonthMaxDays[isLeapYear][m];
	}

	void Date::AddYears(const short& years)
	{
		y += years;
		isLeapYear = Date::IsLeapYear(y);

		if (!isLeapYear && m == 2 && d == 29)
			d = 28;
	}

	void Date::SubtractDays(const short& days)
	{
		d -= days;

		while (d <= 0)
		{
			--m;
			if (m == 0)
			{
				m = 12;
				--y;
				isLeapYear = Date::IsLeapYear(y);
			}

			d += Date::MonthMaxDays[isLeapYear][m];
		}
	}

	void Date::SubtractMonths(const short& months)
	{
		m -= months;

		while (m <= 0)
		{
			m += 12;
			--y;
			isLeapYear = Date::IsLeapYear(y);
		}

		if (d > Date::MonthMaxDays[isLeapYear][m])
			d = Date::MonthMaxDays[isLeapYear][m];
	}

	void Date::SubtractYears(const short& years)
	{
		y -= years;
		isLeapYear = Date::IsLeapYear(y);

		if (!isLeapYear && m == 2 && d == 29)
			d = 28;
	}
}