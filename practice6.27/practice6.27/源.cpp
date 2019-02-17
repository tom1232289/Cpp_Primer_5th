#include<iostream>

using namespace std;

int myAdd(initializer_list<int> ii) {
	int count = 0;
	for (auto val:ii)
		count += val;
	return count;
}

int main()
{
	int a = 1, b = 2, c = 3, d = 4;
	cout << myAdd({ a,b,c,d,5 }) << endl;
	system("pause");
	return 0;
}