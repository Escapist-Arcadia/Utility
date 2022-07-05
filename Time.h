#pragma once

namespace Escapist
{
	class Time
	{
	private:
		short h;
		short m;

	public:
		Time();
		Time(const short& hour, const short& minute);
		Time(const Time& time);

		short GetHour()const { return h; }
		short GetMinute()const { return m; }

		void SetHour(const short& hour);
		void SetMinute(const short& mintue);

		static int Compare(const short& leftHour, const short& leftMinute, const short& rightHour, const short& rightMinute);
		static int Compare(const Time& left, const Time& right);
		int CompareTo(const short& hour, const short& minute)const;
		int CompareTo(const Time& other)const;

		void AddHours(const short& hours);
		void AddMinutes(const short& minutes);

		void SubtractHours(const short& hours);
		void SubtractMinutes(const short& minutes);
	};
}