#include "RE/Bethesda/Calendar.h"

#include "RE/Bethesda/Settings.h"
#include "RE/Bethesda/TESForms.h"

namespace RE
{
	using namespace literals;

	float Calendar::GetCurrentGameTime() const
	{
		return gameDaysPassed ? gameDaysPassed->value : 1.0F;
	}

	float Calendar::GetDay() const
	{
		return gameDay ? gameDay->value : 17.0F;
	}

	std::string Calendar::GetDayName() const
	{
		switch (GetDayOfWeek()) {
		case Calendar::Day::kSunday:
			return std::string("sDaySunday"_gs.value_or("Bad Day"));
		case Calendar::Day::kMonday:
			return std::string("sDayMonday"_gs.value_or("Bad Day"));
		case Calendar::Day::kTuesday:
			return std::string("sDayTuesday"_gs.value_or("Bad Day"));
		case Calendar::Day::kWednesday:
			return std::string("sDayWednesday"_gs.value_or("Bad Day"));
		case Calendar::Day::kThursday:
			return std::string("sDayThursday"_gs.value_or("Bad Day"));
		case Calendar::Day::kFriday:
			return std::string("sDayFriday"_gs.value_or("Bad Day"));
		case Calendar::Day::kSaturday:
			return std::string("sDaySaturday"_gs.value_or("Bad Day"));
		default:
			return "Bad Day";
		}
	}

	std::uint32_t Calendar::GetDayOfWeek() const
	{
		return static_cast<std::uint32_t>(GetDaysPassed()) % 7;
	}

	float Calendar::GetDaysPassed() const
	{
		return gameDaysPassed ? gameDaysPassed->value : 1.0F;
	}

	void Calendar::GetTimeDateString(char* a_dest, std::uint32_t a_max, bool a_showYear) const
	{
		using func_t = decltype(&Calendar::GetTimeDateString);
		REL::Relocation<func_t> func{ REL::ID(2228570) };
		return func(this, a_dest, a_max, a_showYear);
	}

	float Calendar::GetHour() const
	{
		return gameHour ? gameHour->value : 12.0F;
	}

	float Calendar::GetHoursPassed() const
	{
		return GetDaysPassed() * 24.0F;
	}

	std::uint32_t Calendar::GetMonth() const
	{
		return gameMonth ? static_cast<std::uint32_t>(gameMonth->value) : 7;
	}

	std::string Calendar::GetMonthName() const
	{
		switch (GetMonth()) {
		case Calendar::Month::kJanuary:
			return std::string("sMonthJanuary"_gs.value_or("Bad Month"));
		case Calendar::Month::kFebruary:
			return std::string("sMonthFebruary"_gs.value_or("Bad Month"));
		case Calendar::Month::kMarch:
			return std::string("sMonthMarch"_gs.value_or("Bad Month"));
		case Calendar::Month::kApril:
			return std::string("sMonthApril"_gs.value_or("Bad Month"));
		case Calendar::Month::kMay:
			return std::string("sMonthMay"_gs.value_or("Bad Month"));
		case Calendar::Month::kJune:
			return std::string("sMonthJune"_gs.value_or("Bad Month"));
		case Calendar::Month::kJuly:
			return std::string("sMonthJuly"_gs.value_or("Bad Month"));
		case Calendar::Month::kAugust:
			return std::string("sMonthAugust"_gs.value_or("Bad Month"));
		case Calendar::Month::kSeptember:
			return std::string("sMonthSeptember"_gs.value_or("Bad Month"));
		case Calendar::Month::kOctober:
			return std::string("sMonthOctober"_gs.value_or("Bad Month"));
		case Calendar::Month::kNovember:
			return std::string("sMonthNovember"_gs.value_or("Bad Month"));
		case Calendar::Month::kDecember:
			return std::string("sMonthDecember"_gs.value_or("Bad Month"));
		default:
			return "Bad Month";
		}
	}

	std::tm Calendar::GetTime() const
	{
		std::tm time;

		time.tm_sec = 0;
		time.tm_min = 0;
		time.tm_hour = static_cast<int>(GetHour());
		time.tm_mday = static_cast<int>(GetDay());
		time.tm_mon = static_cast<int>(GetMonth());
		time.tm_year = static_cast<int>(GetYear());
		time.tm_wday = static_cast<int>(GetDayOfWeek());

		time.tm_yday = time.tm_mday;
		for (int i = 0; i < time.tm_mon - 1; ++i) {
			time.tm_yday += DAYS_IN_MONTH[i];
		}

		time.tm_isdst = 0;

		return time;
	}

	float Calendar::GetTimescale() const
	{
		return timeScale->value;
	}

	std::uint32_t Calendar::GetYear() const
	{
		return gameYear ? static_cast<std::uint32_t>(gameYear->value) : 77;
	}
}
