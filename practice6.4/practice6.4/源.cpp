#include<iostream>
using namespace std;
int fact(int val) {
	if (val < 0) {
		cout << "���������0����" << endl;
		system("pause");
		return -1;
	}
	int ret = 1;
	while (val > 1) 
		ret *= val--;
	return ret;
}

int main()
{
	int num;
	cout << "������һ��������" << endl;
	cin >> num;
	cout << num << "!=" << fact(num) << endl;
	system("pause");
	return 0;
}