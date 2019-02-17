#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int a[10], b[10];
	for (int i = 0; i < 10; ++i) {
		a[i] = i;
	}
	for (int j = 0; j < 10; ++j) {
		b[j] = a[j];
	}
	for (auto c : a) {
		cout << c << " ";
	}
	cout << endl;
	for (auto c : b) {
		cout << c << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}