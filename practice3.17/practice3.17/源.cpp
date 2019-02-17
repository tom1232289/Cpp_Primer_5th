#include<iostream>
#include<string>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
	vector<string> vString;
	string str;
	while (cin >> str) {
		vString.push_back(str);	
	}
	for (auto mem : vString) {
		for (auto &c : mem) {
			c=toupper(c);
		}
		cout << mem << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}