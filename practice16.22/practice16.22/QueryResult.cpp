#include "QueryResult.h"

ostream & print(ostream & os, const QueryResult & qr)
{
	os << qr.sought << " occurs " << qr.size() << " times" << endl;
	for (auto num : *qr.lines)
		os << "(line " << num + 1 << "):" << *(qr.file->begin() + num) << endl;
	return os;
}