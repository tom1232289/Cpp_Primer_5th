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

	// �����͵ݼ�
	BlobPtr<T> & operator++();		// ǰ�������
	BlobPtr<T> & operator--();
	BlobPtr<T> & operator++(int);	// ���������
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
	// �����ɹ���check����һ��ָ��vector��shared_ptr
	shared_ptr<vector<T>> check(size_t, const string &msg) const;
	// ����һ��weak_ptr����ʾ�ײ�vector���ܱ�����
	weak_ptr<vector<T>> wptr;
	size_t curr;	// �����еĵ�ǰλ��
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

// ���ã��������󵫷���ԭֵ
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