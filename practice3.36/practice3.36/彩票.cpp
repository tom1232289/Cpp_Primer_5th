#include<iostream>	
#include<ctime>
using namespace std;
int main()
{
	const int sz = 5;
	int arr1[sz], arr2[sz];
	srand((unsigned)time(NULL));
	for (int i = 0; i < sz; ++i) {
		arr1[i] = rand() % 10;
	}
	cout << "请猜"<<sz<<"个数：" << endl;
	for (int i = 0; i < sz; ++i) {
		int ival = 0;
		if (cin >> ival) {
			arr2[i] = ival;
		}
		else {
			cout << "输入有误！" << endl;
			system("pause");
			return 0;
		}
	}
	cout << "您猜测的数字为：" << endl;
	for (auto c : arr2) {
		cout << c << " ";
	}
	cout << endl;
	cout << "中奖数字为：" << endl;
	for (auto c : arr1) {
		cout << c << " ";
	}
	cout << endl;
	for (int *p1 = begin(arr1), *p2 = begin(arr2); p1 != end(arr1) && p2 != end(arr2); ++p1, ++p2) {
		if (*p1 != *p2) {
			cout << "很遗憾，您未能中奖。" << endl;
			system("pause");
			return 0;
		}
	}
	cout << "恭喜您中奖了！" << endl;
	system("pause");
	return 0;
}