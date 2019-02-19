#include<iostream>
#include<string>

using namespace std;

void find_char(string &s, const string &chars) {
	string::size_type pos = 0;
	while ((pos = s.find_first_of(chars, pos)) != string::npos) {
		cout << "pos:" << pos << ",chars:" << s[pos] << endl;
		++pos;
	}
}

void find_not_char(string &s, const string &chars) {
	string::size_type pos = 0;
	while ((pos = s.find_first_not_of(chars, pos)) != string::npos) {
		cout << "pos:" << pos << ",chars:" << s[pos] << endl;
		++pos;
	}
}

int main()
{
	string s = { "ab2c3d7R4E6" };
	cout << "查找所有数字：" << endl;
	string numbers = { "0123456789" };
	string alphabet = { "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
//	find_char(s, numbers);
	find_not_char(s, alphabet);
	cout << "查找所有字母：" << endl;
//	find_char(s, alphabet);
	find_not_char(s, numbers);

	system("pause"); return 0;
}