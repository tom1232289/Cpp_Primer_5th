#include<iostream>
#include<string>
using namespace std;
int main()
{
	string st1("A string example"), st2("A different string");
	if (st1 < st2) {
		cout << "��һ���ַ���С�ڵڶ����ַ�����" << endl;
	}
	if(st1>st2){
		cout << "��һ���ַ������ڵڶ����ַ�����" << endl;
	}
	else {
		cout << "�����ַ�����ȡ�" << endl;
	}
	const char ca1[] = "A string example", ca2[] = "A different string";
	if (strcmp(ca1, ca2) < 0) {
		cout << "��һ���ַ���С�ڵڶ����ַ�����" << endl;
	}
	if (strcmp(ca1, ca2) > 0) {
		cout << "��һ���ַ������ڵڶ����ַ�����" << endl;
	}
	else {
		cout << "�����ַ�����ȡ�" << endl;
	}
	system("pause");
	return 0;
}