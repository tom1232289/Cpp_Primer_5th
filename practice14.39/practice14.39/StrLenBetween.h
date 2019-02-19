#pragma once

#include <iostream>
#include <string>

using namespace std;

class StrLenBetween
{
public:
	StrLenBetween(size_t minl,size_t maxl):
		minLen(minl),
		maxLen(maxLen){	}
	bool operator()(const string &s)
	{
		return s.size() >= minLen && s.size() <= maxLen;
	}
private:
	size_t minLen;
	size_t maxLen;
};