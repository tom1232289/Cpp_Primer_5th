#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> ivec = { 0,1,2,3,4,5,6,7,8,9 };
	auto begin = ivec.begin();
	auto end = ivec.end();
	while (begin != end) {
		++begin;
		begin = ivec.insert(begin, 42);
		++begin;
	}

	system("pause"); return 0;
}