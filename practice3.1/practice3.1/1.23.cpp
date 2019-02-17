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
	Sales_data totalData, currData;
	int cnt = 1;
	if (cin >> totalData.bookNo >> totalData.units_sold >> totalData.price) {
		while (cin >> currData.bookNo >> currData.units_sold >> currData.price) {
			if (totalData.bookNo == currData.bookNo) {
				cnt++;
			}
			else {
				cout << totalData.bookNo << "有" << cnt << "条记录" << endl;
				totalData.bookNo = currData.bookNo;
				cnt = 1;
			}
		}
		cout << totalData.bookNo << "有" << cnt << "条记录" << endl;
	}
	else {
		cerr << "No data?!" << endl;
		system("pause");
		return -1;
	}
	system("pause");
	return 0;
}