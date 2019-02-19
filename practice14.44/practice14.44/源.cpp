#include <iostream>
#include <functional>
#include <map>
#include <string>

using namespace std;
using namespace std::placeholders;

int main()
{
	map<string, function<double(double, double)>> binOps{
		{"+",plus<double>()},
		{"-",minus<double>()},
		{"*",multiplies<double>()},
		{"/",divides<double>()},
// 		{"%",modulus<double>()}
	};
	double left, right;
	string op;
	cin >> left >> op >> right;
	cout << binOps[op](left, right) << endl;

	system("pause");
	return 0;
}