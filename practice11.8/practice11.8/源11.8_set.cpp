#include<iostream>
#include<set>
#include<string>

using namespace std;

int main()
{
	set<string> sset;
	string word;
	while (cin >> word) {
		sset.insert(word);
	}
	for (const auto s : sset)
		cout << s << " ";

	system("pause"); return 0;
}