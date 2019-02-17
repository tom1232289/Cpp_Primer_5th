#include<iostream>
#include<string>
using namespace std;
int main()
{
	string st1("A string example"), st2("A different string");
	if (st1 < st2) {
		cout << "第一个字符串小于第二个字符串。" << endl;
	}
	if(st1>st2){
		cout << "第一个字符串大于第二个字符串。" << endl;
	}
	else {
		cout << "两个字符串相等。" << endl;
	}
	const char ca1[] = "A string example", ca2[] = "A different string";
	if (strcmp(ca1, ca2) < 0) {
		cout << "第一个字符串小于第二个字符串。" << endl;
	}
	if (strcmp(ca1, ca2) > 0) {
		cout << "第一个字符串大于第二个字符串。" << endl;
	}
	else {
		cout << "两个字符串相等。" << endl;
	}
	system("pause");
	return 0;
}