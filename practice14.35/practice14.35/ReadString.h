#pragma once
#ifndef READSTRING_H
#define READSTRING_H

#include <iostream>
#include <string>

using namespace std;

class ReadString
{
public:
	ReadString(istream &i):
		is(i){	}
	string operator()()
	{
		string line;
		if (!getline(is, line))
			line = "";
		return line;
	}
private:
	istream &is;
};

#endif	// !READSTRING_H