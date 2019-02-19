#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}

int main()
{
	vector<string> svec = { "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	elimDups(svec);
	stable_sort(svec.begin(), svec.end(), isShorter);
	for (auto c : svec)
		cout << c << " ";
	cout << endl;

	system("pause"); return 0;
}