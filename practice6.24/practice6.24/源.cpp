#include<iostream>
#include<ctime>
#include<vector>

using namespace std;

//void print(const int ia[10]) {
//	for (size_t i = 0; i != 10; ++i)
//		cout << ia[i] << endl;
//}

void print(const int *b,const int *e) {
	for (auto p = b; p != e; ++p)
		cout << *p << " ";
}

int main()
{
	int a[9];
	srand((unsigned)time(NULL));
	for (auto &c : a)
		c = rand() % 100;
	auto b = cbegin(a), e = cend(a);
	print(b,e);
	system("pause");
	return 0;
}