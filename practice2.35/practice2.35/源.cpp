#include<iostream>
int main()
{
	const int i = 42;//i是整形常量
	auto j = i;//j是整数
	const auto &k = i;//k是整形常量
	auto *p = &i;//p是指向整形常量的指针
	const auto j2 = i, &k2 = i;//j2是整型常量，k2是整型常量
	std::cout << "i为" << typeid(i).name() << std::endl
		<< "&i为" << typeid(&i).name() << std::endl
		<< "j为" << typeid(j).name() << std::endl
		<< "k为" << typeid(k).name() << std::endl
		<< "p为" << typeid(p).name() << std::endl
		<< "*p为" << typeid(*p).name() << std::endl
		<< "j2为" << typeid(j2).name() << std::endl
		<< "k2为" << typeid(k2).name() << std::endl
		<< "p的地址" << p << std::endl;
	p = &j2;
	std::cout<< "p为" << typeid(p).name() << std::endl;
	std::cout << "p的地址" << p << std::endl;
	getchar();
	return 0;
}