#pragma once
#ifndef TEXTQUERY_INCLUDE
#define TEXTQUERY_INCLUDE

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<map>
#include<set>
#include<memory>
#include"StrBlob.h"

using namespace std;

using line_no = vector<string>::size_type;

class QueryResult;
class TextQuery {
public:
	TextQuery(ifstream&);
	QueryResult query(const string&) const;
private:
	StrBlob file;
	map<string, shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream &is) :file(new vector<string>)
{
	string text;
	while (getline(is, text)) {
		file.push_back(text);
		int n = file.size() - 1;
		istringstream line(text);
		string word;
		while (line >> word) {
			auto &lines = wm[word];
			if (!lines) {
				lines.reset(new set<line_no>);
			}
			lines->insert(n);
		}
	}
}

#endif // !TEXTQUERY_INCLUDE