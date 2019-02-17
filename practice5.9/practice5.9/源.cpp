#include<iostream>
using namespace std;
int main()
{
	unsigned vowelCnt = 0;
	char ch;
	while (cin >> ch) {
		if (ch == 'a' || ch == 'i' || ch == 'o' || ch == 'e' || ch == 'u') {
			++vowelCnt;
		}
	}
	cout << "Numbel of vowel:" << vowelCnt << endl;
	system("pause");
	return 0;
}