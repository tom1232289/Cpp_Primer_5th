#include<iostream>
#include<string>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
	vector<int> vInt1(10, 42);
	vector<int> vInt2{ 42,42,42,42,42,42,42,42,42,42 };
	vector<int> vInt3(10);
	for (auto i : vInt1)
		cout << i << " ";
	cout << endl;
	for (auto i : vInt2)
		cout << i << " ";
	cout << endl;
	for (auto &i : vInt3) {
		i = 42;
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}