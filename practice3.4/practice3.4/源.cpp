#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
	string st1, st2;
	cin >> st1 >> st2;
	if (st1 == st2) {
		cout << "字符串相等 "<<st1 << endl;
	}
	else {
		if (st1 < st2) {
			cout << "较大的字符串为：" << st2 << endl;
		}
		else {
			cout << "较大的字符串为：" << st1 << endl;
		}
	}
	if (st1.size() == st2.size()) {
		cout <<"字符串等长 "<< st1 << endl;
	}
	else {
		if (st1.size() < st2.size()) {
			cout << "长度较大的字符串为：" << st2 << endl;
		}
		else {
			cout << "长度较大的字符串为：" << st1 << endl;
		}
	}
	system("pause");
	return 0;
}