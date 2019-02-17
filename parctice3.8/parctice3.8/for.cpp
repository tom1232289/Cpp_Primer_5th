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
	for (string::size_type n = 0; n < str.size(); ++n)
		str[n] = 'X';
	cout << str << endl;
	system("pause");
	return 0;
}