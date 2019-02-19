#pragma once

#ifndef HAS_PTR_H
#define HAS_PTR_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class HasPtr
{
public:
	friend void swap(HasPtr &lhs, HasPtr &rhs);
public:
	HasPtr(const string &s = string()) :
		ps(new string(s)),
		i(0)
	{	}
	HasPtr(const HasPtr &hp) :
		ps(new string(*hp.ps)),
		i(hp.i)
	{	}
	~HasPtr();
	HasPtr &operator=(const HasPtr &rhs);
	HasPtr &operator=(const string& rhs);
	bool operator<(const HasPtr &rhs);

public:
	string getString();

private:
	string *ps;
	int i;
};

inline HasPtr::~HasPtr()
{
	delete ps;
}

inline HasPtr & HasPtr::operator=(const HasPtr & rhs)
{
	auto new_ps = new string(*rhs.ps);
	delete ps;
	ps = new_ps;
	i = rhs.i;
	return *this;
}

inline HasPtr & HasPtr::operator=(const string & rhs)
{
	*ps = rhs;
	return *this;
}

inline string HasPtr::getString()
{
	return *ps;
}

inline void swap(HasPtr & lhs, HasPtr & rhs)
{
	cout << "½»»»" << *lhs.ps << "ºÍ" << *rhs.ps << endl;
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

inline bool HasPtr::operator<(const HasPtr & rhs)
{
	return *ps < *rhs.ps;
}

#endif	// !endif