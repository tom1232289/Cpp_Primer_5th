#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	ifstream in("C:\\Users\\lenovo\\Desktop\\infile����.txt");
	if (!in) {
		cerr << "�޷��������ļ�" << endl;
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