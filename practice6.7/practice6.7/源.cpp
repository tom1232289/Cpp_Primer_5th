#include<iostream>
using namespace std;
int myCnt() {
	static int cnt = -1;
	++cnt;
	return cnt;
}

int main()
{
	char ch;
	cout << "�����������ַ��󰴻س�����" << endl;
	while (cin>>ch) {
		cout << myCnt() << endl;
	}
	system("pause");
	return 0;
}