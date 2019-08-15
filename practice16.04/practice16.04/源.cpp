#include <vector>
#include <list>
#include <string>
#include <iostream>

using namespace std;

template <typename I,typename T>
I find(I first,I last,const T &val)
{
	for (; first != last; ++first) {
		if (*first == val)
			return first;
	}
	return last;
}

int main()
{
	vector<int> ivec = { 2,3,5,1,4,7 };
	const int val = 2;
	auto iter = ::find(ivec.begin(), ivec.end(), val);
	if (iter == ivec.end())
		cout << "can not find " << val << endl;
	else 
		cout << "find " << val << " at position " << iter - ivec.begin() << endl;

	list<string> sList = { "a","hello","123" };
	const string str = "hello";
	auto iter2 = ::find(sList.begin(), sList.end(), str);
	if (iter2 == sList.end())
		cout << "can not find " << str << endl;
	else
		cout << "find " << str << endl;

	return 0;
}