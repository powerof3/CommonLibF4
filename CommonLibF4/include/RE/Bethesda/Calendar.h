#pragma once

#include "RE/Bethesda/BSTSingleton.h"

namespace RE
{
	class TESGlobal;

	class Calendar :
		public BSTSingletonSDM<Calendar>
	{
	public:
		static constexpr std::uint8_t DAYS_IN_MONTH[] = {
			31,  // January
			28,  // February
			31,  // March
			30,  // April
			31,  // May
			30,  // June
			31,  // July
			31,  // August
			30,  // Sepetember
			31,  // October
			30,  // November
			31   // December
		};

		struct Days
		{
			enum Day
			{
				kSunday,
				kMonday,
				kTuesday,
				kWednesday,
				kThursday,
				kFriday,
				kSaturday,
				kTotal
			};
		};
		using Day = Days::Day;

		struct Months
		{
			enum Month
			{
				kJanuary,
				kFebruary,
				kMarch,
				kApril,
				kMay,
				kJune,
				kJuly,
				kAugust,
				kSeptember,
				kOctober,
				kNovember,
				kDecember,
				kTotal
			};
		};
		using Month = Months::Month;

		[[nodiscard]] static Calendar* GetSingleton()
		{
			static REL::Relocation<Calendar**> singleton{ REL::ID(4796378) };
			return *singleton;
		}

		[[nodiscard]] float         GetCurrentGameTime() const;
		[[nodiscard]] float         GetDay() const;
		[[nodiscard]] std::string   GetDayName() const;
		[[nodiscard]] std::uint32_t GetDayOfWeek() const;
		[[nodiscard]] float         GetDaysPassed() const;
		void                        GetTimeDateString(char* a_dest, std::uint32_t a_max, bool a_showYear) const;
		[[nodiscard]] float         GetHour() const;
		[[nodiscard]] float         GetHoursPassed() const;
		[[nodiscard]] std::uint32_t GetMonth() const;
		[[nodiscard]] std::string   GetMonthName() const;
		[[nodiscard]] std::tm       GetTime() const;
		[[nodiscard]] float         GetTimescale() const;
		[[nodiscard]] std::uint32_t GetYear() const;

		// members
		TESGlobal*    gameYear;         // 08
		TESGlobal*    gameMonth;        // 10
		TESGlobal*    gameDay;          // 18
		TESGlobal*    gameHour;         // 20
		TESGlobal*    gameDaysPassed;   // 28
		TESGlobal*    timeScale;        // 30
		std::uint32_t midnightsPassed;  // 38
		float         rawDaysPassed;    // 3C
	};
	static_assert(sizeof(Calendar) == 0x40);
}
