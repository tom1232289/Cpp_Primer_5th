#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> vInt, vInt2;
	for (int i = 0; i < 10; ++i) {
		vInt.push_back(i);
	}
	for (int j = 0; j < 10; ++j) {
		vInt2.push_back(vInt[j]);
	}
	for (auto c : vInt) {
		cout << c << " ";
	}
	cout << endl;
	for (auto c : vInt2) {
		cout << c << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}