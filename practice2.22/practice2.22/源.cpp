#include<iostream>
int main()
{
	int *p1 = nullptr;
	int i = 0;
	int *p2 = &i;
	if (p1)
		std::cout << "p1 pass" << std::endl;
	if (p2)
		std::cout << "p2 pass" << std::endl;
	if (*p2)
		std::cout << "i pass" << std::endl;
	getchar();
	return 0;
}