#include<iostream>
#include<string>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
	vector<int> v1;
	cout << "v1��Ԫ�ظ����ǣ�"<<v1.size() << endl;
	if (v1.cbegin() != v1.cend()) {
		cout << "v1��Ԫ�طֱ��ǣ�";
		for (auto it = v1.cbegin(); it != v1.cend(); ++it)
			cout << *it << " ";
		cout << endl;
	}
	vector<int> v2(10);
	cout << "v2��Ԫ�ظ����ǣ�" << v2.size() << endl;
	if (v2.cbegin() != v2.cend()) {
		cout << "v2��Ԫ�طֱ��ǣ�";
		for (auto it = v2.cbegin(); it != v2.cend(); ++it)
			cout << *it << " ";
		cout << endl;
	}
	vector<int> v3(10, 42);
	cout << "v3��Ԫ�ظ����ǣ�" << v3.size() << endl;
	if (v3.cbegin() != v3.cend()) {
		cout << "v3��Ԫ�طֱ��ǣ�";
		for (auto it = v3.cbegin(); it != v3.cend(); ++it)
			cout << *it << " ";
		cout << endl;
	}
	vector<int> v4{ 10 };
	cout << "v4��Ԫ�ظ����ǣ�" << v4.size() << endl;
	if (v4.cbegin() != v4.cend()) {
		cout << "v4��Ԫ�طֱ��ǣ�";
		for (auto it = v4.cbegin(); it != v4.cend(); ++it)
			cout << *it << " ";
		cout << endl;
	}
	vector<int> v5{ 10,42 };
	cout << "v5��Ԫ�ظ����ǣ�" << v5.size() << endl;
	if (v5.cbegin() != v5.cend()) {
		cout << "v5��Ԫ�طֱ��ǣ�";
		for (auto it = v5.cbegin(); it != v5.cend(); ++it)
			cout << *it << " ";
		cout << endl;
	}
	vector<string> v6{ 10 };
	cout << "v6��Ԫ�ظ����ǣ�" << v6.size() << endl;
	if (v6.cbegin() != v6.cend()) {
		cout << "v6��Ԫ�طֱ��ǣ�";
		for (auto it = v6.cbegin(); it != v6.cend(); ++it)
			cout << *it << " ";
		cout << endl;
	}
	vector<string> v7{ 10,"hi" };
	cout << "v7��Ԫ�ظ����ǣ�" << v7.size() << endl;
	if (v7.cbegin() != v7.cend()) {
		cout << "v7��Ԫ�طֱ��ǣ�";
		for (auto it = v7.cbegin(); it != v7.cend(); ++it)
			cout << *it << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}