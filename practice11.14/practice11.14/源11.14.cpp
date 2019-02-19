#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

void add_family(map<string, vector<pair<string,string>>> &families, const string &family) {
	families[family];
}

void add_child(map<string, vector<pair<string, string>>> &families, const string &family, const string &child, const string &birthday) {
	families[family].push_back({ child, birthday });
}

int main()
{
	map<string, vector<pair<string, string>>> families;
	add_family(families, "zhang");
	add_child(families, "zhang", "lin", "1990-1-1");
	add_family(families, "feng");
	add_child(families, "tom", "tom", "1991-1-1");
	for (const auto f : families) {
		cout << f.first << ":" << endl;
		for (const auto c : f.second) {
			cout << c.first << "(" << c.second << ")" << endl;
		}
	}

	system("pause"); return 0;
}