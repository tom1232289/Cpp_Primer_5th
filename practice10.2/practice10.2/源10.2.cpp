#include<iostream>
#include<algorithm>
#include<list>
#include<string>
#include<fstream>

using namespace std;

int main(int argc, char* argv[]) {
	ifstream in(argv[1]);
	if (!in) {
		cerr << "�޷��������ļ�" << endl;
		system("pause"); return -1;
	}
	list<string> istring;
	string str;
	while (in >> str)
		istring.push_back(str);
	cout << "������Ҫ�������ַ���" << endl;
	cin >> str;
	cout << str << "������" << count(istring.begin(), istring.end(), str) << "��" << endl;

	system("pause"); return 0;
}