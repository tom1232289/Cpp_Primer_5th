#pragma once
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <vector>

using namespace std;

class Date
{
	friend ostream & operator<<(ostream &os, const Date &data);
	friend bool operator==(const Date &lhs, const Date &rhs);
	friend bool operator!=(const Date &lhs, const Date &rhs);
	friend bool operator<(const Date &lhs, const Date &rhs);
	friend bool operator<=(const Date &lhs, const Date &rhs);
	friend bool operator>(const Date &lhs, const Date &rhs);
	friend bool operator>=(const Date &lhs, const Date &rhs);
public:
	Date() = default;
	Date(int y, int m, int d) :
		year(y),
		month(m),
		day(d)
	{	}
	Date & operator=(const string &date);
	explicit operator bool()
	{
		vector<vector<int>> days_per_month = {
			{31,28,31,30,31,30,31,31,30,31,30,31},
			{31,29,31,30,31,30,31,31,30,31,30,31}
		};
		return month >= 1 && month <= 12 && day >= 1 && day <= days_per_month[isLeapYear() ? 1 : 0][month - 1];
	}
public:
	bool isLeapYear()
	{
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}
private:
	int year, month, day;
};

#endif	// !DATE_H