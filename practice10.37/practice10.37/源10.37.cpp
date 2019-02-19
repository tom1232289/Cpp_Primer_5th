#include<iostream>
#include<vector>
#include<list>

using namespace std;

int main()
{
	vector<int> ivec = { 0,1,2,3,4,5,6,7,8,9 };
	list<int> ilist;
	copy(ivec.crbegin() + ivec.size() - 7, ivec.crend() - 3 + 1, back_inserter(ilist));
	for (auto c : ilist)
		cout << c << " ";
	cout << endl;

	system("pause"); return 0;
}