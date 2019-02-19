#pragma once
#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include"TextQuery.h"
#include"F:\c++ primer\test1\test1\make_plural.h"

using namespace std;

class QueryResult {
	friend ostream &print(ostream &, const QueryResult &);
public:
	QueryResult(string s, shared_ptr<vector<string>> f, shared_ptr<vector<line_no>> l) :sought(s), file(f), vector_lineno(l) { }
private:
	string sought;
	shared_ptr<vector<string>> file;
	shared_ptr<vector<line_no>> vector_lineno;
};

QueryResult TextQuery::query(const string &sought) const {
	auto loc = wm.find(sought);
	static shared_ptr<vector<line_no>> nodata(new vector<line_no>);
	if (loc == wm.end()) {
		return QueryResult(sought, file, nodata);
	}
	else {
		return QueryResult(sought, file, loc->second);
	}
}

ostream &print(ostream &os, const QueryResult &qr) {
	os << qr.sought << " occurs " << qr.vector_lineno->size() << make_plural(qr.vector_lineno->size(), " time", "s") << endl;
	for (auto num : *(qr.vector_lineno)) {
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
	}
	return os;
}

#endif // !QUERYRESULT_H
