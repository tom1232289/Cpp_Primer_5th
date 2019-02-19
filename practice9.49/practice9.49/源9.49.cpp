#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void find_longest_word(ifstream &in) {
	string word, longest_word;
	int max_length = 0;
	while (in >> word) {
		if (word.find_first_of("bdfghjklpqty") != string::npos)
			continue;
		cout << word << " ";
		if (max_length < word.size()) {
			max_length = word.size();
			longest_word = word;
		}
	}
	cout << endl << "最长字符串：" << longest_word << endl;
}

int main(int argc,char *argv[])
{
	ifstream in(argv[1]);
	if (!in) {
		cerr << "无法打开输入文件" << endl;
		system("pause"); return -1;
	}
	find_longest_word(in);

	system("pause"); return 0;
}