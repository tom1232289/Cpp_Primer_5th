#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	cout << "����������������" << endl;
	int i = 0, j = 0;
	cin >> i >> j;
	if (i > j) {
		int k = 0;
		k = i;
		i = j;
		j = k;
	}
	for(;i<=j;i++){
		cout << i << " ";
	}
	system("pause");
	return 0;
}