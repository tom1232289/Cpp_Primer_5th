#include<iostream>
#include<ctime>
using namespace std;
int main()
{
	int arr1[] = { 1,2,2,4,5 }, arr2[] = { 1,2,3,4,5 };
	if (end(arr1) - begin(arr1) != end(arr2) - begin(arr2)) {
		cout << "arr1和arr2这两个数组维度不同，即不相等。" << endl;
		system("pause");
		return 0;
	}
	else {
		for (int *p1 = begin(arr1), *p2 = begin(arr2); p1 != end(arr1); ++p1, ++p2) {
			if (*p1 != *p2) {
				cout << "arr1和arr2这两个数组不相等！" << endl;
				system("pause");
				return 0;
			}
		}
		cout << "arr1和arr2相等！" << endl;
		system("pause");
		return 0;
	}
}