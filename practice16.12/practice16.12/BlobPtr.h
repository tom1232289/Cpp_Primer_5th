#pragma once

#ifndef BLOBPTR_H
#define BLOBPTR_H

#include <memory>
#include <vector>
#include <string>
#include "Blob.h"

using namespace std;

template<typename T>
class BlobPtr
{
	template <typename T>
	friend bool operator==<T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
public:
	BlobPtr() :curr(0) {}
	BlobPtr(Blob<T> &a, size_t sz = 0) :
		wptr(a.data), curr(sz) {}

	// 递增和递减
	BlobPtr<T> & operator++();		// 前置运算符
	BlobPtr<T> & operator--();
	BlobPtr<T> & operator++(int);	// 后置运算符
	BlobPtr<T> & operator--(int);

	T & operator[](size_t i) {
		auto p = check(i, "subcript out of range");
		return (*p)[i];
	}
	const T & operator[](size_t i) const {
		auto p = check(i, "subcript out of range");
		return (*p)[i];
	}

	T & operator*() const {
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}

	T * operator->() const {
		return &this->operator*();
	}

private:
	// 若检查成功，check返回一个指向vector的shared_ptr
	shared_ptr<vector<T>> check(size_t, const string &msg) const;
	// 保存一个weak_ptr，表示底层vector可能被销毁
	weak_ptr<vector<T>> wptr;
	size_t curr;	// 数组中的当前位置
};

template <typename T>
inline BlobPtr<T>& BlobPtr<T>::operator++()
{
	check(curr, "++");
	++curr;
	return *this;
}

template <typename T>
inline BlobPtr<T>& BlobPtr<T>::operator--()
{
	--curr;
	check(curr, "--");
	return *this;
}

// 后置：递增对象但返回原值
template <typename T>
inline BlobPtr<T>& BlobPtr<T>::operator++(int)
{
	BlobPtr ret = *this;
	++*this;
	return ret;
}

template <typename T>
inline BlobPtr<T>& BlobPtr<T>::operator--(int)
{
	BlobPtr ret = *this;
	--*this;
	return ret;
}

template <typename T>
inline shared_ptr<vector<T>> BlobPtr<T>::check(size_t, const string & msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw runtime_error("unbind BlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}

template <typename T>
inline bool operator==<T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	return (lhs.wptr.lock().get() == rhs.wptr.lock().get()) && lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return !(lhs == rhs);
}

#endif	// !BLOBPTR_H