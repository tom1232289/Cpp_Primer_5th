#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	vector<int> ilist1;
	vector<int> ilist2 = ilist1;
	vector<int> ilist3 = { 1,2,3,4,5,6,7 };
	vector<int> ilist4(ilist3.begin() + 2, ilist3.end() - 1);
	vector<int> ilist5(10);
	vector<int> ilist6(10, 1);

	system("pause"); return 0;
}