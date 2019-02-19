#include<iostream>
#include<iterator>
#include<vector>

using namespace std;

int main()
{
	vector<int> ivec;
	ostream_iterator<int> out_iter(cout, " ");
	//for (auto e : ivec)
	//	*out_iter++ = e;
	copy(ivec.begin(), ivec.end(), out_iter);
	cout << endl;
}