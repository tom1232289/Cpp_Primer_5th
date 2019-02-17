#include<iostream>
using namespace std;
int main()
{
	int a[10];
	for (int i = 0; i < 10; ++i) {
		a[i] = i;
	}
	for (auto c : a) {
		cout << c << " ";
	}
	system("pause");
	return 0;
}