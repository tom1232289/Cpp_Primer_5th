#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
int main()
{
	const int sz = 10;
	int arr[sz];
	srand((unsigned)time(NULL));
	for (auto &val : arr) {
		val = rand() % 100;
		cout << val << " ";
	}
	cout << endl;
	vector<int> vInt(begin(arr), end(arr));
	for (auto c : vInt)
		cout << c << " ";
	cout << endl;
	system("pause");
	return 0;
}