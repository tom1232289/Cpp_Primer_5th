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
// 	HasPtr(const HasPtr &p):			// �������캯��
// 		ps(new string(*p.ps)),
// 		i(p.i)
// 	{ }
	HasPtr &operator=(const HasPtr &rhs);	// ������ֵ�����
	HasPtr &operator=(const string &rhs);	// ������string
	string &operator*();					// ������
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
	// TODO: �ڴ˴����� return ���
	string *newps = new string(*rhs.ps);	// ����ָ��ָ��Ķ���
	delete ps;								// ����ԭstring
	ps = newps;								// ָ����string
	i = rhs.i;								// ʹ�����õ�int��ֵ
	return *this;							// ����һ���˶��������
}

inline HasPtr & HasPtr::operator=(const string & rhs)
{
	// TODO: �ڴ˴����� return ���
	*ps = rhs;
	return *this;
}

inline string & HasPtr::operator*()
{
	// TODO: �ڴ˴����� return ���
	return *ps;
}



#endif	// !HAS_PTR_H