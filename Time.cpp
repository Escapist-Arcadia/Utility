#include<Windows.h>
#include"Time.h"

namespace Escapist
{
	Time::Time()
	{
		SYSTEMTIME time;
		::GetSystemTime(&time);
		h = time.wHour;
		m = time.wMinute;
	}
	Time::Time(const short& hour, const short& minute)
	{
		if (hour >= 1 && hour <= 23)
			h = hour;

		if (minute >= 0 && minute <= 59)
			m = minute;
	}
	Time::Time(const Time& time) :h(time.h), m(time.m) {}

	void Time::SetHour(const short& hour)
	{
		if (hour >= 0 && hour <= 23)
			h = hour;
	}
	void Time::SetMinute(const short& mintue)
	{
		if (mintue >= 0 && mintue <= 59)
			m = mintue;
	}

	int Time::Compare(const short& leftHour, const short& leftMinute, const short& rightHour, const short& rightMinute)
	{
		if (leftHour == rightHour)
			if (leftMinute == rightMinute)
				return 0;
			else
				if (leftMinute < rightMinute)
					return 1;
				else
					return -1;
		else
			if (leftHour < rightHour)
				return 1;
			else
				return -1;
	}
	int Time::Compare(const Time& left, const Time& right) { return Time::Compare(left.h, left.m, right.h, right.m); }
	int Time::CompareTo(const short& hour, const short& minute)const { return Time::Compare(h, m, hour, minute); }
	int Time::CompareTo(const Time& other)const { return Time::Compare(h, m, other.h, other.m); }

	void Time::AddHours(const short& hours)
	{
		h += hours;
		if (h > 23)
			h = 23, m = 59;
	}
	void Time::AddMinutes(const short& minutes)
	{
		m += minutes;
		while (m >= 60)
		{
			m -= 60;
			++h;
		}

		if (h > 23)
			h = 23, m = 59;
	}

	void Time::SubtractHours(const short& hours)
	{
		h -= hours;
		if (h < 0)
			h = 0, m = 0;
	}
	void Time::SubtractMinutes(const short& minutes)
	{
		m -= minutes;
		while (m < 0)
		{
			m += 60;
			--h;
		}

		if (h < 0)
			h = 0, m = 0;
	}
}