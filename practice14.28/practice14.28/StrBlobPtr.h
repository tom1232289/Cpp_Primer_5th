#pragma once
#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include "StrBlob.h"

using namespace std;

// ����ͼ����һ�������ڵ�Ԫ��ʱ��StrBlobPtr�׳�һ���쳣
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
	StrBlobPtr& incr();				// ǰ׺����
	StrBlobPtr& decr();				// ǰ׺�ݼ�
private:
	// �����ɹ���check����һ��ָ��vector��shared_ptr
	shared_ptr<vector<string>> check(size_t, const string&) const;

	// ����һ��weak_ptr,��ζ�ŵײ�vector���ܻᱻ����
	weak_ptr<vector<string>> wptr;
	size_t curr;					// �������еĵ�ǰλ��
};

inline shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const {
	auto ret = wptr.lock();			// vector��������
	if (!ret) {
		throw runtime_error("unbound StrBlobStr");
	}
	if (i >= ret->size()) {
		throw out_of_range(msg);
	}
	return ret;						// ���򣬷���ָ��vector��shared_ptr
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
	return (*p)[curr];				// (*p)�Ƕ�����ָ���vector
}

inline string & StrBlobPtr::deref(int off) const {
	auto p = check(curr + off, "dereference past end");
	return (*p)[curr + off];		// (*p)�Ƕ�����ָ���vector
}

// ǰ׺���������ص�����Ķ��������
inline StrBlobPtr & StrBlobPtr::incr() {
	// ���curr�Ѿ�ָ��������β��λ�ã��Ͳ��ܵ�����
	check(curr, "increment past end of StrBlobPtr");
	++curr;							// �ƽ���ǰλ��
	return *this;
}

// ǰ׺�ݼ������صݼ���Ķ��������
inline StrBlobPtr & StrBlobPtr::decr() {
	// ���curr�Ѿ�Ϊ0���ݼ����ͻ����һ���Ƿ��±�
	--curr;							// �ݼ���ǰλ��
	check(-1, "decrement past begin of StrBlobPtr");
	return *this;
}

// StrBlob��begin��end��Ա�Ķ���
inline StrBlobPtr StrBlob::begin() {
	return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end() {
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}

// const�汾
inline StrBlobPtr StrBlob::begin() const {
	return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end() const {
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}

// StrBlobPtr�ıȽϲ���
inline bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	// ���ײ��vector��ͬһ��
	if (l == r) {
		// ������ָ�붼�ǿգ�����ָ����ͬԪ��ʱ���������
		return (!r || lhs.curr == rhs.curr);
	}
	else {
		return false;			// ��ָ��ͬvector,�򲻿������
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
