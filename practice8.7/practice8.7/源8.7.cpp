#include<iostream>
#include<fstream>
#include"F:\c++ primer\test1\test1\Sales_data.h"
using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 3) {
		cerr << "��������롢����ļ���" << endl;
		system("pause"); return -1;
	}
	ifstream in(argv[1]);
	if (!in) {
		cerr << "�޷��������ļ�" << endl;
		system("pause"); return -1;
	}
	ofstream out(argv[2], ostream::app);
	if (!out) {
		cerr << "�޷�������ļ�" << endl;
		system("pause"); return -1;
	}

	Sales_data total;
	if (read(in, total)) {
		Sales_data trans;
		while (read(in, trans)) {
			if (total.isbn() == trans.isbn())
				total = add(total, trans);
			else {
				print(out, total) << endl;	// ע�⣺out������ļ���cout���������̨
				total = trans;
			}
		}
		print(out, total) << endl;
	}
	else
		cerr << "û������" << endl;

	system("pause"); return 0;
}
