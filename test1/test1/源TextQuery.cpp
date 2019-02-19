#include "TextQuery.h"

void runQuery(ifstream & infile) {
	TextQuery tq(infile);
	while (true) {
		cout << "enter word to query or q to quit:" << endl;
		string s;
		if (!(cin >> s) || s == "q")
			break;
		print(cout, tq.query(s)) << endl;
	}
}

int main(int argc, char *argv[])
{
	ifstream infile;
	if (argc < 2 || !(infile.open(argv[1]), infile)) {
		cerr << "No data?" << endl;
		return -1;
	}
	runQuery(infile);

	system("pause");
	return 0;
}