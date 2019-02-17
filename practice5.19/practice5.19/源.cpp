#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1, str2;
	do {
		cout << "请输入两个string对象：" << endl;
		cin >> str1 >> str2;
		if (str1.size() < str2.size())
			cout << str1 << endl;
		else if (str1.size() > str2.size())
			cout << str2 << endl;
		else
			cout << "两个字符串等长。" << endl;
	} while (cin);
	system("pause");
	return 0;
}