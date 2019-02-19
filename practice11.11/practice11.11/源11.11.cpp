#include<iostream>
#include<set>
#include"F:\c++ primer\test1\test1\Sales_data.h"

using namespace std;

typedef bool(*pf)(Sales_data &, Sales_data &);

bool compareIsbn(Sales_data &lhs, Sales_data &rhs) {
	return lhs.isbn() < rhs.isbn();
}

int main()
{
	multiset<Sales_data, pf> bookstore(compareIsbn);

	system("pause"); return 0;
}