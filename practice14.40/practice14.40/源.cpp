#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class IsShorter
{
public:
	bool operator()(const string &s1, const string s2)
	{
		return s1.size() < s2.size();
	}
};

class NotShorterThen
{
public:
	NotShorterThen(size_t minl):
		minLen(minl){	}
	bool operator()(const string &s)
	{
		return s.size() >= minLen;
	}
private:
	size_t minLen;
};

class PrintString
{
public:
	void operator()(const string &s)
	{
		cout << s << " ";
	}
};

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, size_t sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), IsShorter());
	auto wc = find_if(words.begin(), words.end(), NotShorterThen(sz));
	auto count = words.end() - wc;
	cout << "有" << count << "个比" << sz << "长" << endl;
	for_each(words.begin(), words.end(), PrintString());
	cout << endl;
}

void readStr(istream &is, vector<string> &sVec)
{
	string word;
	while (is >> word)
		sVec.push_back(word);
}

int main()
{
	vector<string> sVec;
	readStr(cin, sVec);
	biggies(sVec, 10);

	system("pause");
	return 0;
}