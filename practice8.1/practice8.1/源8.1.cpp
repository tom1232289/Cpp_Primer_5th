#include<iostream>
using namespace std;

istream& func(istream& in) {
	int v;
	while (in >> v, !in.eof()) {
		if (in.bad())
			throw runtime_error("IO������");
		if (in.fail()) {
			cerr << "���ݴ��������ԣ�" << endl;
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
	cout << "������һЩ��������Ctrl+Z����" << endl;
	func(cin);

	system("pause");
	return 0;
}