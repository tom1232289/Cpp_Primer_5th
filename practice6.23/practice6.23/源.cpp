#include<iostream>
using namespace std;

void print1(const int *p) {
	cout << *p << endl;
}

void print2(const int *p, const int sz) {
	int i = 0;
	while (i != sz) {
		cout << *p++ << endl;
		++i;
	}
}

void print3(const int *b, const int *e) {
	for (auto p = b; p != e; ++p)
		cout << *p << " ";
}

int main()
{
	int i = 0, j[10] = { 0,1,2,3,4,5,6,7,8,9 };
	/*print1(&i);
	print1(j);*/
	/*print2(&i, 1);
	print2(j, sizeof(j)/sizeof(*j));*/
	auto b = cbegin(j);
	auto e = cend(j);
	print3(b, e);
	system("pause");
	return 0;
}