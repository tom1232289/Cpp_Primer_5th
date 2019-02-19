#include<iostream>
#include<sstream>
using namespace std;

istream& func(istream& in) {
	string v;
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
	ostringstream msg;
	msg << "C++ Primer 5th" << endl;
	istringstream in(msg.str());
	func(in);

	system("pause"); return 0;
}