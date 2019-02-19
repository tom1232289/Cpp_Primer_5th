#include "TextQuery.h"

TextQuery::TextQuery(ifstream & is):
	file(new vector<string>)
{
	string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line >> word) {
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<size_t>);
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const string & s)
{
	static shared_ptr<set<size_t>> nodata(new set<size_t>);
	auto loc = wm.find(s);
	if (loc == wm.end())
		return QueryResult(s, nodata, file);
	else
		return QueryResult(s, loc->second, file);
}
