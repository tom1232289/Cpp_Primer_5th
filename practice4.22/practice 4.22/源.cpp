#include<iostream>
#include<ctime>
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	int grade = rand() & 100;
	cout << grade << endl;
	string finalgrade;
	if (grade > 90) {
		finalgrade = { "high pass" };
	}
	else if (grade > 75) {
		finalgrade = { "pass" };
	}
	else if (grade > 60) {
		finalgrade = { "low pass" };
	}
	else {
		finalgrade = { "fail" };
	}
	for (auto c : finalgrade) {
		cout << c;
	}
	cout << endl;
	system("pause");
	return 0;
}