#include<iostream>	
#include<vector>
#include<ctime>
using namespace std;
int main()
{
	const int sz = 0;
	vector<int> a, b;
	srand((unsigned)time(NULL));
	for (int i = 0; i < sz; ++i) {
		a.push_back(rand() % 10);
	}
	int ival=0;
	cout << "请输入" << sz << "个数,若输入过多，将只取前" << sz << "个数" << endl;
	for (int i = 0; i < sz; ++i) {
		if (cin >> ival) {
			b.push_back(ival);
		}
		else {
			cout << "输入有误！" << endl;
			system("pause");
			return -1;
		}
	}
	cout << "系统中元素依次为：" << endl;
	for (auto c : a) {
		cout << c << " ";
	}
	cout << endl;
	cout << "您输入的元素依次为:" << endl;
	for (auto c : b) {
		cout << c << " ";
	}
	cout << endl;
	auto abeg = a.cbegin(), aend = a.cend(), bbeg = b.cbegin(), bend = b.cend();
	if (aend - abeg != bend - bbeg) {
		cout << "这两个vector对象容量不等，即不相等。" << endl;
		system("pause");
		return 0;
	}//规定了容量sz后，此if语句基本上没用了。
	for (; abeg != aend; ++abeg, ++bbeg) {
		if (*abeg != *bbeg) {
			cout << "这两个vector对象不相等。" << endl;
			system("pause");
			return 0;
		}
	}
	cout << "这两个vector对象相等。" << endl;
	system("pause");
	return 0;
}