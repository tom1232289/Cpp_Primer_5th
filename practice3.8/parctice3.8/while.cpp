#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
	string str("Hello World!");
	cout << str << endl;
	decltype(str.size()) n = 0;
	while (str[n]) {
		str[n] = 'X';
		++n;
	}
	cout << str << endl;
	system("pause");
	return 0;
}