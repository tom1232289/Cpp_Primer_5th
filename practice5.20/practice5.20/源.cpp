#include<iostream>
#include<string>
using namespace std;
int main()
{
	string currString,preString;
	cin >> preString;
	bool bl = true;
	while (cin>>currString) {
		if (preString == currString) {
			cout << currString;
			bl = false;
			break;
		}
		preString = currString;
	}
	cout << endl;
	if (bl) {
		cout << "没有任何单词是连续重复出现的。" << endl;
	}
	system("pause");
	return 0;
}