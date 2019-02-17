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
	int cnt = 1;
	if (std::cin >> totalData.bookNo >> totalData.units_sold >> totalData.price) {
		while (std::cin >> currData.bookNo >> currData.units_sold >> currData.price) {
			if (totalData.bookNo == currData.bookNo) {
				cnt++;
			}
			else {
				std::cout << totalData.bookNo << "有" << cnt << "条记录" << std::endl;
				std::cin.get();
				totalData.bookNo = currData.bookNo;
				cnt = 1;
			}
		}
		std::cout << totalData.bookNo << "有" << cnt << "条记录" << std::endl;
	}
	else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}