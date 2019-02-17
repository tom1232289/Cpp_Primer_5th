#include<iostream>
using namespace std;
double myADD(double dval1, double dval2) {
	double result = dval1 + dval2;
	static unsigned cnt = 0;
	++cnt;
	cout << "该函数已经累计执行了" << cnt << "次。" << endl;
	return result;
}

int main()
{
	double num1, num2;
	cout << "请输入两个数：" << endl;
	while (cin >> num1 >> num2) {
		cout << num1 << "与" << num2 << "的求和结果为：" << myADD(num1, num2) << endl;
	}
	system("pause");
	return 0;
}