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
	cout << "������" << sz << "����,��������࣬��ֻȡǰ" << sz << "����" << endl;
	for (int i = 0; i < sz; ++i) {
		if (cin >> ival) {
			b.push_back(ival);
		}
		else {
			cout << "��������" << endl;
			system("pause");
			return -1;
		}
	}
	cout << "ϵͳ��Ԫ������Ϊ��" << endl;
	for (auto c : a) {
		cout << c << " ";
	}
	cout << endl;
	cout << "�������Ԫ������Ϊ:" << endl;
	for (auto c : b) {
		cout << c << " ";
	}
	cout << endl;
	auto abeg = a.cbegin(), aend = a.cend(), bbeg = b.cbegin(), bend = b.cend();
	if (aend - abeg != bend - bbeg) {
		cout << "������vector�����������ȣ�������ȡ�" << endl;
		system("pause");
		return 0;
	}//�涨������sz�󣬴�if��������û���ˡ�
	for (; abeg != aend; ++abeg, ++bbeg) {
		if (*abeg != *bbeg) {
			cout << "������vector������ȡ�" << endl;
			system("pause");
			return 0;
		}
	}
	cout << "������vector������ȡ�" << endl;
	system("pause");
	return 0;
}