#include<iostream>
#include<list>
#include<vector>

using namespace std;

int main()
{
	list<int> ilist1 = { 1,2,3,4 };
	vector<double> ilist2(ilist1.begin(), ilist1.end());
	vector<int> ilist3 = { 5,6,7,8,9 };
	vector<double> ilist4(ilist3.begin(), ilist3.end());

	cout << ilist2.capacity() << " " << ilist2.size() << endl;
	for (auto c : ilist2) {
		cout << c << " ";
	}
	cout << endl;
	cout << ilist4.capacity() << " " << ilist4.size() << endl;
	for (auto c : ilist4) {
		cout << c << " ";
	}
	cout << endl;

	system("pause"); return 0;
}