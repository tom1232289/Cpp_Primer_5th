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
			cout << "v1��v2֮�䲻����ǰ׺��ϵ��" << endl;
			system("pause");
			return -1;
		}
	}
	if (it1 == vInt1.cend()) {
		cout << "v1��v2��ǰ׺��" << endl;
	}
	if (it2 == vInt2.cend()) {
		cout << "v2��v1��ǰ׺��" << endl;
	}
	system("pause");
	return 0;
}