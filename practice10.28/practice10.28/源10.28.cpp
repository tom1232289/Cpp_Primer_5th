#include<iostream>
#include<vector>
#include<iterator>
#include<list>
#include<algorithm>

using namespace std;

void output(list<int> &ilist) {
	for (auto c : ilist)
		cout << c << " ";
	cout << endl;
}

int main()
{
	vector<int> ivec = { 1,2,3,4,5,6,7,8,9 };
	list<int> ilist1, ilist2, ilist3;
	unique_copy(ivec.cbegin(), ivec.cend(), inserter(ilist1, ilist1.begin()));
	output(ilist1);
	unique_copy(ivec.cbegin(), ivec.cend(), back_inserter(ilist2));
	output(ilist2);
	unique_copy(ivec.cbegin(), ivec.cend(), front_inserter(ilist3));
	output(ilist3);

	system("pause"); return 0;
}