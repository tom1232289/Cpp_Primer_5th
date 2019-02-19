#include<iostream>
#include<vector>
#include<list>

using namespace std;

int main()
{
	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
	vector<int> ivec;
	list<int> ilist;
	ivec.assign(ia, ia + 11);
	ilist.assign(ia, ia + 11);
	for (auto c : ilist)
		cout << c << " ";
	cout << endl;
	auto it1 = ilist.cbegin();
	while (it1 != ilist.cend()) {
		if (*it1 % 2 != 0)
			it1 = ilist.erase(it1);
		else
			++it1;
	}
	for (auto c : ilist)
		cout << c << " ";
	cout << endl;
	for (auto c : ivec)
		cout << c << " ";
	cout << endl;
	auto it2 = ivec.cbegin();
	while (it2 != ivec.cend()) {
		if (*it2 % 2 == 0)
			it2 = ivec.erase(it2);
		else
			++it2;
	}
	for (auto c : ivec)
		cout << c << " ";
	cout << endl;

	system("pause"); return 0;
}