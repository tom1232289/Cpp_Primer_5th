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
	// ÿ��Blobʵ��������Ȩ����������ͬ����ʵ������BlobPtr����������
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
	// Blob�е�Ԫ����Ŀ
	size_t size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	// ��Ӻ�ɾ��Ԫ��
	void push_back(const T &t) { data->push_back(t); }
	void push_back(T &&t) { data->push_back(std::move(t)); }	// �ƶ��汾
	void pop_back();
	// Ԫ�ط���
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
	// ��data[i]��Ч�����׳�msg
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
	// ���i̫��check���׳��쳣����ֹ����һ�������ڵ�Ԫ��
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
inline const T & Blob<T>::operator[](size_t i) const
{
	// ���i̫��check���׳��쳣����ֹ����һ�������ڵ�Ԫ��
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