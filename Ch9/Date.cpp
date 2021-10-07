//#include "Date.h"
//
//Chrono::Date::Date(int d, Month m, int y) : day(d), month(m), year(y) 
//{
//	if (day < 0 || day>31 || year < 0) {
//		throw Chrono::Ivalid_date();
//	}
//}
//
//
//void Chrono::Date::show_date()
//{
//	std::cout <<"Day :" << day << " Month: " << (int) month << " Year: " << year;
//}
//
//void Chrono::Date::add_day()
//{
//	int max_day = days_in_months.at(month);
//	if (day == max_day) {
//		day = 1;
//		if (month == Month::dec) year++;
//		month = (Month)(((int)(month) + 1))%12)
//	}
//}
