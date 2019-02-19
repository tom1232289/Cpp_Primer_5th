#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> ivec = { 1,2,3,4,5,6,7 }, ivec2;
	int i;
	while (cin >> i)
		ivec2.push_back(i);
	if (ivec == ivec2)
		cout << "ivec==ivec2" << endl;
	else if (ivec < ivec2)
		cout << "ivec<ivec2" << endl;
	else 
		cout << "ivec>ivec2" << endl;

	system("pause"); return 0;
}