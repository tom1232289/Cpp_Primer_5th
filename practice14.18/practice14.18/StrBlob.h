#pragma once
#ifndef STRBLOB_H_INCLUDE
#define STRBLOB_H_INCLUDE

#include<iostream>
#include<string>
#include<vector>
#include<memory>

using namespace std;

class StrBlobPtr;
class StrBlob {
	friend class StrBlobPtr;
	friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator<=(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator>(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator>=(const StrBlob &lhs, const StrBlob &rhs);
public:
	StrBlob();
	StrBlob(initializer_list<string> il);
	StrBlob(vector<string> *p);
public:
	size_t size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string &t) { data->push_back(t); }
	void push_back(string &&t) { data->push_back(std::move(t)); }
	void pop_back();
	string &front();
	const string &front() const;
	string &back();
	const string &back() const;
public:
	// 提供给StrBlobPtr的接口
	StrBlobPtr begin();
	StrBlobPtr end();
	StrBlobPtr begin() const;
	StrBlobPtr end() const;
private:
	shared_ptr<vector<string>> data;
	void check(size_t i, const string &msg) const;
};

inline StrBlob::StrBlob() :data(make_shared<vector<string>>()) { }
inline StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) { }
inline StrBlob::StrBlob(vector<string>* p) : data(p) { }

void StrBlob::check(size_t i, const string &msg) const {
	if (i >= data->size())
		throw out_of_range(msg);
}

string& StrBlob::front() {
	check(0, "front on empty StrBlob");
	return data->front();
}

const string& StrBlob::front() const {
	check(0, "front on empty StrBlob");
	return data->front();
}

string& StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}

const string& StrBlob::back() const {
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob");
	return data->pop_back();
}

#endif // !STRBLOB_H_INCLUDE
