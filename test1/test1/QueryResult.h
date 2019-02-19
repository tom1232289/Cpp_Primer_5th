#pragma once
#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <set>

using namespace std;

class QueryResult
{
	friend ostream & print(ostream & os, const QueryResult &qr);
public:
	QueryResult(string s, shared_ptr<set<size_t>> p, shared_ptr<vector<string>> f) :
		sought(s),
		lines(p),
		file(f) {	}
public:
	size_t size() const { return lines->size(); }
	auto begin() const { return lines->begin(); }
	auto end() const { return lines->end(); }
	auto get_file() const { return file; }
private:
	string sought;
	shared_ptr<set<size_t>> lines;
	shared_ptr<vector<string>> file;
};

#endif	// !QUERY_RESULT_H