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
	string str;
	vector<string> vString;
	while (cin >> str) {
		vString.push_back(str);
	}
	for (auto mem : vString)
		cout << mem;
	cout << endl;
	system("pause");
	return 0;
}