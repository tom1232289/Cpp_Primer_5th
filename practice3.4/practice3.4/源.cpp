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
		cout << "�ַ������ "<<st1 << endl;
	}
	else {
		if (st1 < st2) {
			cout << "�ϴ���ַ���Ϊ��" << st2 << endl;
		}
		else {
			cout << "�ϴ���ַ���Ϊ��" << st1 << endl;
		}
	}
	if (st1.size() == st2.size()) {
		cout <<"�ַ����ȳ� "<< st1 << endl;
	}
	else {
		if (st1.size() < st2.size()) {
			cout << "���Ƚϴ���ַ���Ϊ��" << st2 << endl;
		}
		else {
			cout << "���Ƚϴ���ַ���Ϊ��" << st1 << endl;
		}
	}
	system("pause");
	return 0;
}