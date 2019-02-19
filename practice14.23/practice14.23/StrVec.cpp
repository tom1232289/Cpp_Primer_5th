#include "StrVec.h"
#include <algorithm>

StrVec::StrVec(initializer_list<string> il)
{
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = newdata.second;
}

StrVec::StrVec(const StrVec & svec)
{
	auto newdata = alloc_n_copy(svec.begin(), svec.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec & StrVec::operator=(const StrVec & rhs)
{
	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}

StrVec::StrVec(StrVec && svec) noexcept :
	elements(svec.elements),
	first_free(svec.first_free),
	cap(svec.cap)
{
	svec.elements = svec.first_free = svec.cap = nullptr;
}

StrVec & StrVec::operator=(StrVec && rhs) noexcept
{
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

// 因为是initializer_list，所以不用判断是否是"自赋值"
StrVec & StrVec::operator=(initializer_list<string> il)
{
	auto newdata = alloc_n_copy(il.begin(), il.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}

void StrVec::push_back(const string & s)
{
	check_n_alloc();
	alloc.construct(first_free++, s);
}

void StrVec::resize(size_t n)
{
	if (size() < n) {
		while (size() < n)
			push_back(string());
	}
	else if (size() > n) {
		while (size() > n)
			alloc.destroy(--first_free);
	}
}

void StrVec::resize(size_t n, const string & s)
{
	if (size() < n) {
		while (size() < n)
			push_back(s);
	}
}

void StrVec::reallocate()
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

void StrVec::reallocate(size_t newcapacity)
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

void StrVec::free()
{
	if (elements) {
		for_each(elements, first_free, [this](string &s) { alloc.destroy(&s); });
		alloc.deallocate(elements, cap - elements);
	}
}

pair<string*, string*> StrVec::alloc_n_copy(const string * b, const string * e)
{
	auto newdata = alloc.allocate(e - b);
	return { newdata,uninitialized_copy(b,e,newdata) };
}

bool operator==(const StrVec & lhs, const StrVec & rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	for (auto itr1 = lhs.begin(), itr2 = rhs.begin(); itr1 != lhs.end(); ++itr1, ++itr2) {
		if (*itr1 != *itr2)
			return false;
	}
	return true;
}

bool operator!=(const StrVec & lhs, const StrVec & rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrVec & lhs, const StrVec & rhs)
{
	auto itr1 = lhs.begin(), itr2 = rhs.begin();
	for (; itr1 != lhs.end(), itr2 != rhs.end(); ++itr1, ++itr2) {
		if (*itr1 < *itr2)
			return true;
		else if (*itr1 > *itr2)
			return false;
	}
	if (itr1 == lhs.end() && itr2 != lhs.end())
		return true;
	return false;
}

bool operator<=(const StrVec & lhs, const StrVec & rhs)
{
	auto itr1 = lhs.begin(), itr2 = rhs.begin();
	for (; itr1 != lhs.end(), itr2 != rhs.end(); ++itr1, ++itr2) {
		if (*itr1 < *itr2)
			return true;
		else if (*itr1 > *itr2)
			return false;
	}
	if (itr1 == lhs.end())
		return true;
	return false;
}

bool operator>(const StrVec & lhs, const StrVec & rhs)
{
	auto itr1 = lhs.begin(), itr2 = rhs.begin();
	for (; itr1 != lhs.end(), itr2 != rhs.end(); ++itr1, ++itr2) {
		if (*itr1 > *itr2)
			return true;
		else if (*itr1 < *itr2)
			return false;
	}
	if (itr1 != lhs.end() && itr2 == lhs.end())
		return true;
	return false;
}

bool operator>=(const StrVec & lhs, const StrVec & rhs)
{
	auto itr1 = lhs.begin(), itr2 = rhs.begin();
	for (; itr1 != lhs.end(), itr2 != rhs.end(); ++itr1, ++itr2) {
		if (*itr1 > *itr2)
			return true;
		else if (*itr1 < *itr2)
			return false;
	}
	if (itr2 == lhs.end())
		return true;
	return false;
}