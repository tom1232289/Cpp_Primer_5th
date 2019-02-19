#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<string>

using namespace std;

int main(int argc,char* argv[])
{
	ifstream in(argv[1]);
	if (!in) {
		cerr << "无法读取输入文件" << endl;
		system("pause"); return -1;
	}
	istream_iterator<string> str_iter(in), eof;
	vector<string> svec(str_iter, eof);
	for (auto c : svec)
		cout << c << " ";
	cout << endl;

	system("pause"); return 0;
}