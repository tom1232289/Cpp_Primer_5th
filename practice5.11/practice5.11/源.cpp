#include<iostream>
using namespace std;
int main()
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0, tabCnt = 0, newlineCnt = 0,
		ffCnt = 0, flCnt = 0, fiCnt = 0;
	char ch, preCh = '\0';
	while (cin.get(ch)) {
		bool bl = true;
		switch (ch) {
		case'a':case'A':
			++aCnt;
			break;
		case'e':case'E':
			++eCnt;
			break;
		case'i':case'I':
			++iCnt;
			break;
		case'o':case'O':
			++oCnt;
			break;
		case'u':case'U':
			++uCnt;
			break;
		case' ':
			++spaceCnt;
			break;
		case'/t':
			++tabCnt;
			break;
		case'/n':
			++newlineCnt;
			break;
		}
		if (preCh == 'f') {
			switch (ch) {
			case'f':
				++ffCnt;
				bl = false;
				break;
			case'l':
				++flCnt;
				bl = false;
				break;
			case'i':
				++fiCnt;
				bl = false;
				break;
			}
		}
		if (!bl) {
			preCh = '\0';
		}
		else {
			preCh = ch;
		}
	}
	cout << "Number of vowel 'a':" << aCnt << endl;
	cout << "Number of vowel 'e':" << eCnt << endl;
	cout << "Number of vowel 'i':" << iCnt << endl;
	cout << "Number of vowel 'o':" << oCnt << endl;
	cout << "Number of vowel 'u':" << uCnt << endl;
	cout << "Number of space:" << spaceCnt << endl;
	cout << "Number of tab:" << tabCnt << endl;
	cout << "Number of newline:" << newlineCnt << endl;
	cout << "Number of ff:" << ffCnt << endl;
	cout << "Number of fl:" << flCnt << endl;
	cout << "Number of fi:" << fiCnt << endl;
	system("pause");
	return 0;
}