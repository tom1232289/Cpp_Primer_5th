#include "Date.h"

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

