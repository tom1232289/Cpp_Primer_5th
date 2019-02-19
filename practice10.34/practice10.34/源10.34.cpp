#include<iostream>
#include<iterator>
#include<vector>

using namespace std;

int main()
{
	vector<int> ivec = { 0,1,2,3,4,5,6,7,8,9 };
	for (auto iter = ivec.crbegin(); iter != ivec.crend(); ++iter)
		cout << *iter << " ";
	cout << endl;

	system("pause"); return 0;
}