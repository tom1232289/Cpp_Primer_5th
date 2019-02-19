#include<iostream>
#include<list>
#include<forward_list>

using namespace std;

int main()
{
	list<int> ilist = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter = ilist.begin();
	while (iter != ilist.end()) {
		if (*iter % 2) {
			iter = ilist.insert(iter, *iter);
			++iter; ++iter;
		}
		else 
			iter = ilist.erase(iter);
	}
	for (auto c : ilist)
		cout << c << " ";
	cout << endl;

	forward_list<int> iflist = { 0,10,1,10,2,3,4,5,6,7,8,9 };
	auto prev = iflist.before_begin();
	auto curr = iflist.begin();
	while (curr != iflist.end()) {
		if (*curr % 2) {
			curr = iflist.insert_after(curr, *curr);
			prev = curr;
			++curr;
		}
		else 
			curr = iflist.erase_after(prev);
	}
	for (auto c : iflist)
		cout << c << " ";
	cout << endl;

	system("pause"); return 0;
}