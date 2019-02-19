#include<iostream>
#include<map>
#include<list>
#include<fstream>
#include<sstream>

using namespace std;

int main(int argc,char* argv[])
{
	ifstream in(argv[1]);
	if (!in) {
		cerr << "�޷��������ļ�" << endl;
		exit(1);
	}
	map<string, list<size_t>> word_lineno;
	string line;
	string word;
	size_t lineno = 0;
	while (getline(in, line)) {
		++lineno;
		istringstream l_in(line);
		while (l_in >> word) 
			word_lineno[word].push_back(lineno);
	}
	
	for (const auto &w : word_lineno) {
		cout << w.first << "�����У�";
		for (const auto &i : w.second)
			cout << i << " ";
		cout << endl;
	}

	system("pause"); return 0;
}