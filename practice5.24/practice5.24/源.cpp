#include<iostream>
#include<stdexcept>
using namespace std;
int main()
{
	int ival1, ival2;
	cout << "���������뱻�����ͳ���:" << endl;
	cin >> ival1 >> ival2;
	if (ival2 == 0) {
		throw runtime_error("��������Ϊ0");
	}
	cout << "��������Ľ����:" << ival1 / ival2 << endl;
	system("pause");
	return 0;
}