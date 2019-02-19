#include "StrBlob.h"

bool operator==(const StrBlob & lhs, const StrBlob & rhs)
{
	return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob & lhs, const StrBlob & rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrBlob & lhs, const StrBlob & rhs)
{
	return *lhs.data < *rhs.data;
}

bool operator<=(const StrBlob & lhs, const StrBlob & rhs)
{
	return *lhs.data <= *rhs.data;
}

bool operator>(const StrBlob & lhs, const StrBlob & rhs)
{
	return *lhs.data > *rhs.data;
}

bool operator>=(const StrBlob & lhs, const StrBlob & rhs)
{
	return *lhs.data >= *rhs.data;
}
