#include<iostream>
using namespace std;
int fact(int val) {
	if (val < 0) {
		cout << "请输入大于0的数" << endl;
		system("pause");
		return -1;
	}
	int ret = 1;
	while (val > 1) 
		ret *= val--;
	return ret;
}

int main()
{
	int num;
	cout << "请输入一个整数：" << endl;
	cin >> num;
	cout << num << "!=" << fact(num) << endl;
	system("pause");
	return 0;
}