#include<Windows.h>
#include"Calendar.h"

namespace Escapist
{
	Calendar::Calendar()
	{
		SYSTEMTIME time;
		::GetSystemTime(&time);
		year = time.wYear;
		month = time.wMonth;
		day = time.wDay;
		hour = time.wHour;
		minute = time.wMinute;
		isLeapYear = Date::IsLeapYear(year);
	}
	Calendar::Calendar(const short& newYear, const short& newMonth, const short& newDay, const short& newHour, const short& newMinute)
	{
		year = newYear;
		isLeapYear = Date::IsLeapYear(year);

		if (newMonth >= 1 && newMonth <= 12)
			month = newMonth;

		if (newDay >= 1 && newDay <= Date::MonthMaxDays[isLeapYear][month])
			day = newDay;

		if (newHour >= 0 && newHour <= 23)
			hour = newHour;

		if (newMinute >= 0 && newMinute <= 59)
			minute = newMinute;
	}
	Calendar::Calendar(const Date& date, const Time& time) :year(date.GetYear()), month(date.GetMonth()), day(date.GetDay()), hour(time.GetHour()), minute(time.GetMinute()), isLeapYear(date.IsLeapYear()) {}
	Calendar::Calendar(const Calendar& calendar) :year(calendar.year), month(calendar.month), day(calendar.day), hour(calendar.hour), minute(calendar.minute), isLeapYear(calendar.isLeapYear) {}

	void Calendar::SetYear(const short& newYear)
	{
		year = newYear;
		isLeapYear = Date::IsLeapYear(year);

		if (!isLeapYear && month == 2 && day == 29)
			day = 28;
	}
	void Calendar::SetMonth(const short& newMonth)
	{
		if (newMonth >= 1 && newMonth <= 12)
		{
			month = newMonth;
			if (day > Date::MonthMaxDays[isLeapYear][month])
				day = Date::MonthMaxDays[isLeapYear][month];
		}
	}
	void Calendar::SetDay(const short& newDay)
	{
		if (newDay >= 1 && newDay <= Date::MonthMaxDays[isLeapYear][month])
			day = newDay;
	}
	void Calendar::SetHour(const short& newHour)
	{
		if (newHour >= 0 && newHour <= 23)
			hour = newHour;
	}
	void Calendar::SetMinute(const short& newMinute)
	{
		if (newMinute >= 0 && newMinute <= 59)
			minute = newMinute;
	}
}