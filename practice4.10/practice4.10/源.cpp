#include<iostream>
using namespace std;
int main()
{
	int i = 0;
	while (cin >> i && i != 42) {
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}