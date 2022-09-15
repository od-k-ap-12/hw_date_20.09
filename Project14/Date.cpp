#include "Date.h"
#include <iostream>
using namespace std;
Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
	if (day > this->DayQuantityCheck(m, y)) {
		//invalid date
		day = 0;
		month = 0;
		year = 0;
	}
}

void Date::InputDate()
{
	cout << "enter day: ";
	cin >> day;
	cout << "enter month: ";
	cin >> month;
	cout << "enter year: ";
	cin >> year;
	if (day>this->DayQuantityCheck(month,year)&&year<1) {
		//invalid date
		day = 0;
		month = 0;
		year = 0;
	}
}
int Date::DayQuantityCheck(int month,int year)
{
	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int d = days[month];
	if (month == 2 && year%4==0)
	{
		d += 1;
	}
	return d;
}
void Date::PrintDate()const
{
	cout << "date: " << day << "." << month << "." << year << endl;
}

void Date::SetDay(int SetDay)
{
	if (SetDay > this->DayQuantityCheck(month, year)) {
		cout << "Error";
	}
	else {
		day = SetDay;
	}
}

int Date::GetDay()const
{
	return day;
}

void Date::SetMonth(int SetMonth)
{
	if ((SetMonth > 12||SetMonth<1)||(day > this->DayQuantityCheck(SetMonth, year))) {
		cout << "Error"<<endl;
	}
	else {
		month = SetMonth;
	}
}

int Date::GetMonth()const
{
	return month;
}

void Date::SetYear(int SetYear)
{
	if ((year < 1) || (day > this->DayQuantityCheck(month, SetYear))) {
		cout << "Error" << endl;
	}
	else {
		year = SetYear;
	}
}

int Date::GetYear()const
{
	return year;
}

Date Date::operator+=(int a)
{
	if (day + a > DayQuantityCheck(month, year)) {
		a -= DayQuantityCheck(month, year) - day;
		day = 1;
		if (month == 12) {
			year++;
			month = 1;
		}
		else {
			month++;
		}
		while (a> DayQuantityCheck(month, year)) {
			day = DayQuantityCheck(month, year);
			a -= DayQuantityCheck(month, year);
			if (month == 12) {
				year++;
				month = 1;
			}
			else {
				month++;
			}
		}
		day = a;
		return *this;
	}
	else {
		day += a;
		return *this;
	}
}

Date Date::operator+(int a)
{
	Date rez(this->day, this->month, this->year);
	if (rez.day + a > DayQuantityCheck(rez.month, rez.year)) {
		a -= DayQuantityCheck(rez.month, rez.year) - rez.day;
		rez.day = 1;
		if (rez.month == 12) {
			rez.year++;
			rez.month = 1;
		}
		else {
			rez.month++;
		}
		while (a > DayQuantityCheck(rez.month, rez.year)) {
			rez.day = DayQuantityCheck(rez.month, rez.year);
			a -= DayQuantityCheck(rez.month, rez.year);
			if (rez.month == 12) {
				rez.year++;
				rez.month = 1;
			}
			else {
				rez.month++;
			}
		}
		rez.day = a;
		rez.PrintDate(); 
		return rez;
	}
	else {
		rez.day += a;
		rez.PrintDate();
		return rez;
	}
}

Date Date::operator-(int a)
{
	Date rez(this->day, this->month, this->year);
	if (rez.day - a < 1) {
		rez.day = 1;
		if (rez.month == 1) {
			rez.year--;
			rez.month = 12;
		}
		else {
			rez.month--;
		}
		a -= rez.day;
		while (a > DayQuantityCheck(rez.month, rez.year)) {
			rez.day = 1;
			a -= DayQuantityCheck(rez.month, rez.year);
			if (rez.month == 1) {
				rez.year--;
				rez.month = 12;
			}
			else {
				rez.month--;
			}
		}
		rez.month--;
		rez.day = DayQuantityCheck(rez.month, rez.year) - a;
		rez.PrintDate();
		return rez;
	}
	else {
		rez.day -= a;
		rez.PrintDate();
		return rez;
	}
}

