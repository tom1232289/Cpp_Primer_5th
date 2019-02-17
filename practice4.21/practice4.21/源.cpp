#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
int main()
{
	vector<int> vInt;
	const int sz = 10;
	srand((unsigned)time(NULL));
	for (int i = 0; i != sz; ++i) {
		vInt.push_back(rand()%100);
	}
	cout << "随机生成的" << sz << "个数为：" << endl;
	for (auto it = vInt.cbegin(); it != vInt.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	for (auto &c : vInt) {
		c = (c % 2 != 0) ? c * 2 : c;
	}
	cout << "奇数翻倍后为：" << endl;
	for (auto it = vInt.cbegin(); it != vInt.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}