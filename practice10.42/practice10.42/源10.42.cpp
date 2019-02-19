#include<iostream>
#include<list>
#include<string>
#include<algorithm>

using namespace std;

void elimDups(list<string> &words) {
	words.sort();
	words.unique();
}

int main()
{
	list<string> slist = { "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	elimDups(slist);
	for (auto c : slist)
		cout << c << " ";
	cout << endl;

	system("pause"); return 0;
}