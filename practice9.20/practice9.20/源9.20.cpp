#include<iostream>
#include<list>
#include<deque>

using namespace std;

int main()
{
	list<int> ilist = { 1,2,3,4,5,6,7,8,9,10 };
	deque<int> ideq_even, ideq_odd_number;
	for (auto c : ilist) {
		if (c & 1)	// 用位于运算符查看最低位，1：奇数，0：偶数(和%2运算是等价的)
			ideq_odd_number.push_back(c);
		else
			ideq_even.push_back(c);
	}
	for (auto c : ideq_even)
		cout << c << " ";
	cout << endl;

	for (auto c : ideq_odd_number)
		cout << c << " ";
	cout << endl;

	system("pause"); return 0;
}