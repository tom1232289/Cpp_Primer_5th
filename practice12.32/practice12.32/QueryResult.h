#pragma once
#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include"TextQuery.h"
#include"F:\c++ primer\test1\test1\make_plural.h"
#include"StrBlob.h"
#include"StrBlobPtr.h"

using namespace std;

class QueryResult {
	friend ostream &print(ostream &, const QueryResult &);
public:
	QueryResult(string s, StrBlob f, shared_ptr<set<line_no>> l) :sought(s), file(f), set_lineno(l) { }
private:
	string sought;
	StrBlob file;
	shared_ptr<set<line_no>> set_lineno;
};

QueryResult TextQuery::query(const string &sought) const {
	auto loc = wm.find(sought);
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	if (loc == wm.end()) {
		return QueryResult(sought, file, nodata);
	}
	else {
		return QueryResult(sought, file, loc->second);
	}
}

ostream &print(ostream &os, const QueryResult &qr) {
	os << qr.sought << " occurs " << qr.set_lineno->size() << make_plural(qr.set_lineno->size(), " time", "s") << endl;
	for (auto num : *(qr.set_lineno)) {
		os << "\t(line " << num + 1 << ") " << qr.file.begin().deref(num) << endl;
	}
	return os;
}

#endif // !QUERYRESULT_H
