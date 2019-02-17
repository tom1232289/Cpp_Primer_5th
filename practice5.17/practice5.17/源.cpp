#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	vector<int> vInt1 = { 0,1,1,2 }, vInt2 = { 0,1,1,2,3,5,8 };
	auto it1 = vInt1.cbegin(), it2 = vInt2.cbegin();
	for (; it1 != vInt1.cend() && it2 != vInt2.cend(); ++it1, ++it2) {
		if (*it1 != *it2) {
			cout << "v1和v2之间不存在前缀关系。" << endl;
			system("pause");
			return -1;
		}
	}
	if (it1 == vInt1.cend()) {
		cout << "v1是v2的前缀。" << endl;
	}
	if (it2 == vInt2.cend()) {
		cout << "v2是v1的前缀。" << endl;
	}
	system("pause");
	return 0;
}