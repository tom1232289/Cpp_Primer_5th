#include<iostream>	
#include<vector>
#include<string>
using namespace std;
int main()
{
	const vector<string> scores = { "F","D","C","B","A","A++" };
	unsigned grade = 0;
	string lettergrade;
	cin >> grade;
	if (grade <= 100) {
		if (grade < 60) {
			lettergrade = scores[0];
		}
		else {
			lettergrade = scores[(grade - 50) / 10];
			if (grade != 100) {
				if (grade % 10 < 3) {
					lettergrade += '-';
				}
				else if (grade % 10 > 7) {
					lettergrade += '+';
				}
			}
		}
	}
	cout << lettergrade << endl;
	system("pause");
	return 0;
}
			