#include<iostream>
using namespace std;
double myADD(double dval1, double dval2) {
	double result = dval1 + dval2;
	static unsigned cnt = 0;
	++cnt;
	cout << "�ú����Ѿ��ۼ�ִ����" << cnt << "�Ρ�" << endl;
	return result;
}

int main()
{
	double num1, num2;
	cout << "��������������" << endl;
	while (cin >> num1 >> num2) {
		cout << num1 << "��" << num2 << "����ͽ��Ϊ��" << myADD(num1, num2) << endl;
	}
	system("pause");
	return 0;
}