#include<iostream>
#include<fstream>
#include<sstream>
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
	vector<string> words;
	string line;
	while (getline(in, line)) {
		words.push_back(line);
	}
	in.close();

	for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it) {
		istringstream line_str(*it);
		string word;
		while (line_str >> word)
			cout << word << " ";
		cout << endl;
	}

	system("pause"); return 0;
}