#include<iostream>
int main()
{
	const int i = 42;//i�����γ���
	auto j = i;//j������
	const auto &k = i;//k�����γ���
	auto *p = &i;//p��ָ�����γ�����ָ��
	const auto j2 = i, &k2 = i;//j2�����ͳ�����k2�����ͳ���
	std::cout << "iΪ" << typeid(i).name() << std::endl
		<< "&iΪ" << typeid(&i).name() << std::endl
		<< "jΪ" << typeid(j).name() << std::endl
		<< "kΪ" << typeid(k).name() << std::endl
		<< "pΪ" << typeid(p).name() << std::endl
		<< "*pΪ" << typeid(*p).name() << std::endl
		<< "j2Ϊ" << typeid(j2).name() << std::endl
		<< "k2Ϊ" << typeid(k2).name() << std::endl
		<< "p�ĵ�ַ" << p << std::endl;
	p = &j2;
	std::cout<< "pΪ" << typeid(p).name() << std::endl;
	std::cout << "p�ĵ�ַ" << p << std::endl;
	getchar();
	return 0;
}