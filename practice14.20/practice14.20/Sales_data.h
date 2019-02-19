#pragma once
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include<iostream>
#include<string>
using namespace std;

class Sales_data {
	friend istream & operator>>(istream &is, Sales_data &rhs);
	friend ostream & operator<<(ostream &os, const Sales_data &rhs);
	friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
public:
	Sales_data() = default;
	string isbn() { return bookNo; }
	friend istream & read(istream & is, Sales_data & item);
	friend ostream & print(ostream & os, const Sales_data & item);
	friend Sales_data add(const Sales_data & lhs, const Sales_data & rhs);
	Sales_data & combine(const Sales_data & rhs);
	double avg_price() const {
		if (units_sold)
			return revenue / units_sold;
		else
			return 0;
	}
public:
	Sales_data & operator+=(const Sales_data &rhs);
private:
	string bookNo;
	size_t	units_sold = 0;
	double revenue = 0.0;
};

inline istream & operator>>(istream & is, Sales_data & rhs)
{
	double price;
	is >> rhs.bookNo >> rhs.units_sold >> price;
	if (is)
		rhs.revenue = price * rhs.units_sold;
	else
		rhs = Sales_data();
	return is;
}

inline ostream & operator<<(ostream & os, const Sales_data & rhs)
{
	return print(os, rhs);
}

inline Sales_data operator+(const Sales_data & lhs, const Sales_data & rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}

inline istream & read(istream & is, Sales_data & item) {
	is >> item.bookNo >> item.units_sold >> item.revenue;
	return is;
}
inline ostream & print(ostream & os, const Sales_data & item) {
	os << item.bookNo << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

inline Sales_data & Sales_data::combine(const Sales_data & rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

inline Sales_data & Sales_data::operator+=(const Sales_data & rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

inline Sales_data add(const Sales_data & lhs, const Sales_data & rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

#endif	// !SALES_DATA_H
