#include<iostream>
#include<ctime>
using namespace std;
int main()
{
	int arr1[] = { 1,2,2,4,5 }, arr2[] = { 1,2,3,4,5 };
	if (end(arr1) - begin(arr1) != end(arr2) - begin(arr2)) {
		cout << "arr1��arr2����������ά�Ȳ�ͬ��������ȡ�" << endl;
		system("pause");
		return 0;
	}
	else {
		for (int *p1 = begin(arr1), *p2 = begin(arr2); p1 != end(arr1); ++p1, ++p2) {
			if (*p1 != *p2) {
				cout << "arr1��arr2���������鲻��ȣ�" << endl;
				system("pause");
				return 0;
			}
		}
		cout << "arr1��arr2��ȣ�" << endl;
		system("pause");
		return 0;
	}
}