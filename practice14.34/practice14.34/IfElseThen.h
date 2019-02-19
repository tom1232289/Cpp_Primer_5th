#pragma once
#ifndef IFELSETHEN_H
#define IFELSETHEN_H

#include <iostream>

using namespace std;

class IfElseThen
{
public:
	IfElseThen(int v1, int v2, int v3) :
		val1(v1),
		val2(v2),
		val3(v3){	}
	bool operator()(int v1, int v2, int v3)
	{
		return v1 ? v2 : v3;
	}
private:
	int val1, val2, val3;
};

#endif	// !IFELSETHEN_H