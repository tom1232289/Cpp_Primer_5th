#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> ivec;
	int s, c;
	for (s = ivec.size(), c = ivec.capacity(); s <= c; ++s)
		ivec.push_back(1);
	cout << "�ռ䣺" << ivec.capacity() << " Ԫ������" << ivec.size() << endl;
	for (s = ivec.size(), c = ivec.capacity(); s <= c; ++s)
		ivec.push_back(1);
	cout << "�ռ䣺" << ivec.capacity() << " Ԫ������" << ivec.size() << endl;
	for (s = ivec.size(), c = ivec.capacity(); s <= c; ++s)
		ivec.push_back(1);
	cout << "�ռ䣺" << ivec.capacity() << " Ԫ������" << ivec.size() << endl;
	for (s = ivec.size(), c = ivec.capacity(); s <= c; ++s)
		ivec.push_back(1);
	cout << "�ռ䣺" << ivec.capacity() << " Ԫ������" << ivec.size() << endl;
	for (s = ivec.size(), c = ivec.capacity(); s <= c; ++s)
		ivec.push_back(1);
	cout << "�ռ䣺" << ivec.capacity() << " Ԫ������" << ivec.size() << endl;
	for (s = ivec.size(), c = ivec.capacity(); s <= c; ++s)
		ivec.push_back(1);
	cout << "�ռ䣺" << ivec.capacity() << " Ԫ������" << ivec.size() << endl;


	system("pause"); return 0;
}