#pragma once

#ifndef HAS_PTR_H
#define HAS_PTR_H

#include <iostream>
#include <string>

using namespace std;

class HasPtr {
public:
	// 构造函数分配新的string和新的计数器，将计数器置为1
	HasPtr(const string &s = string()) :
		ps(new string(s)),
		i(0),
		use(new size_t(1))
	{ }
	// 拷贝构造函数拷贝所有三个数据成员，并递增计数器
	HasPtr(const HasPtr &p) :			// 拷贝构造函数
		ps(new string(*p.ps)),
		i(p.i),
		use(p.use)
	{
		++*use;
	}
	HasPtr &operator=(const HasPtr &rhs);	// 拷贝赋值运算符
	HasPtr &operator=(const string &rhs);	// 赋予新string
	string &operator*();					// 解引用
	~HasPtr();

private:
	string * ps;
	int i;
	size_t * use;	// 用来记录有多少个对象共享*ps的成员
};

HasPtr::~HasPtr()
{
	if (--*use == 0) {
		delete ps;
		delete use;
	}
}

inline HasPtr & HasPtr::operator=(const HasPtr & rhs)
{
	// TODO: 在此处插入 return 语句
	++*rhs.use;
	if (--*use == 0) {
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}

inline HasPtr & HasPtr::operator=(const string & rhs)
{
	// TODO: 在此处插入 return 语句
	*ps = rhs;
	return *this;
}

inline string & HasPtr::operator*()
{
	// TODO: 在此处插入 return 语句
	return *ps;
}

#endif	// !HAS_PTR_H#pragma once
