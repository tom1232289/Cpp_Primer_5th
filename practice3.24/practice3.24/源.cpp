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
	vector<int> vInt;
	int ival = 0;
	while (cin >> ival) {
		vInt.push_back(ival);
	}
	if (vInt.cbegin() == vInt.cend()) {
		cout << "û��Ԫ�ػ��������!" << endl;
		system("pause");
		return -1;
	}
	cout << "����Ԫ��֮������Ϊ��" << endl;
	if (vInt.size() % 2 == 0) {
		for (auto it = vInt.cbegin(); it + 1 != vInt.cend() - 1; it += 2) {
			cout << *it + *(it + 1) << " ";
		}
		cout << *(vInt.end() - 2) + *(vInt.end() - 1);
	}
	else {
		for (auto it = vInt.cbegin(); it != vInt.cend() - 1; it += 2) {
			cout << *it + *(it + 1) << " ";
		}
		cout << *(vInt.end() - 1);
	}
	cout << endl;
	cout << "��λԪ��֮������Ϊ��" << endl;
	for (auto beg = vInt.cbegin(), end = vInt.cend()-1; beg < end; ++beg, --end) {
		cout << *beg + *end << " ";
	}
	if (vInt.size() % 2 != 0) {
		cout << *(vInt.cbegin() + vInt.size() / 2);
	}
	cout << endl;
	system("pause");
	return 0;
}