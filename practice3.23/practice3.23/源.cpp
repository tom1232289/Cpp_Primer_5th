#include<iostream>
#include<string>
#include<vector>
#include<ctime>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
	vector<int> vInt;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++) {
		vInt.push_back(rand() % 1000);
	}
	cout << "������ɵ�10�������ǣ�" << endl;
	for (auto it = vInt.cbegin(); it != vInt.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	cout << "�������10�������ǣ�" << endl;
	for (auto it = vInt.begin(); it != vInt.cend(); ++it) {
		*it *= 2;
		cout << *it << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}