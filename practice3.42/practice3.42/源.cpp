#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
int main()
{
	vector<int> vInt;
	srand((unsigned)time(NULL));
	const int sz = 10;
	for (int i = 0; i < 10; ++i) {
		vInt.push_back(rand() % 100);
	}
	for (auto c : vInt) {
		cout << c << " ";
	}
	cout << endl;
	int arr[sz];
	auto it = vInt.cbegin();
	for (auto &c : arr) {
		c = *it;
		cout << c << " ";
		++it;
	}
	cout << endl;
	system("pause");
	return 0;
}