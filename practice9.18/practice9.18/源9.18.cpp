#include<iostream>
#include<deque>
#include<string>

using namespace std;

int main()
{
	deque<string> sdeq;
	string word;
	while (cin >> word)
		sdeq.push_back(word);
	for (auto beg=sdeq.cbegin(); beg != sdeq.cend(); ++beg)
		cout << *beg << " ";
	cout << endl;

	system("pause"); return 0;
}