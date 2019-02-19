#include<iostream>
#include<vector>
#include<string>	

using namespace std;

int main()
{
	vector<string> svec;
	string word;
	auto iter = svec.begin();
	while (cin >> word)
		iter = svec.insert(iter, word);

	for (auto c : svec)
		cout << c << " ";
	cout << endl;
	system("pause"); return 0;
}