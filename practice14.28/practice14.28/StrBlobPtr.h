#pragma once
#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include "StrBlob.h"

using namespace std;

// 当试图访问一个不存在的元素时，StrBlobPtr抛出一个异常
class StrBlobPtr {
	friend bool eq(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend StrBlobPtr operator+(const StrBlobPtr &lhs, int n);
	friend StrBlobPtr operator-(const StrBlobPtr &lhs, int n);
public:
	StrBlobPtr() :curr(0) { }
	StrBlobPtr(StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) { }
	StrBlobPtr(const StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) { }
	string & operator[](size_t n) { return (*wptr.lock())[n]; }
	const string & operator[](size_t n) const { return (*wptr.lock())[n]; }
	StrBlobPtr & operator++();
	StrBlobPtr & operator--();
	StrBlobPtr & operator++(int);
	StrBlobPtr & operator--(int);
public:
	string &deref() const;
	string &deref(int off) const;
	StrBlobPtr& incr();				// 前缀递增
	StrBlobPtr& decr();				// 前缀递减
private:
	// 若检查成功，check返回一个指向vector的shared_ptr
	shared_ptr<vector<string>> check(size_t, const string&) const;

	// 保存一个weak_ptr,意味着底层vector可能会被销毁
	weak_ptr<vector<string>> wptr;
	size_t curr;					// 在数组中的当前位置
};

inline shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const {
	auto ret = wptr.lock();			// vector还存在吗？
	if (!ret) {
		throw runtime_error("unbound StrBlobStr");
	}
	if (i >= ret->size()) {
		throw out_of_range(msg);
	}
	return ret;						// 否则，返回指向vector的shared_ptr
}

inline StrBlobPtr & StrBlobPtr::operator++()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

inline StrBlobPtr & StrBlobPtr::operator--()
{
	--curr;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}

inline StrBlobPtr & StrBlobPtr::operator++(int)
{
	StrBlobPtr ret = *this;
	++(*this);
	return ret;
}

inline StrBlobPtr & StrBlobPtr::operator--(int)
{
	StrBlobPtr ret = *this;
	--(*this);
	return ret;
}

inline string & StrBlobPtr::deref() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];				// (*p)是对象所指向的vector
}

inline string & StrBlobPtr::deref(int off) const {
	auto p = check(curr + off, "dereference past end");
	return (*p)[curr + off];		// (*p)是对象所指向的vector
}

// 前缀递增：返回递增后的对象的引用
inline StrBlobPtr & StrBlobPtr::incr() {
	// 如果curr已经指向容器的尾后位置，就不能递增它
	check(curr, "increment past end of StrBlobPtr");
	++curr;							// 推进当前位置
	return *this;
}

// 前缀递减：返回递减后的对象的引用
inline StrBlobPtr & StrBlobPtr::decr() {
	// 如果curr已经为0，递减它就会产生一个非法下标
	--curr;							// 递减当前位置
	check(-1, "decrement past begin of StrBlobPtr");
	return *this;
}

// StrBlob的begin和end成员的定义
inline StrBlobPtr StrBlob::begin() {
	return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end() {
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}

// const版本
inline StrBlobPtr StrBlob::begin() const {
	return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end() const {
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}

// StrBlobPtr的比较操作
inline bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	// 若底层的vector是同一个
	if (l == r) {
		// 则两个指针都是空，或者指向相同元素时，它们相等
		return (!r || lhs.curr == rhs.curr);
	}
	else {
		return false;			// 若指向不同vector,则不可能相等
	}
}

inline bool operator==(const StrBlobPtr & lhs, const StrBlobPtr & rhs)
{
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	if (l == r)
		return (!r) || lhs.curr == rhs.curr;
	else
		return false;
}

inline bool operator!=(const StrBlobPtr & lhs, const StrBlobPtr & rhs)
{
	return !(lhs == rhs);
}

inline bool operator<(const StrBlobPtr & lhs, const StrBlobPtr & rhs)
{
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	if (l == r) {
		if (!r)
			return false;
		return (lhs.curr < rhs.curr);
	}
	else
		return false;
}

inline bool operator<=(const StrBlobPtr & lhs, const StrBlobPtr & rhs)
{
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	if (l == r) {
		return (!r) || (lhs.curr <= rhs.curr);
	}
	else
		return false;
}

inline bool operator>(const StrBlobPtr & lhs, const StrBlobPtr & rhs)
{
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	if (l == r) {
		if (!r)
			return false;
		return (lhs.curr > rhs.curr);
	}
	else
		return false;
}

inline bool operator>=(const StrBlobPtr & lhs, const StrBlobPtr & rhs)
{
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	if (l == r) {
		return (!r) || (lhs.curr >= rhs.curr);
	}
	else
		return false;
}

inline StrBlobPtr operator+(const StrBlobPtr & lhs, int n)
{
	auto ret = lhs;
	ret.curr += n;
	return ret;
}

inline StrBlobPtr operator-(const StrBlobPtr & lhs, int n)
{
	auto ret = lhs;
	ret.curr -= n;
	return ret;
}

inline bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return !eq(lhs, rhs);
}

#endif // !STRBLOBPTR_H
