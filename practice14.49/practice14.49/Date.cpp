#include "Date.h"
#include <sstream>

ostream & operator<<(ostream & os, const Date & data)
{
	const char seq = '\t';
	os << data.year << " " << data.month << " " << data.day;
	return os;
}

bool operator==(const Date & lhs, const Date & rhs)
{
	return lhs.year == rhs.year&&lhs.month == rhs.month&&lhs.day == rhs.day;
}

bool operator!=(const Date & lhs, const Date & rhs)
{
	return !(lhs == rhs);
}

bool operator<(const Date & lhs, const Date & rhs)
{
	return (lhs.year < rhs.year) || (lhs.year == rhs.year&&lhs.month < rhs.month) || (lhs.year == rhs.year&&lhs.month == rhs.month&&lhs.day < rhs.day);
}

bool operator<=(const Date & lhs, const Date & rhs)
{
	return (lhs < rhs) || (lhs == rhs);
}

bool operator>(const Date & lhs, const Date & rhs)
{
	return !(lhs <= rhs);
}

bool operator>=(const Date & lhs, const Date & rhs)
{
	return (lhs > rhs) || (lhs == rhs);
}

Date & Date::operator=(const string & date)
{
	istringstream in(date);
	char ch1, ch2;
	in >> year >> ch1 >> month >> ch2 >> day;
	if (!in || ch1 != '-' || ch2 != '-')
		throw invalid_argument("Bad date");
	if (month < 1 || month>12 || day < 1 || day>31)
		throw invalid_argument("Bad date");
	return *this;
}
