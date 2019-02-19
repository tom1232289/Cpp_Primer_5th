#include<iostream>
#include<string>
using namespace std;

class Sales_data {
public:
	Sales_data() = default;
	Sales_data(const string &book):bookNo(book) { }
	Sales_data(const string &book, const unsigned num, const double sellp, const double salep);
	Sales_data(istream &is);
public:
	string bookNo;
	unsigned units_sold = 0;
	double sellingprice = 0.0;
	double saleprice = 0.0;
	double discount = 0.0;
};
istream &read(istream &is, Sales_data &item) {
	is >> item.bookNo >> item.units_sold >> item.sellingprice >> item.saleprice;
	return is;
}

ostream &print(ostream &os, Sales_data &item) {
	os << item.bookNo << " " << item.units_sold << " " << item.sellingprice << " " << item.saleprice << " " << item.discount;
	return os;
}

Sales_data::Sales_data(const string &book, const unsigned num, const double sellp, const double salep) {
	bookNo = book;
	units_sold = num;
	sellingprice = sellp;
	saleprice = salep;
	if (sellingprice != 0)
		discount = saleprice / sellingprice;
}

Sales_data::Sales_data(istream &is) {
	read(is, *this);
}


int main()
{
	Sales_data data1;
	Sales_data data2("978-7-121-15535-2");
	Sales_data data3("978-7-121-15535-2", 100, 128, 109);
	Sales_data data4(cin);

	cout << "书籍的销售情况是：" << endl;
	print(cout, data1); cout << endl;
	print(cout, data2); cout << endl;
	print(cout, data3); cout << endl;
	print(cout, data4); cout << endl;
	system("pause");
	return 0;
}