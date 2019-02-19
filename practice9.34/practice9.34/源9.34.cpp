#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> ivec = { 0,1,2,3,4,5,6,7,8,9,9,10,10 };
	auto iter = ivec.begin();
	while (iter != ivec.end()) {
		if (*iter % 2)
			iter = ivec.insert(iter, *iter);
		++iter;
	}
	for (auto c : ivec)
		cout << c << " ";
	cout << endl;

	system("pause"); return 0;
}