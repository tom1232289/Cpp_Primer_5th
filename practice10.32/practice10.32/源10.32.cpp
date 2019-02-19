#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<numeric>
#include"F:\c++ primer\test1\test1\Sales_item.h"

using namespace std;

inline bool compareISBN(const Sales_item &lhs, const Sales_item &rhs) {
	return lhs.isbn() < rhs.isbn();
}

int main()
{
	istream_iterator<Sales_item> item_iter(cin), eof;
	vector<Sales_item> itemvec(item_iter, eof);
	if (itemvec.empty()) {
		cerr << "No data?!" << endl;
		system("pause"); return -1;
	}
	sort(itemvec.begin(), itemvec.end(), compareISBN);
	auto l = itemvec.begin();
	while (l != itemvec.end()) {
		auto item = *l;
		auto r = find_if(l + 1, itemvec.end(), [item](const Sales_item &item1) { return item.isbn() != item1.isbn(); });
		cout << accumulate(l + 1, r, item) << endl;
		l = r;
	}

	system("pause"); return 0;
}