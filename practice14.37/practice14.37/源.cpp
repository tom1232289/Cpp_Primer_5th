#include "IntCompare.h"
#include <vector>

int main()
{
	vector<int> iVec = { 1,2,3,2,1 };
	const int oldVal = 2;
	const int newVal = 200;
	replace_if(iVec.begin(), iVec.end(), IntCompare(oldVal), newVal);
	for (auto i : iVec)
		cout << i << " ";
	cout << endl;

	system("pause");
	return 0;
}