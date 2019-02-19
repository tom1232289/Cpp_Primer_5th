#pragma once
#ifndef STRVEC_H
#define STRVEC_H

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class StrVec
{
	friend bool operator==(const StrVec &lhs, const StrVec &rhs);
	friend bool operator!=(const StrVec &lhs, const StrVec &rhs);
	friend bool operator<(const StrVec &lhs, const StrVec &rhs);
	friend bool operator<=(const StrVec &lhs, const StrVec &rhs);
	friend bool operator>(const StrVec &lhs, const StrVec &rhs);
	friend bool operator>=(const StrVec &lhs, const StrVec &rhs);
public:
	StrVec() = default;
	StrVec(initializer_list<string> il);
	~StrVec() { free(); }
	StrVec(const StrVec &svec);
	StrVec & operator=(const StrVec &rhs);
	StrVec(StrVec &&svec) noexcept;
	StrVec & operator=(StrVec &&rhs) noexcept;
	StrVec & operator=(initializer_list<string> il);
public:
	void push_back(const string &s);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	string *begin() const { return elements; }
	string *end() const { return first_free; }
	void reserve(size_t n)
	{
		if (capacity() < n)
			reallocate(n);
	}
	void resize(size_t n);
	void resize(size_t n, const string &s);
private:
	void check_n_alloc()
	{
		if (size() == capacity())
			reallocate();
	}
	void reallocate();
	void reallocate(size_t newcapacity);
	void free();
	pair<string*,string*> alloc_n_copy(const string *b,const string *e);
private:
	allocator<string> alloc;
	string *elements = nullptr;
	string *first_free = nullptr;
	string *cap = nullptr;
};

#endif	// !STRVEC_H