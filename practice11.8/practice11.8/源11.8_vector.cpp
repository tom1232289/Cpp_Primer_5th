#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	vector<string> unique_word;
	string word;
	while (cin >> word) {
		if (find(unique_word.cbegin(), unique_word.cend(), word) == unique_word.cend())
			unique_word.push_back(word);
	}

	for (const auto s : unique_word)
		cout << s << " ";
	cout << endl;

	system("pause"); return 0;
}