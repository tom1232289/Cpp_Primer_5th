#include "HasPtr.h"
#include <algorithm>

int main()
{
	vector<HasPtr> vecHP;
	for (int i = 33; i > 0; --i)
		vecHP.push_back(to_string(i));
	for (auto p : vecHP)
		cout << p.getString() << " ";
	cout << endl;
	sort(vecHP.begin(), vecHP.end());	// 当元素较少时会采用插入排序法，不会调用swap，而元素较多时会采用快速排序法，会调用swap。（这里分界点为33个元素）
	for (auto p : vecHP)
		cout << p.getString() << " ";

	getchar();
	return 0;
}