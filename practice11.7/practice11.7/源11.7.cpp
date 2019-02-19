#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

void add_family(map<string, vector<string>> &families, const string &family) {
	families[family];
}

void add_child(map<string, vector<string>> &families, const string &family, const string &child) {
	families[family].push_back(child);
}

int main()
{
	map<string, vector<string>> families;
	add_family(families, "zhang");
	add_child(families, "zhang", "lin");
	add_family(families, "feng");
	add_child(families, "tom", "tom");
	for (const auto &f : families) {
		cout << f.first << ":";
		for (const auto c : f.second)
			cout << c << " ";
		cout << endl;
	}
	system("pause"); return 0;
}