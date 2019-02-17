#include<iostream>
using namespace std;
double jue_dui_zhi(double val) {
	double ret = 0;
	if (val < 0)
		ret = val * -1;
	else
		ret = val;
	return ret;
}

int main()
{
	double val = jue_dui_zhi(-7.3937363);
	cout << val << endl;
	system("pause");
	return 0;
}