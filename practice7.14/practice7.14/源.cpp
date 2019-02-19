#include<iostream>
#include<string>
using namespace std;

class Sales_data {
public:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	//¹¹Ôìº¯Êý
	Sales_data(const string &book) :bookNo(book),units_sold(2),revenue(22.2){}
};

ostream& print(ostream &os, const Sales_data &item) {
	os << item.bookNo << " " << item.units_sold << " " << item.revenue;
	return os;
}

int main()
{
	Sales_data trans("cc");
	print(cout, trans); cout << endl;
	system("pause");
	return 0;
}