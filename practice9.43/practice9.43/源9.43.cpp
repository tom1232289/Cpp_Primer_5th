#include<iostream>
#include<string>

using namespace std;

void replace_string(string &s, const string &oldVal, const string &newVal) {
	auto oldLen = oldVal.size();
	if (!oldLen)
		return;
	auto iter = s.begin();
	while (iter <= s.end() - oldLen) {
		auto iter1 = iter;
		auto iter2 = oldVal.begin();
		while (iter2 != oldVal.end() && *iter1 == *iter2) {
			++iter1;
			++iter2;
		}
		if (iter2 == oldVal.end()) {
			iter = s.erase(iter, iter1);
			if (newVal.size()) {
				auto iter3 = newVal.end();
				do {
					--iter3;
					iter = s.insert(iter, *iter3);
				} while (iter3 > newVal.begin());
			}
			iter += newVal.size();
		}
		else
			++iter;
	}
}

int main()
{
	string s = "tho thru tho!";
	replace_string(s, "tho", "thought");
	cout << s << endl;
	replace_string(s, "thru", "thought");
	cout << s << endl;

	system("pause"); return 0;
}