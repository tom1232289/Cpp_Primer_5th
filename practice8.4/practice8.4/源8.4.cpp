#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	ifstream in("C:\\Users\\lenovo\\Desktop\\infile备份.txt");
	if (!in) {
		cerr << "无法打开输入文件" << endl;
		system("pause"); return -1;
	}

	string line;
	vector<string> words;
	while (getline(in, line)) {
		words.push_back(line);
	}

	in.close();

	for (auto c : words) {
		cout << c << endl;
	}

	system("pause"); return 0;
}