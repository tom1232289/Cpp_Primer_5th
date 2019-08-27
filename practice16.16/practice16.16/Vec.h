#pragma once
#ifndef VEC_H
#define VEC_H

#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;

template <typename T>
class Vec
{
public:
	Vec() = default;
	Vec(initializer_list<T> il);
	~Vec() { free(); }
	Vec(const Vec &vec);
	Vec & operator=(const Vec &rhs);

public:
	void push_back(const T &s);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	T *begin() const { return elements; }
	T *end() const { return first_free; }
	void reserve(size_t n)
	{
		if (capacity() < n)
			reallocate(n);
	}
	void resize(size_t n);
	void resize(size_t n, const T &s);

private:
	void check_n_alloc()
	{
		if (size() == capacity())
			reallocate();
	}
	void reallocate();
	void reallocate(size_t newcapacity);
	void free();
	pair<T*, T*> alloc_n_copy(const T *b, const T *e);

private:
	allocator<T> alloc;
	T *elements = nullptr;
	T *first_free = nullptr;
	T *cap = nullptr;
};

template <typename T>
Vec<T>::Vec(initializer_list<T> il)
{
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = newdata.second;
}

template <typename T>
Vec<T>::Vec(const Vec & vec)
{
	auto newdata = alloc_n_copy(vec.begin(), vec.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template <typename T>
Vec<T> & Vec<T>::operator=(const Vec & rhs)
{
	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}

template <typename T>
void Vec<T>::push_back(const T & s)
{
	check_n_alloc();
	alloc.construct(first_free++, s);
}

template <typename T>
void Vec<T>::resize(size_t n)
{
	if (size() < n) {
		while (size() < n)
			push_back(T());
	}
	else if (size() > n) {
		while (size() > n)
			alloc.destroy(--first_free);
	}
}

template <typename T>
void Vec<T>::resize(size_t n, const T & s)
{
	if (size() < n) {
		while (size() < n)
			push_back(s);
	}
}

template <typename T>
void Vec<T>::reallocate()
{
	auto newcapacity = size() ? size() * 2 : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i < size(); ++i)
		alloc.construct(dest++, move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

template <typename T>
void Vec<T>::reallocate(size_t newcapacity)
{
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = newdata + newcapacity;
}

template <typename T>
void Vec<T>::free()
{
	if (elements) {
		for_each(elements, first_free, [this](T &s) { alloc.destroy(&s); });
		alloc.deallocate(elements, cap - elements);
	}
}

template <typename T>
pair<T*, T*> Vec<T>::alloc_n_copy(const T * b, const T * e)
{
	auto newdata = alloc.allocate(e - b);
	return{ newdata,uninitialized_copy(b,e,newdata) };
}

#endif	// !VEC_H