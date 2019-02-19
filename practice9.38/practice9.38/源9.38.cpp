#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> ivec;
	int s, c;
	for (s = ivec.size(), c = ivec.capacity(); s <= c; ++s)
		ivec.push_back(1);
	cout << "空间：" << ivec.capacity() << " 元素数：" << ivec.size() << endl;
	for (s = ivec.size(), c = ivec.capacity(); s <= c; ++s)
		ivec.push_back(1);
	cout << "空间：" << ivec.capacity() << " 元素数：" << ivec.size() << endl;
	for (s = ivec.size(), c = ivec.capacity(); s <= c; ++s)
		ivec.push_back(1);
	cout << "空间：" << ivec.capacity() << " 元素数：" << ivec.size() << endl;
	for (s = ivec.size(), c = ivec.capacity(); s <= c; ++s)
		ivec.push_back(1);
	cout << "空间：" << ivec.capacity() << " 元素数：" << ivec.size() << endl;
	for (s = ivec.size(), c = ivec.capacity(); s <= c; ++s)
		ivec.push_back(1);
	cout << "空间：" << ivec.capacity() << " 元素数：" << ivec.size() << endl;
	for (s = ivec.size(), c = ivec.capacity(); s <= c; ++s)
		ivec.push_back(1);
	cout << "空间：" << ivec.capacity() << " 元素数：" << ivec.size() << endl;


	system("pause"); return 0;
}