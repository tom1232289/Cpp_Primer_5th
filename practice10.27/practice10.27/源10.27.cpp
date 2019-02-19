#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<iterator>

using namespace std;

int main()
{
	vector<int> ivec = { 0,1,2,3,4,5,6,7,8,9,4,3,6,2,5,2 };
	list<int> ilist;
	sort(ivec.begin(), ivec.end());
	unique_copy(ivec.cbegin(), ivec.cend(), back_inserter(ilist));
	for (auto c : ilist)
		cout << c << " ";
	cout << endl;

	system("pause"); return 0;
}