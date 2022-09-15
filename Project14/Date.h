#pragma once
class Date
{
	int day;
	int month;
	int year;
public:
	Date();
	Date(int d, int m, int y);
	void InputDate();
	void PrintDate()const;
	void SetDay(int SetDay);
	int GetDay()const;
	void SetMonth(int SetMonth);
	int GetMonth()const;
	void SetYear(int SetYear);
	int GetYear()const;
	Date operator+=(int a);
	Date operator+(int a);
	Date operator-=(int a);
	Date operator-(int a);
	Date operator-(const Date& obj);
	Date operator++(int); 
	Date& operator++();
	Date operator--(int);
	Date& operator--();
	bool operator<(const Date& obj);
	bool operator>(const Date& obj);
	bool operator<=(const Date& obj);
	bool operator>=(const Date& obj);
	bool operator==(const Date& obj);
	bool operator!=(const Date& obj);
	int DayQuantityCheck(int month, int year); //функция для сокращения кода в if-statement, хранит кол-во дней в месяцах
};

