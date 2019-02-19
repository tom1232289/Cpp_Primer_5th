#include<iostream>
#include<fstream>
#include"F:\c++ primer\test1\test1\Sales_data.h"
using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 3) {
		cerr << "请给出输入、输出文件名" << endl;
		system("pause"); return -1;
	}
	ifstream in(argv[1]);
	if (!in) {
		cerr << "无法打开输入文件" << endl;
		system("pause"); return -1;
	}
	ofstream out(argv[2], ostream::app);
	if (!out) {
		cerr << "无法打开输出文件" << endl;
		system("pause"); return -1;
	}

	Sales_data total;
	if (read(in, total)) {
		Sales_data trans;
		while (read(in, trans)) {
			if (total.isbn() == trans.isbn())
				total = add(total, trans);
			else {
				print(out, total) << endl;	// 注意：out输出到文件，cout输出到控制台
				total = trans;
			}
		}
		print(out, total) << endl;
	}
	else
		cerr << "没有数据" << endl;

	system("pause"); return 0;
}
