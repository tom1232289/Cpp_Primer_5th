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
	cout << "���"<<sz<<"������" << endl;
	for (int i = 0; i < sz; ++i) {
		int ival = 0;
		if (cin >> ival) {
			arr2[i] = ival;
		}
		else {
			cout << "��������" << endl;
			system("pause");
			return 0;
		}
	}
	cout << "���²������Ϊ��" << endl;
	for (auto c : arr2) {
		cout << c << " ";
	}
	cout << endl;
	cout << "�н�����Ϊ��" << endl;
	for (auto c : arr1) {
		cout << c << " ";
	}
	cout << endl;
	for (int *p1 = begin(arr1), *p2 = begin(arr2); p1 != end(arr1) && p2 != end(arr2); ++p1, ++p2) {
		if (*p1 != *p2) {
			cout << "���ź�����δ���н���" << endl;
			system("pause");
			return 0;
		}
	}
	cout << "��ϲ���н��ˣ�" << endl;
	system("pause");
	return 0;
}