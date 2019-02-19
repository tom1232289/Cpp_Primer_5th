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
	cout << "长度在1~9之间的有：" << count_if(sVec.begin(), sVec.end(), StrLenBetween(1, 9)) <<"个"<< endl;
	cout << "长度在于10的有：" << count_if(sVec.begin(), sVec.end(), StrNotShorterThan(10)) << "个" << endl;

	system("pause");
	return 0;
}