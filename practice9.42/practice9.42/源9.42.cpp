#include<iostream>
#include<string>

using namespace std;

void input_string(string &s) {
	s.reserve(100);
	char c;
	while (cin >> c)
		s.push_back(c);
}

int main()
{
	string str;
	input_string(str);
	cout << str << endl;

	system("pause"); return 0;
}