#pragma once
#ifndef INT_COMPARE_H
#define INT_COMPARE_H

#include <iostream>
#include <algorithm>

using namespace std;

class IntCompare
{
public:
	IntCompare(int val):
		value(val){	}
	bool operator()(int val)
	{
		return value == val;
	}
private:
	int value;
};

#endif // !INT_COMPARE_H