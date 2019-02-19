#include<iostream>
#include<string>
using namespace std;

class Sales_data {
	//Sales_data() = default;
	//Sales_data(const string &book) :bookNo(book) { }
	//Sales_data(const string &book, const unsigned num, const double sellp, const double salep);
public:
	Sales_data(istream &is);
	double avg_price() const{
		if (units_sold)
			return revenue / units_sold;
		else
			return 0;
	}
	string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data &rhs) {
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

istream &read(istream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

Sales_data::Sales_data(istream &is) {
	read(is, *this);
}

ostream &print(ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

int main()
{
	Sales_data total(cin);
	if(cin){
		Sales_data trans(cin);
		while (cin) {
			if (total.isbn() == trans.isbn()) {
				add(total, trans);
			}
			print(cout, total); cout << endl;
		}
		if (total.isbn() == trans.isbn()) {
			print(cout, total); cout << endl;
		}
		print(cout, trans); cout << endl;
	}
	else {
		cerr << "No Data?!" << endl;
		system("pause");
		return -1;
	}
	system("pause");
	return 0;
}
