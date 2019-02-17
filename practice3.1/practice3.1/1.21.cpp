#include<iostream>
#include<string>
#include<iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double price = 0.00;
	double revenue = 0.00;
};
int main()
{
	Sales_data data1, data2;
	cin >> data1.bookNo >> data1.units_sold >> data1.price;
	data1.revenue = data1.units_sold*data1.price;
	cin >> data2.bookNo >> data2.units_sold >> data2.price;
	data2.revenue = data2.units_sold*data2.price;
	if (data1.bookNo == data2.bookNo) {
		double average_price = 0.0;
		unsigned totalCnt = data1.units_sold + data2.units_sold;
		double totalRevenue = data1.revenue + data2.revenue;
		if (totalCnt != 0)
			average_price = totalRevenue / totalCnt;
		cout << data1.bookNo << " "
			<< totalCnt << " "
			<< std::setiosflags(std::ios::fixed) << std::setprecision(2) << totalRevenue << " "
			<< average_price << endl;
	}
	else {
		cerr << "Data must refer to the same ISBN" << endl;
		return -1;
	}
	system("pause");
	return 0;
}