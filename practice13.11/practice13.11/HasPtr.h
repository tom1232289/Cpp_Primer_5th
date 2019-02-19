#pragma once

#include <iostream>

using namespace std;

class HasPtr {
public:
	HasPtr(const string &s = string()):
		ps(new string(s)),
		i(0)
	{ }
	HasPtr(const HasPtr&hp) {
		ps = new string(*hp.ps);
		i = hp.i;
	}
	HasPtr& operator=(const HasPtr& hp);
	~HasPtr(){
		if (ps != nullptr) {
			delete ps;
			ps = nullptr;
		}
	}
private:
	string * ps;
	int i;
};

HasPtr & HasPtr::operator=(const HasPtr & rhs)
{
	auto newps = new string(*rhs.ps);
	delete ps;
	ps = newps;
	i = rhs.i;
	return *this;
}
