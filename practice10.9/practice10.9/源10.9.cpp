#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());

	auto end_unique = unique(words.begin(), words.end());
	for (auto c : words)
		cout << c << " ";
	cout << endl;

	words.erase(end_unique, words.end());
	for (auto c : words)
		cout << c << " ";
	cout << endl;

}

int main()
{
	vector<string> svec = { "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	for (auto c : svec)
		cout << c << " ";
	cout << endl;
	elimDups(svec);

	system("pause"); return 0;
}