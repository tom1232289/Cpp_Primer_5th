#include<iostream>
#include<vector>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
int main()
{
	vector<int> v1;
	cout << "v1����" << v1.size() << "��Ԫ��" << endl;
	if (v1.size() > 0) {
		cout << "v1��Ԫ��Ϊ��";
		for (auto i : v1)
			cout << i << " ";
		cout << endl;
	}
	else {
		cout << "v1��û��Ԫ�أ�" << endl;
	}
	vector<int> v2(10);
	cout << "v2����" << v2.size() << "��Ԫ��" << endl;
	if (v2.size() > 0) {
		cout << "v2��Ԫ��Ϊ��";
		for (auto i : v2)
			cout << i << " ";
		cout << endl;
	}
	else {
		cout << "v2��û��Ԫ�أ�" << endl;
	}
	vector<int> v3(10, 42);
	cout << "v3����" << v3.size() << "��Ԫ��" << endl;
	if (v3.size() > 0) {
		cout << "v3��Ԫ��Ϊ��";
		for (auto i : v3)
			cout << i << " ";
		cout << endl;
	}
	else {
		cout << "v3��û��Ԫ�أ�" << endl;
	}
	vector<int> v4{ 10 };
	cout << "v4����" << v4.size() << "��Ԫ��" << endl;
	if (v4.size() > 0) {
		cout << "v4��Ԫ��Ϊ��";
		for (auto i : v4)
			cout << i << " ";
		cout << endl;
	}
	else {
		cout << "v4��û��Ԫ�أ�" << endl;
	}
	vector<int> v5{ 10,42 };
	cout << "v5����" << v5.size() << "��Ԫ��" << endl;
	if (v5.size() > 0) {
		cout << "v5��Ԫ��Ϊ��";
		for (auto i : v5)
			cout << i << " ";
		cout << endl;
	}
	else {
		cout << "v5��û��Ԫ�أ�" << endl;
	}
	vector<string> v6{ 10 };
	cout << "v6����" << v6.size() << "��Ԫ��" << endl;
	if (v6.size() > 0) {
		cout << "v6��Ԫ��Ϊ��";
		for (auto i : v6)
			cout << i << " ";
		cout << endl;
	}
	else {
		cout << "v6��û��Ԫ�أ�" << endl;
	}
	vector<string> v7{ 10,"hi" };
	cout << "v7����" << v7.size() << "��Ԫ��" << endl;
	if (v7.size() > 0) {
		cout << "v7��Ԫ��Ϊ��";
		for (auto i : v7)
			cout << i << " ";
		cout << endl;
	}
	else {
		cout << "v7��û��Ԫ�أ�" << endl;
	}
	system("pause");
	return 0;
}