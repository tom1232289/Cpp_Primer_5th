#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> ivec(21);
	vector<int>::size_type cnt = ivec.size();
	for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--) {
		ivec[ix] = cnt;
	}
	for (auto c : ivec) {
		cout << c << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}