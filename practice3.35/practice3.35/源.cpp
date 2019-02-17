#include<iostream>
using namespace std;
int main()
{
	int arr[] = { 1,2,3,4,5 };
	for (auto c : arr) {
		cout << c << " ";
	}
	cout << endl;
	for (int *p = begin(arr); p != end(arr); ++p) {
		*p = 0;
	}
	for (auto c : arr) {
		cout << c << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}