#include<iostream>
#include<vector>

using namespace std;

bool search_vec(vector<int>::iterator beg, vector<int>::iterator end, int val) {
	while (beg != end) {
		if (*beg == val)
			return true;
		++beg;
	}
	return false;
}

int main()
{
	vector<int> ilist = { 1,2,3,4,5,6,7 };
	cout << search_vec(ilist.begin(), ilist.end(), 2) << endl;
	cout << search_vec(ilist.begin(), ilist.end(), 8) << endl;

	system("pause"); return 0;
}