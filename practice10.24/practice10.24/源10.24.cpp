#include<iostream>
#include<vector>
#include<string>
#include<functional>
#include<algorithm>

using namespace std;
using namespace placeholders;

bool check_size(const string &s, size_t sz) {
	return s.size() <= sz;
}
//
int main()
{
	vector<int> ivec = { 0,1,2,3,4,5,6,7,8,9 };
	string s = "abc";
	auto p = find_if(ivec.begin(), ivec.end(), bind(check_size, s, _1));
	cout << "第" << p - ivec.begin() + 1 << "个数" << *p << ">=" << s << "的长度" << endl;

	system("pause"); return 0;
}