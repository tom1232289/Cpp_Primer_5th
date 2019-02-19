// 练习7.30：通过this指针使用成员的做法虽然合法，但是有点多余。讨论显式地使用指针访问成员的优缺点。
#include<iostream>
#include<string>
using namespace std;
class Sales_data {
private:
	string bookNo;
	unsigned units_sold = 0;
	double sellingprice = 0.0;//原始价格
	double saleprice = 0.0;//实售价格
	double discount = 0.0;//折扣
public:
	string isbn() const { return this->bookNo; }
	Sales_data& combine(const Sales_data& rhs) {
		units_sold += rhs.units_sold;
		saleprice = (saleprice*units_sold + rhs.saleprice*rhs.units_sold) / (units_sold + rhs.units_sold);
		if (sellingprice != 0)
			discount = saleprice / sellingprice;
		return *this;
	}
};

// 【出题思路】对比使用this指针访问成员的利弊。

// 【解答】通过this指针访问成员的优点是，可以非常明确地指出访问的是对象的成员，并且可以在成员函数中使用与数据成员同名的形参；
//		   缺点是显得多余，代码不够简洁。