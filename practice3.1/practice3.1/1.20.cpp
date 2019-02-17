#include<iostream>
#include<string>
#include<iomanip>
using std::cin;
using std::cout;
using std::endl;
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double price = 0.00;
	double revenue = 0.00;
};
int main()
{
	Sales_data data;
	while (cin >> data.bookNo >> data.units_sold >> data.price) {
		data.revenue = data.price*data.units_sold;
		cout << data.bookNo << " "
			<< data.units_sold << " "
			<< std::setiosflags(std::ios::fixed) << std::setprecision(2) << data.price << " "
			<< data.revenue << endl;
	}
	system("pause");
	return 0;
}