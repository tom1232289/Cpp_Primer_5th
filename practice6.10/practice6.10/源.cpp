#include<iostream>
using namespace std;

void mySwap(int &p,int &q)
{
	int tmp = p;
	p = q;
	q = tmp;
}

int main()
{
	int a = 5, b = 10;
	cout << "����ǰa=" << a << ",b=" << b << endl;
	mySwap(a, b);
	cout << "������a=" << a << ",b=" << b << endl;
	system("pause");
	return 0;
}