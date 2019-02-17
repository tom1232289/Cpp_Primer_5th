#include<iostream>
#include<ctime>
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	int grade = rand() & 100;
	cout << grade << endl;
	string finalgrade;
	finalgrade = (grade > 90) ? "high pass" : (grade > 75) ? "pass" : (grade > 60) ? "low pass" : "fail";
	for (auto c : finalgrade) {
		cout << c;
	}
	cout << endl;
	system("pause");
	return 0;
}