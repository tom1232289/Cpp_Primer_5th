#include<iostream>
using namespace std;
int main()
{
	auto old_state = cin.rdstate();
	cin.clear();
	process_input(cin);
	cin.setstate(old_state);

	system("pause");
	return 0;
}