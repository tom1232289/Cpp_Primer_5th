#pragma once
#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <memory>

using namespace std;

class String
{
	friend String operator+(const String &lhs, const String &rhs);
	friend String add(const String &lhs, const String &rhs);
	friend void swap(String &lhs, String &rhs);
	friend ostream & operator<<(ostream &os, const String &rhs);
public:
	String() = default;
	~String() { free(); }
	String(const String &s);
	String & operator=(const String &rhs);
	String(const char *cp);
	String(size_t n, char c);
	String(initializer_list<char> il);
	String & operator=(const char *cp);
	String & operator=(char c);
	String(String &&s) noexcept;
	String & operator=(String &&rhs) noexcept;

public:
	const char *begin() { return p; }
	const char *begin() const { return p; }
	const char *end() { return p + sz; }
	const char *end() const { return p + sz; }
	size_t size() const { return sz; }

private:
	void free()
	{
		if (p)
			alloc.deallocate(p, sz);
	}

private:
	static allocator<char> alloc;
	size_t sz = 0;
	char *p = nullptr;
};

#endif	// !STRING_H