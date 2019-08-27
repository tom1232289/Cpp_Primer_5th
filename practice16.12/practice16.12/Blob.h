#pragma once

#ifndef BLOB_H
#define BLOB_H

#include <memory>
#include <vector>

using namespace std;

template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T>
class Blob
{
	// 每个Blob实例将访问权限授予用相同类型实例化的BlobPtr和相等运算符
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T> &lhs, const Blob<T> &rhs);
public:
	typedef T value_type;
	// 	typedef typename vector<T>::size_type size_type;
public:
	Blob();
	Blob(initializer_list<T> il);
	template <typename It>
public:
	// Blob中的元素数目
	size_t size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	// 添加和删除元素
	void push_back(const T &t) { data->push_back(t); }
	void push_back(T &&t) { data->push_back(std::move(t)); }	// 移动版本
	void pop_back();
	// 元素访问
	T & back();
	const T & back() const;
	T & front();
	const T & front() const;
	T & operator[](size_t i);
	const T & operator[](size_t i) const;

	BlobPtr<T> begin() { return *this };
	BlobPtr<T> end() {
		auto ret = BlobPtr<T>(*this, this->size());
		return ret;
	}
private:
	shared_ptr<vector<T>> data;
	// 若data[i]无效，则抛出msg
	void check(size_t i, const string &msg) const;
};

template <typename T>
Blob<T>::Blob() :
	data(make_shared<vector<T>>())
{
}

template <typename T>
Blob<T>::Blob(initializer_list<T> il) :
	data(make_shared<vector<T>>())
{
}

template <typename T>
void Blob<T>::check(size_t i, const string &msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

template <typename T>
T & Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
inline const T & Blob<T>::back() const
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
inline T & Blob<T>::front()
{
	check(0, "front on empty Blob");
	return data->front();
}

template <typename T>
inline const T & Blob<T>::front() const
{
	check(0, "front on empty Blob");
	return data->front();
}

template <typename T>
T & Blob<T>::operator[](size_t i)
{
	// 如果i太大，check会抛出异常，阻止访问一个不存在的元素
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
inline const T & Blob<T>::operator[](size_t i) const
{
	// 如果i太大，check会抛出异常，阻止访问一个不存在的元素
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

template <typename T>
bool operator==(const Blob<T>& lhs, const Blob<T>& rhs)
{
	if (rhs.size() != lhs.size())
		return false;
	for (size_t i = 0; i != lhs.size(); ++i) {
		if (lhs[i] != rhs[i])
			return false;
	}
	
	return true;
}

#endif	// !BLOB_H