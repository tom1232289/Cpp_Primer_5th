#include<iostream>
#include<vector>
#include<list>

using namespace std;

bool l_v_equal(list<int> &ilist, vector<int> &ivec) {
	if (ilist.size() != ivec.size())
		return false;
	auto lb = ilist.cbegin();
	auto le = ilist.cend();
	auto vb = ivec.cbegin();
	auto ve = ivec.cend();
	for (; lb != le; ++lb, ++vb) {
		if (*lb != *vb)
			return false;
	}
	return true;
}

int main()
{
	list<int> ilist = { 1,2,3,4,5,6,7 };
	vector<int> ivec1 = { 1,2,3,4,5,6,7 };
	vector<int> ivec2 = { 1,2,3,4,5 };
	vector<int> ivec3 = { 1,2,3,4,5,6,7,8 };
	vector<int> ivec4 = { 1,2,3,4,5,7,6 };

	cout << l_v_equal(ilist, ivec1) << endl;
	cout << l_v_equal(ilist, ivec2) << endl;
	cout << l_v_equal(ilist, ivec3) << endl;
	cout << l_v_equal(ilist, ivec4) << endl;

	system("pause"); return 0;
}