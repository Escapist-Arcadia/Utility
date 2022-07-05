#pragma once

#include"Date.h"
#include"Time.h"

namespace Escapist
{
	class Calendar
	{
	private:
		short year;
		short month;
		short day;
		short hour;
		short minute;

		bool isLeapYear;

	public:
		Calendar();
		Calendar(const short& newYear, const short& newMonth, const short& newDay, const short& newHour, const short& newMinute);
		Calendar(const Date& date, const Time& time);
		Calendar(const Calendar& calendar);

		short GetYear()const { return year; }
		short GetMonth()const { return month; }
		short GetDay()const { return day; }
		short GetHour()const { return hour; }
		short GetMinute()const { return minute; }
		bool IsLeapYear()const { return isLeapYear; }

		void SetYear(const short& newYear);
		void SetMonth(const short& newMonth);
		void SetDay(const short& newDay);
		void SetHour(const short& newHour);
		void SetMinute(const short& newMinute);

		void AddMinutes(const short& newMinute)
		{
			minute += newMinute;

			while (minute > 59)
			{
				minute -= 60;
				++hour;
			}

			while (hour > 23)
			{
				hour -= 24;
				++day;
			}

			while (day > Date::MonthMaxDays[isLeapYear][month])
			{
				day -= Date::MonthMaxDays[isLeapYear][month];
				++month;

				if (month == 13)
				{
					month = 1;
					++year;
					isLeapYear = Date::IsLeapYear(year);
				}
			}
		}
		void AddHours(const short& newHour)
		{
			hour += newHour;

			while (hour > 23)
			{
				hour -= 24;
				++day;
			}

			while (day > Date::MonthMaxDays[isLeapYear][month])
			{
				day -= Date::MonthMaxDays[isLeapYear][month];
				++month;

				if (month == 13)
				{
					month = 1;
					++year;
					isLeapYear = Date::IsLeapYear(year);
				}
			}
		}
		void AddDays(const short& newDay)
		{
			day += newDay;

			while (day > Date::MonthMaxDays[isLeapYear][month])
			{
				day -= Date::MonthMaxDays[isLeapYear][month];
				++month;

				if (month == 13)
				{
					month = 1;
					++year;
					isLeapYear = Date::IsLeapYear(year);
				}
			}
		}
		void AddMonths(const short& newMonth)
		{
			month += newMonth;

			while (month > 12)
			{
				month -= 12;
				++year;
				isLeapYear = Date::IsLeapYear(year);
			}

			if (day > Date::MonthMaxDays[isLeapYear][month])
				day = Date::MonthMaxDays[isLeapYear][month];
		}
		void AddYears(const short& newYear)
		{
			year += newYear;
			isLeapYear = Date::IsLeapYear(year);

			if (!isLeapYear && month == 2 && day == 29)
				day = 28;
		}

		void SubtractMinutes(const short& newMinutes)
		{
			minute -= newMinutes;

			while (minute < 0)
			{
				minute += 60;
				--hour;
			}

			while (hour < 0)
			{
				hour += 24;
				--day;
			}

			while (day <= 0)
			{
				--month;
				if (month == 0)
				{
					month = 12;
					--year;
					isLeapYear = Date::IsLeapYear(year);
				}

				day += Date::MonthMaxDays[isLeapYear][month];
			}
		}
		void SubtractHours(const short& newHour)
		{
			hour -= newHour;

			while (hour < 0)
			{
				hour += 24;
				--day;
			}

			while (day <= 0)
			{
				--month;
				if (month == 0)
				{
					month = 12;
					--year;
					isLeapYear = Date::IsLeapYear(year);
				}

				day += Date::MonthMaxDays[isLeapYear][month];
			}
		}
		void SubtractDays(const short& newDay)
		{
			day -= newDay;

			while (day <= 0)
			{
				--month;
				if (month == 0)
				{
					month = 12;
					--year;
					isLeapYear = Date::IsLeapYear(year);
				}

				day += Date::MonthMaxDays[isLeapYear][month];
			}
		}
		void SubtractMonths(const short& newMonth)
		{
			month -= newMonth;

			while (month <= 0)
			{
				month += 12;
				--year;
				isLeapYear = Date::IsLeapYear(year);
			}

			if (day > Date::MonthMaxDays[isLeapYear][month])
				day = Date::MonthMaxDays[isLeapYear][month];
		}
		void SubtractYears(const short& newYears)
		{
			year -= newYears;
			isLeapYear = Date::IsLeapYear(year);

			if (!isLeapYear && month == 2 && day == 29)
				day = 28;
		}
	};
}