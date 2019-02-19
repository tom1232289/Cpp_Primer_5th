#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool five_or_more(string &s) {
	return s.size() > 5;
}

int main()
{
	vector<string> svec = { "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	auto iter = partition(svec.begin(), svec.end(), five_or_more);
	for (auto beg = svec.begin(); beg != iter; ++beg) 
		cout << *beg << " ";
	cout << endl;

	system("pause"); return 0;
}