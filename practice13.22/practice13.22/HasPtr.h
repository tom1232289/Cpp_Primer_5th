#pragma once

#ifndef HAS_PTR_H
#define HAS_PTR_H

#include <iostream>
#include <string>

using namespace std;

class HasPtr {
public:
	HasPtr(const string &s = string()):	
		ps(new string(s)),
		i(0)
	{ }
// 	HasPtr(const HasPtr &p):			// 拷贝构造函数
// 		ps(new string(*p.ps)),
// 		i(p.i)
// 	{ }
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
	// TODO: 在此处插入 return 语句
	string *newps = new string(*rhs.ps);	// 拷贝指针指向的对象
	delete ps;								// 销毁原string
	ps = newps;								// 指向新string
	i = rhs.i;								// 使用内置的int赋值
	return *this;							// 返回一个此对象的引用
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



#endif	// !HAS_PTR_H