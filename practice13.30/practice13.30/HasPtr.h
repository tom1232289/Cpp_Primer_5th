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
	HasPtr(const HasPtr &p) :				// �������캯��
		ps(new string(*p.ps)),
		i(p.i)
	{ }
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
	string *newps = new string(*rhs.ps);	// ����ָ��ָ��Ķ���
	delete ps;								// ����ԭstring
	ps = newps;								// ָ����string
	i = rhs.i;								// ʹ�����õ�int��ֵ
	return *this;							// ����һ���˶��������
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
	cout << "����" << *lhs.ps << "��" << *rhs.ps << endl;
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

#endif	// !HAS_PTR_H