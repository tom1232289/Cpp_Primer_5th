#pragma once

class StrNotShorterThan
{
public:
	StrNotShorterThan(size_t minl):
		minLen(minl){	}
	bool operator()(const string &s)
	{
		return s.size() >= minLen;
	}
private:
	size_t minLen;
};