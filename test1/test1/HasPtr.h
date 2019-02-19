#pragma once

#ifndef HAS_PTR_H
#define HAS_PTR_H

#include <iostream>
#include <string>

using namespace std;

class HasPtr {
public:
	// ���캯�������µ�string���µļ�����������������Ϊ1
	HasPtr(const string &s = string()) :
		ps(new string(s)),
		i(0),
		use(new size_t(1))
	{ }
	// �������캯�����������������ݳ�Ա��������������
	HasPtr(const HasPtr &p) :			// �������캯��
		ps(new string(*p.ps)),
		i(p.i),
		use(p.use)
	{
		++*use;
	}
	HasPtr &operator=(const HasPtr &rhs);	// ������ֵ�����
	HasPtr &operator=(const string &rhs);	// ������string
	string &operator*();					// ������
	~HasPtr();

private:
	string * ps;
	int i;
	size_t * use;	// ������¼�ж��ٸ�������*ps�ĳ�Ա
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
	// TODO: �ڴ˴����� return ���
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
	// TODO: �ڴ˴����� return ���
	*ps = rhs;
	return *this;
}

inline string & HasPtr::operator*()
{
	// TODO: �ڴ˴����� return ���
	return *ps;
}

#endif	// !HAS_PTR_H#pragma once
