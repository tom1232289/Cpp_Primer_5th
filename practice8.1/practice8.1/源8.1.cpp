#include<iostream>
using namespace std;

istream& func(istream& in) {
	int v;
	while (in >> v, !in.eof()) {
		if (in.bad())
			throw runtime_error("IO流错误");
		if (in.fail()) {
			cerr << "数据错误，请重试：" << endl;
			in.clear();
			in.ignore(100, '\n');
			continue;
		}
		cout << v << " ";
	}
	in.clear();
	return in;
}

int main()
{
	cout << "请输入一些整数，按Ctrl+Z结束" << endl;
	func(cin);

	system("pause");
	return 0;
}