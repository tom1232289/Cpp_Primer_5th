#include<iostream>
#include<stdexcept>
using namespace std;
int main()
{
	int ival1, ival2;
	cout << "���������뱻�����ͳ���:" << endl;
	while (cin >> ival1 >> ival2) {
		try {
			if (ival2 == 0) {
				throw runtime_error("��������Ϊ0");
			}
			cout << "��������Ľ���ǣ�" << ival1 / ival2 << endl;
		}
		catch (runtime_error err) {
			cout << err.what() << endl;
			cout << "��Ҫ������y or n����";
			char ch;
			cin >> ch;
			if (ch != 'y'&&ch != 'Y')
				break;
		}
	}
	system("pause");
	return 0;
}