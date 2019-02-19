#pragma once

#ifndef HAS_PTR_H
#define HAS_PTR_H

#include <iostream>
#include <string>

using namespace std;

class HasPtr {
public:
	friend void swap(HasPtr & lhs, HasPtr & rhs);

public:
	HasPtr(const string &s = string()) :
		ps(new string(s)),
		i(0)
	{ }
	HasPtr(const HasPtr &p) :				// 拷贝构造函数
		ps(new string(*p.ps)),
		i(p.i)
	{ }
	HasPtr &operator=(const HasPtr &rhs);	// 拷贝赋值运算符
	HasPtr &operator=(const string &rhs);	// 赋予新string
	string &operator*();					// 解引用
	~HasPtr();

private:
	string * ps;
	int i;
};

HasPtr::~HasPtr()
{
	delete ps;
}

inline HasPtr & HasPtr::operator=(const HasPtr & rhs)
{
	string *newps = new string(*rhs.ps);	// 拷贝指针指向的对象
	delete ps;								// 销毁原string
	ps = newps;								// 指向新string
	i = rhs.i;								// 使用内置的int赋值
	return *this;							// 返回一个此对象的引用
}

inline HasPtr & HasPtr::operator=(const string & rhs)
{
	*ps = rhs;
	return *this;
}

inline string & HasPtr::operator*()
{
	return *ps;
}

inline void swap(HasPtr & lhs, HasPtr & rhs)
{
	cout << "交换" << *lhs.ps << "和" << *rhs.ps << endl;
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

#endif	// !HAS_PTR_H