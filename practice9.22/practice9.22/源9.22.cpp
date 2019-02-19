#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> iv = { 1,1,4,1 };
	int some_val = 1;
	auto iter = iv.cbegin();
	int org_size = iv.size();
	int i = 0;
	while (i <= org_size / 2) {
		if (*iter == some_val) {
			iter = iv.insert(iter, 2 * some_val);
			++iter; ++iter;
		}
		else
			++iter;
		++i;
	}
	for (auto c : iv)
		cout << c << " ";
	cout << endl;

	system("pause"); return 0;
}