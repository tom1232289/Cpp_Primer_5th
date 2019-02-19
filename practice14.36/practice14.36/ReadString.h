#pragma once
#ifndef READSTRING_H
#define READSTRING_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ReadString
{
public:
	ReadString(istream &i = cin) :
		is(i) {	}
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

void testReadString()
{
	vector<string> sVec;
	ReadString rc;
	while (true) {
		string line = rc();
		if (!line.empty())
			sVec.push_back(line);
		else
			break;
	}
}

#endif	// !READSTRING_H