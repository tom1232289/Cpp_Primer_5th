#include<iostream>
#include<string>

using namespace std;

void replace_string(string &s, const string &oldVal, const string &newVal) {
	int p = 0;
	while ((p = s.find(oldVal, p)) != string::npos) {
		s.replace(p, oldVal.size(), newVal);
		p += newVal.size();
	}
}

int main()
{
	string s = "tho thru tho!";
	string str = "aaaabcaaa";
	replace_string(str, "abc", "def");
	replace_string(s, "tho", "thought");
	cout << s << endl;
	replace_string(s, "thru", "thought");
	cout << s << endl;

	system("pause"); return 0;
}