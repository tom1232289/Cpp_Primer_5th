#include"TextQuery.h"
#include"QueryResult.h"

using namespace std;

void runQuery(ifstream &input_file) {
	TextQuery tq(input_file);
	while (true) {
		cout << "enter word to query or CTRL+Z to quit" << endl;
		string sought;
		if (!(cin >> sought)) {
			break;
		}
		QueryResult qr = tq.query(sought);
		print(cout, qr) << endl;
	}
}

int main(int argc, char* argv[])
{
	if (argc < 2) {
		cerr << "no input file" << endl;
		system("pause");
		return -1;
	}
	ifstream input_file(argv[1]);
	if (!input_file) {
		cerr << "can not open input file" << endl;
		system("pause");
		return -1;
	}
	runQuery(input_file);

	return 0;
}