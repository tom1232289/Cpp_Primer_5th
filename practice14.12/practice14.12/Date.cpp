#include "Date.h"

ostream & operator<<(ostream & os, const Date & data)
{
	const char seq = '\t';
	os << data.year << " " << data.month << " " << data.day;
	return os;
}

istream & operator>>(istream & is, Date & data)
{
	is >> data.year >> data.month >> data.day;
	if (!is)
		data = Date();
	return is;
}

