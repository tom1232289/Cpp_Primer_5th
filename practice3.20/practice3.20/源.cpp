#include<iostream>
#include<string>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::cerr;
int main()
{
	vector<int> vInt;
	int iVal = 0;
	while (cin >> iVal) {
		vInt.push_back(iVal);
	}
	if (vInt.size() == 0) {
		cerr << "没有任何元素" << endl;
		system("pause");
		return -1;
	}
	cout << "相邻两项的和为：";
	for (decltype(vInt.size()) i = 0; i < vInt.size() - 1; i += 2) {
		cout << vInt[i] + vInt[i + 1]<<" ";
		if ((i + 2) % 10 == 0)
			cout << endl;
	}
	if (vInt.size() % 2 != 0)
		cout << vInt[vInt.size() - 1];
	cout << endl;
	decltype(vInt.size()) i = 0, j = vInt.size() - 1;
	cout << "首位相加的和为：";
	while (i < j) {
		cout<< vInt[i] + vInt[j] << " ";
		++i;
		--j;
	}
	if (vInt.size() % 2 != 0) {
		cout << vInt[i] << endl;
	}
	system("pause");
	return 0;
}