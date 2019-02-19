#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<string> svec;
	svec.reserve(1024);
	string word = { "abc" };
	for (int i = 0; i < 1048; ++i)
		svec.push_back(word);
	svec.resize(svec.size() + svec.size() / 2);
	cout << svec.capacity() << endl;

	system("pause"); return 0;
}