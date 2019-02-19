#include<iostream>
using namespace std;
int main()
{
	cin.tie(&cout);
	ostream *old_tie = cin.tie(nullptr);
	cin.tie(&cerr);
	cin.tie(old_tie);

	system("pause");
	return 0;
}