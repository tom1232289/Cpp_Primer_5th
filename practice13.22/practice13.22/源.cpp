#include "HasPtr.h"

int main()
{
	HasPtr h("hi mom!");
	HasPtr h2(h);	// 行为类值，h2、h3和h指向不同string
// 	HasPtr h3 = h;
	h2 = "hi dad!";
// 	h3 = "hi son!";
	cout << "h:" << *h << endl;
	cout << "h2:" << *h2 << endl;
// 	cout << "h3:" << *h3 << endl;

	system("pause");
	return 0;
}