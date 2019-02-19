#include<iostream>

using namespace std;

void add(int a) {
	auto sum = [a](int b) {return a + b; };
	int i;
	cin >> i;
	cout << sum(i) << endl;
}

int main()
{
	add(1);
	add(2);

	system("pause"); return 0;
}