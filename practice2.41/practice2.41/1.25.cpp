#include<iostream>
#include<string>
#include<iomanip>
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double price = 0.00;
	double revenue = 0.00;
};
int main()
{
	Sales_data totalData, currData;
	double average_price = 0.0;
	if (std::cin >> totalData.bookNo >> totalData.units_sold >> totalData.price) {
		totalData.revenue = totalData.units_sold*totalData.price;
		while (std::cin >> currData.bookNo >> currData.units_sold >> currData.price) {
			currData.revenue = currData.units_sold*currData.price;
			if (totalData.bookNo == currData.bookNo) {
				totalData.units_sold += currData.units_sold;
				totalData.revenue += currData.revenue;
			}
			else {
				average_price = totalData.revenue / totalData.units_sold;
				std::cout << totalData.bookNo << " " << totalData.units_sold << " "
					<< std::setiosflags(std::ios::fixed) << std::setprecision(2) << totalData.revenue << " "
					<< average_price << std::endl;
				std::cin.get();
				totalData.bookNo = currData.bookNo;
				totalData.units_sold = currData.units_sold;
				totalData.price = currData.price;
				totalData.revenue = currData.revenue;
			}
		}
		average_price = totalData.revenue / totalData.units_sold;
		std::cout << totalData.bookNo << " " << totalData.units_sold << " "
			<< std::setiosflags(std::ios::fixed) << std::setprecision(2) << totalData.revenue << " "
			<< average_price << std::endl;
		std::cin.get();
	}
	else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}