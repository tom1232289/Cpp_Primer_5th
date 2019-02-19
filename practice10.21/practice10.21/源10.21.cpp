#include<iostream>
#include<algorithm>

using namespace std;

void mutable_lambda(int i) {
	auto f = [i]() mutable -> bool {if (i > 0) { --i; return false; } else return true; };
	for (int j = 0; j <= i; ++j)
		cout << f() << " ";
	cout << endl;
}

int main()
{
	mutable_lambda(1000);

	system("pause"); return 0;
}