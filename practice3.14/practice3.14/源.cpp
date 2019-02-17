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
	int i=0;
	vector<int> vInt;
	cout << "请输入一组整数：" << endl;
	while (cin >> i) {
		vInt.push_back(i);
	}
	for (auto mem : vInt) {
		cout << mem;
	}
	cout << endl;
	system("pause");
	return 0;
}