Date Date::operator-=(int a)
{
	if (day - a < 1) {
		day = 1;
		if (month == 1) {
			year--;
			month = 12;
		}
		else {
			month--;
		}
		a -=day;
		while (a > DayQuantityCheck(month, year)) {
			day = 1;
			a -= DayQuantityCheck(month, year);
			if (month == 1) {
				year--;
				month = 12;
			}
			else {
				month--;
			}
		}
		month--;
		day = DayQuantityCheck(month, year)-a;
		return *this;
	}
	else {
		day -= a;
		return *this;
	}
}

Date Date::operator-(const Date& obj)
{
	if (day - obj.day <1) {
		if (month == 1) {
			year--;
			month = 12;
		}
		else {
			month--;
		}
		day = DayQuantityCheck(month, year) + (day - obj.day);
	}
	else {
		day -= obj.day;
	}
	if (month - obj.month < 1) {
		year--;
		month = 12+(month-obj.month);
		cout << month << endl;
	}
	else {
		month--;
	}
	year -= obj.year;
	return *this;
}

Date Date::operator++(int)
{
	Date temp(*this);
	day++;
	if (day > DayQuantityCheck(month, year)) {
		month++; day = 1;
		if (month > 12) {
			year++; 
			month = 1;
		}
	}
	return temp;
}

Date& Date::operator++()
{
	day++;
	if (day > DayQuantityCheck(month, year)) {
		month++; 
		day = 1;
		if (month > 12) {
			year++; 
			month = 1;
		}
	}
	return *this;
}

Date Date::operator--(int)
{
	Date temp(*this);
	day--;
	if (day < 1) {
		month--;
		day = DayQuantityCheck(month, year);
		if (month < 1) {
			year--;
			month = 12;
		}
	}
	return temp;
}

Date& Date::operator--()
{
	day--;
	if (day < 1) {
		month--;
		day = DayQuantityCheck(month, year);
		if (month < 1) {
			year--;
			month = 12;
		}
	}
	return *this;
}

bool Date::operator<(const Date& obj)
{
	if (year < obj.year) {
		return true;
	}
	else if (year == obj.year) {
		if (month < obj.month) {
			return true;
		}
		else if (month == obj.month) {
			if (day < obj.day) {
				return true;
			}
			else {
				return false;
			}
		
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool Date::operator>(const Date& obj)
{
	if (year > obj.year) {
		return true;
	}
	else if (year == obj.year) {
		if (month > obj.month) {
			return true;
		}
		else if (month == obj.month) {
			if (day > obj.day) {
				return true;
			}
			else {
				return false;
			}

		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool Date::operator<=(const Date& obj)
{
	if (year < obj.year) {
		return true;
	}
	else if (year == obj.year) {
		if (month < obj.month) {
			return true;
		}
		else if (month == obj.month) {
			if (day < obj.day) {
				return true;
			}
			else if (day == obj.day) {
				return true;
			}
			else {
				return false;
			}

		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool Date::operator>=(const Date& obj)
{
	if (year > obj.year) {
		return true;
	}
	else if (year == obj.year) {
		if (month > obj.month) {
			return true;
		}
		else if (month == obj.month) {
			if (day > obj.day) {
				return true;
			}
			else if (day == obj.day) {
				return true;
			}
			else {
				return false;
			}

		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool Date::operator==(const Date& obj)
{
	if (year != obj.year) {
		return false;
	}
	else {
		if (month != obj.month) {
			return false;
		}
		else {
			if (day != obj.day) {
				return false;
			}
			else {
				return true;
			}
		}
	}
}

bool Date::operator!=(const Date& obj)
{
	if (year != obj.year) {
		return true;
	}
	else {
		if (month != obj.month) {
			return true;
		}
		else {
			if (day != obj.day) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}
