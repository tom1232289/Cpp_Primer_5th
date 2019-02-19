#include<iostream>
#include<vector>

using namespace std;

vector<int>::iterator search_vec(vector<int>::iterator beg, vector<int>::iterator end, int val) {
	while (beg != end) {
		if (*beg == val)
			return beg;
		++beg;
	}
	return end;
}

int main()
{
	vector<int> ilist = { 1,2,3,4,5,6,7 };
	cout << search_vec(ilist.begin(), ilist.end(), 2) - ilist.begin() + 1 << endl;
	cout << search_vec(ilist.begin(), ilist.end(), 9) - ilist.begin() + 1 << endl;

	system("pause"); return 0;
}