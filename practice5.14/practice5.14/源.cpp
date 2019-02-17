#include<iostream>
#include<string>
using namespace std;
int main()
{
	string currString, preString = "", maxString;
	int currCnt = 1, maxCnt = 0;
	while (cin >> currString) {
		if (currString == preString) {
			++currCnt;
			if (currCnt > maxCnt) {
				maxCnt = currCnt;
				maxString = currString;
			}
		}
		else {
			preString = currString;
			currCnt = 1;
		}
	}
	if (maxCnt > 1) {
		cout << maxString << "连续出现了" << maxCnt << "次。" << endl;
	}
	else {
		cout << "任何单词都没有连续出现过。" << endl;
	}
	system("pause");
	return 0;
}