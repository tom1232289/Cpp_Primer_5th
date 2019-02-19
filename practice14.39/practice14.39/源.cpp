#include "StrLenBetween.h"
#include "StrNotShorterThan.h"
#include <vector>
#include <algorithm>

void readString(istream &is, vector<string> &sVec)
{
	string word;
	while (is >> word)
		sVec.push_back(word);
}

int main()
{
	vector<string> sVec;
	readString(cin, sVec);
	cout << "������1~9֮����У�" << count_if(sVec.begin(), sVec.end(), StrLenBetween(1, 9)) <<"��"<< endl;
	cout << "��������10���У�" << count_if(sVec.begin(), sVec.end(), StrNotShorterThan(10)) << "��" << endl;

	system("pause");
	return 0;
}