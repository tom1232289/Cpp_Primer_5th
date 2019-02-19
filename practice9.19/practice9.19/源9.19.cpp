#include<iostream>
#include<list>
#include<string>

using namespace std;

int main()
{
	list<string> slist;
	string word;
	while (cin >> word)
		slist.push_back(word);
	for (auto beg = slist.cbegin(); beg != slist.cend(); ++beg)
		cout << *beg << " ";
	cout << endl;

	system("pause"); return 0;
}