#pragma once
#include <iostream>;
#include<map>;

namespace Chrono {
	enum class Month {jan,feb,mar,apr,may,jun,jul,aug,sep,okt,nov,dec};
	std::map<Month, int> days_in_months = { {Month::jan,31},{Month::feb,28},{Month::mar,31},
									{Month::apr,30},{Month::may,31} ,{Month::jun,30},
								{Month::jul,31},{Month::aug,31},{Month::okt,31},
								{Month::nov,31}, {Month::dec,31} };
	class Date
	{
	public:
		Date() = delete;
		Date(int d, Month m, int y);
		void show_date();
		void add_day();

	private:
		int year;
		Month month;
		int day;
	};
	class Ivalid_date {};
}
