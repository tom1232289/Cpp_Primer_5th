#pragma once
#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date
{
	friend ostream & operator<<(ostream &os, const Date &data);
public:
	Date() = default;
	Date(int y, int m, int d) :
		year(y),
		month(m),
		day(d)
	{	}
private:
	int year, month, day;
};

#endif	// !DATE_H