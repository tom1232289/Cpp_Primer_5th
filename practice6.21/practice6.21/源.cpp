#include<iostream>
#include<ctime>
using namespace std;

int myCompare(const int val, const int *p) {
	return (val > *p) ? val : *p;
}

int main()
{
	srand((unsigned)time(NULL));
	int a[10];
	for (auto &i : a)
		i = rand() % 100;
	cout << "������һ������" << endl;
	int j;
	cin >> j;
	cout << "�����������������Ԫ���нϴ���ǣ�" << myCompare(j, a) << endl;
	cout << "�����ȫ��Ԫ���ǣ�" << endl;
	for (auto c : a)
		cout << c << " ";
	cout << endl;
	system("pause");
	return 0;
}