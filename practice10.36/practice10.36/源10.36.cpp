#include<iostream>
#include<iterator>
#include<algorithm>
#include<list>

using namespace std;

int main()
{
	list<int> ilist = { 0,2,3,32,6,45,32,324,66,9,0,0,5 };
	auto last_z = find(ilist.crbegin(), ilist.crend(), 0);
	++last_z;
	int p = 1;
	for (auto iter = ilist.cbegin(); iter != last_z.base(); ++iter, ++p);
	if (p > ilist.size())
		cout << "������û��0" << endl;
	else
		cout << "���һ��0�ڵ�" << p << "��λ��" << endl;

	system("pause"); return 0;
}