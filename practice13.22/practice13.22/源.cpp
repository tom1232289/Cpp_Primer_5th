#include "HasPtr.h"

int main()
{
	HasPtr h("hi mom!");
	HasPtr h2(h);	// ��Ϊ��ֵ��h2��h3��hָ��ͬstring
// 	HasPtr h3 = h;
	h2 = "hi dad!";
// 	h3 = "hi son!";
	cout << "h:" << *h << endl;
	cout << "h2:" << *h2 << endl;
// 	cout << "h3:" << *h3 << endl;

	system("pause");
	return 0;
}