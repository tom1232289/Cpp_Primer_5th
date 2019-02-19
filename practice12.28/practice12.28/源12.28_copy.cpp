#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<map>
#include<set>

using namespace std;

using line_no = vector<string>::size_type;

vector<string> file;
map<string, set<line_no>> wm;

string cleanup_str(const string &word) {
	string ret;
	for (auto it = word.begin(); it != word.end(); ++it) {
		if (!ispunct(*it)) {
			ret += tolower(*it);
		}
	}
	return ret;
}


void input_text(ifstream &infile) {
	string text;
	while (getline(infile, text)) {
		file.push_back(text);
		int n = file.size() - 1;
		istringstream line(text);
		string word;
		while (line >> word) {
			wm[cleanup_str(word)].insert(n);
		}
	}
}

ostream &query_and_print(const string &sought, ostream &os) {
	auto loc = wm.find(sought);
	if (loc == wm.end()) {
		os << sought << "û�г���" << endl;
	}
	else {
		auto lines = loc->second;
		os << sought << "������" << lines.size() << "��" << endl;
		for (auto num : lines) {
			os << "\t(��" << num + 1 << "��)" << *(file.begin() + num) << endl;
		}
	}
	return os;
}

void runQuery(ifstream &infile) {
	input_text(infile);
	while (true) {
		cout << "enter word to look for, or q to quit:" << endl;
		string sought;
		if (!(cin >> sought) || sought == "q") {
			break;
		}
		query_and_print(sought, cout) << endl;
	}
}


int main(int argc,char* argv[])
{
	ifstream infile(argv[1]);
	if (argc < 2) {
		cerr << "û�������ļ�" << endl;
		return -1;
	}
	if (!infile) {
		cerr << "�޷��������ļ�" << endl;
		return -1;
	}

	runQuery(infile);

	system("pause");
	return 0;
}