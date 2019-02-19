#include "Date.h"

ostream & operator<<(ostream & os, const Date & data)
{
	const char seq = '\t';
	os << data.year << " " << data.month << " " << data.day;
	return os;
}

