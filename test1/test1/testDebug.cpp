#include<iostream>
#include"Debug.h"
using namespace std;
int main()
{
	constexpr Debug io_sub(false, true, false);
	if (io_sub.any()) {
		cerr << "print appropriate error message" << endl;
		system("pause");
	}
	constexpr Debug prod(false);
	if (prod.any()) {
		cerr << "print an error message" << endl;
		system("pause");
	}

	return 0;
}
