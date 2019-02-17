#include<iostream>
int main()
{
	int i = 0, &r = i;
	auto a = r;
	const int ci = i, &cr = ci;
	auto b = ci;
	auto c = cr;
	auto d = &i;//d是一个整形指针
	auto e = &ci;//e是一个指向整形常量的指针
	auto &g = ci;//g是一个整形常量的引用，绑定到ci
	std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << g << std::endl;
	a = 42;
	b = 42;
	c = 42;
//	d = 42; 
//	e = 42; 
//	g = 42;
	std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << g << std::endl;
	getchar();
	return 0;
}