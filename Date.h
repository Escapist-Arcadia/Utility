#pragma once

namespace Escapist
{
	class Date
	{
	private:
		short y;
		short m;
		short d;
		bool isLeapYear;

	public:
		static const short MonthMaxDays[2][13];

		Date();
		Date(const short& year, const short& month, const short& day);
		Date(const Date& date);

		static bool IsLeapYear(const short& year);

		unsigned short GetYear()const { return y; }
		unsigned short GetMonth()const { return m; }
		unsigned short GetDay()const { return d; }
		bool IsLeapYear()const { return isLeapYear; }

		void SetYear(const short& year);
		void SetMonth(const short& month);
		void SetDay(const short& day);

		static int Compare(const short& leftYear, const short& leftMonth, const short& leftDay,
			const short& rightYear, const short& rightMonth, const short& rightDay);
		static int Compare(const Date& left, const Date& right);
		int CompareTo(const short& year, const short& month, const short& day)const;
		int CompareTo(const Date& other)const;

		void AddDays(const short& days);
		void AddMonths(const short& months);
		void AddYears(const short& years);

		void SubtractDays(const short& days);
		void SubtractMonths(const short& months);
		void SubtractYears(const short& years);
	};
}