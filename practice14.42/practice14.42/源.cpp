#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using namespace std::placeholders;

int main()
{
	vector<int> iVec{ 213,2134,214321,4,214,312,421,43,21,4,124,312,412,4353532,32134,124 };
	vector<string> sVec{ "pooh", "pooh", "pooh", "asd" };
	cout << count_if(iVec.begin(), iVec.end(), bind(greater<int>(), _1, 1024)) << endl;
	cout << *find_if(sVec.begin(), sVec.end(), bind(not_equal_to<string>(), _1, "pooh")) << endl;
	transform(iVec.begin(), iVec.end(), iVec.begin(), bind(multiplies<int>(), _1, 2));
	for (auto i : iVec)
		cout << i << " ";
	cout << endl;

	system("pause");
	return 0;
}