#include<iostream>
#include<fstream>
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