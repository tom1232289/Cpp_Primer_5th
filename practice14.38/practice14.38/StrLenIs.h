#pragma once
#ifndef STRLENIS_H
#define STRLENIS_H

#include <iostream>
#include <string>

using namespace std;

class StrLenIs
{
public:
	StrLenIs(size_t sz) :
		size(sz) {	}
	bool operator()(const string &s)
	{
		return s.size() == size;
	}
private:
	size_t size;
};

#endif	// !STRLENIS_H