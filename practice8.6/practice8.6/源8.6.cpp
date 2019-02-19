#include<iostream>
#include<fstream>
#include"Sales_data.h"
using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 2) {
		cerr << "������ļ���" << endl;
		system("pause"); return -1;
	}
	ifstream in(argv[1]);
	if (!in) {
		cerr << "�޷��������ļ�" << endl;
		system("pause"); return -1;
	}

	Sales_data total;
	if (read(in, total)) {
		Sales_data trans;
		while (read(in, trans)) {
			if (total.isbn() == trans.isbn())
				add(total, trans);
			else {
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else 
		cerr << "û������" << endl;
	
	system("pause"); return 0;
}
