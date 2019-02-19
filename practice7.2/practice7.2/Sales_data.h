#include<iostream>
#include<string>
using namespace std;

class Sales_data {
private:
	string bookNo;
	unsigned units_sold = 0;
	double sellingprice = 0.0;//ԭʼ�۸�
	double saleprice = 0.0;//ʵ�ۼ۸�
	double discount = 0.0;//�ۿ�
public:
	string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data& rhs) {
		units_sold += rhs.units_sold;
		saleprice = (saleprice*units_sold + rhs.saleprice*rhs.units_sold) / (units_sold + rhs.units_sold);
		if (sellingprice != 0)
			discount = saleprice / sellingprice;
		return *this;
	}
};
