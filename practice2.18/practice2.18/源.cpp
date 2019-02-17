#include<iostream>
int main()
{
	int *p = nullptr;
	int ival = 42, ival2 = 0;
	p = &ival;
	std::cout << p << " " << *p << std::endl;
	*p = 0;
	p = &ival2;
	std::cout << p << " " << *p << " " << ival << std::endl;
	getchar();
	return 0;
}