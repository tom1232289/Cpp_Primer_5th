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
	cout << "v1包含" << v1.size() << "个元素" << endl;
	if (v1.size() > 0) {
		cout << "v1的元素为：";
		for (auto i : v1)
			cout << i << " ";
		cout << endl;
	}
	else {
		cout << "v1里没有元素！" << endl;
	}
	vector<int> v2(10);
	cout << "v2包含" << v2.size() << "个元素" << endl;
	if (v2.size() > 0) {
		cout << "v2的元素为：";
		for (auto i : v2)
			cout << i << " ";
		cout << endl;
	}
	else {
		cout << "v2里没有元素！" << endl;
	}
	vector<int> v3(10, 42);
	cout << "v3包含" << v3.size() << "个元素" << endl;
	if (v3.size() > 0) {
		cout << "v3的元素为：";
		for (auto i : v3)
			cout << i << " ";
		cout << endl;
	}
	else {
		cout << "v3里没有元素！" << endl;
	}
	vector<int> v4{ 10 };
	cout << "v4包含" << v4.size() << "个元素" << endl;
	if (v4.size() > 0) {
		cout << "v4的元素为：";
		for (auto i : v4)
			cout << i << " ";
		cout << endl;
	}
	else {
		cout << "v4里没有元素！" << endl;
	}
	vector<int> v5{ 10,42 };
	cout << "v5包含" << v5.size() << "个元素" << endl;
	if (v5.size() > 0) {
		cout << "v5的元素为：";
		for (auto i : v5)
			cout << i << " ";
		cout << endl;
	}
	else {
		cout << "v5里没有元素！" << endl;
	}
	vector<string> v6{ 10 };
	cout << "v6包含" << v6.size() << "个元素" << endl;
	if (v6.size() > 0) {
		cout << "v6的元素为：";
		for (auto i : v6)
			cout << i << " ";
		cout << endl;
	}
	else {
		cout << "v6里没有元素！" << endl;
	}
	vector<string> v7{ 10,"hi" };
	cout << "v7包含" << v7.size() << "个元素" << endl;
	if (v7.size() > 0) {
		cout << "v7的元素为：";
		for (auto i : v7)
			cout << i << " ";
		cout << endl;
	}
	else {
		cout << "v7里没有元素！" << endl;
	}
	system("pause");
	return 0;
}