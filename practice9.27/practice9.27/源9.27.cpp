#include<iostream>
#include<forward_list>

using namespace std;

int main()
{
	forward_list<int> flst = { 0,1,2,3,4,5,6,7,8,9 };
	auto prev = flst.cbefore_begin();
	auto curr = flst.cbegin();
	while (curr != flst.cend()) {
		if (*curr % 2)	// ��Ԫ��Ϊ����
			curr = flst.erase_after(prev);
		else {
			prev = curr;
			++curr;
		}
	}
	for (auto c : flst)
		cout << c << " ";
	cout << endl;

	system("pause"); return 0;
}
