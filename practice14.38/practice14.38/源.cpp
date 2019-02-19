#include "StrLenIs.h"
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
	for (size_t i = 1; i != 10; ++i) {
		cout << "length:" << i << " count:" << count_if(sVec.begin(), sVec.end(), StrLenIs(i)) << endl;
	}

	system("pause");
	return 0;
}