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
	cout << "请输入任意字符后按回车键。" << endl;
	while (cin>>ch) {
		cout << myCnt() << endl;
	}
	system("pause");
	return 0;
}