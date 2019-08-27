#pragma once

#include "QueryResult.h"
#include <map>
#include <fstream>
#include <sstream>
#include "DebugDelete.h"

class TextQuery
{
public:
	TextQuery(ifstream &is);
public:
	QueryResult query(const string &s);
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<size_t>>> wm;
};