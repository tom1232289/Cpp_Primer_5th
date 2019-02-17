#include<iostream>
using namespace std;

void SwapPointer(int *p, int *q) {
	int *temp = p;
	p = q;
	q = temp;
}

void SwapPointer2(int *p, int *q) {
	int temp = *p;
	*p = *q;
	*q = temp;
}

void SwapPointer3(int *&p, int *&q) {
	int *temp = p;
	p = q;
	q = temp;
}

int main()
{
	int a = 9, b = 10;
	int *p=&a, *q=&b;
	cout << p << " " << q << endl;
	SwapPointer3(p, q);
	cout << p << " " << q << endl;
	cout << *p << " " << *q << endl;
	system("pause");
	return 0;
}