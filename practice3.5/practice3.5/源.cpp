#include<iostream>	
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
	string st1, st2;
	if (cin >> st1) {
		while (cin >> st2) {
		//	st1 += st2;
			st1 = st1 + " " + st2;
		}
		cout << st1 << endl;
	}
	else {
		cout << "No data" << endl;
		system("pause");
		return -1;
	}
	system("pause");
	return 0;
}