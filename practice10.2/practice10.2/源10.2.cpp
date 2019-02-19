#include<iostream>
#include<algorithm>
#include<list>
#include<string>
#include<fstream>

using namespace std;

int main(int argc, char* argv[]) {
	ifstream in(argv[1]);
	if (!in) {
		cerr << "无法打开输入文件" << endl;
		system("pause"); return -1;
	}
	list<string> istring;
	string str;
	while (in >> str)
		istring.push_back(str);
	cout << "请输入要搜索的字符串" << endl;
	cin >> str;
	cout << str << "出现了" << count(istring.begin(), istring.end(), str) << "次" << endl;

	system("pause"); return 0;
}