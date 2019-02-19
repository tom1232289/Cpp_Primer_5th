#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	vector<string> str = { "The is C++ program ","hfh ","","hfdshfisoid" };
	for (auto it = str.begin(); it != str.end() && !it->empty(); ++it)
	{
		cout << *it << endl;
		for (auto st = (*it).begin(); st != (*it).end(); ++st)
		{
			*st = toupper(*st);
		}
		cout << *it << endl;
	}
	system("pause");
	return 0;
}