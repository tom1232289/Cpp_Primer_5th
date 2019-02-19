#include<iostream>
#include<iterator>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	istream_iterator<int> int_iter(cin), eof;
	vector<int> ivec(int_iter, eof);
	sort(ivec.begin(), ivec.end());
	ostream_iterator<int> out_iter(cout, " ");
	copy(ivec.begin(), ivec.end(), out_iter);

	system("pause"); return 0;
}