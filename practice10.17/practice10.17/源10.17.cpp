#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include"F:\c++ primer\test1\test1\Sales_data.h"

//inline bool compareIsbn(Sales_data &lhs, Sales_data &rhs) {
//	return lhs.isbn() < rhs.isbn();
//}

int main(int argc, char* argv[])
{
	ifstream in(argv[1]);
	if (!in) {
		cerr << "无法打开输入文件" << endl;
		return -1;
	}

	vector<Sales_data> sds;
	Sales_data sd;
	while (read(in, sd))
		sds.push_back(sd);

	sort(sds.begin(), sds.end(), [](Sales_data &lhs, Sales_data &rhs) { return lhs.isbn() < rhs.isbn(); });

	for (const auto &c : sds) {
		print(cout, c);
		cout << endl;
	}

	system("pause"); return 0;
}