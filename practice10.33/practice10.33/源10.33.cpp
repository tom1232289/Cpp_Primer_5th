#include<iostream>
#include<fstream>
#include<iterator>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 4) {
		cout << "参数错误" << endl;
		system("pause"); return -1;
	}
	ifstream in(argv[1]);
	if (!in) {
		cerr << "无法打开输入文件" << endl;
		system("pause"); return -1;
	}
	ofstream out1(argv[2]);
	if (!out1) {
		cerr << "无法打开输出文件1" << endl;
		system("pause"); return -1;
	}
	ofstream out2(argv[3]);
	if (!out2) {
		cerr << "无法打开输出文件2" << endl;
		system("pause"); return -1;
	}
	istream_iterator<int> int_iter(in), eof;
	ostream_iterator<int> out1_iter(out1, " ");
	ostream_iterator<int> out2_iter(out2, "\n");
	for (; int_iter != eof; ++int_iter) {
		if (*int_iter % 2) {
			*out1_iter++ = *int_iter;
		}
		else
			*out2_iter++ = *int_iter;
	}

	system("pause"); return 0;
}