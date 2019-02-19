#include "HasPtr.h"

int main()
{
	HasPtr h1("hi mom!");
	HasPtr h2 = h1;
	h1 = "hi dad!";
	cout << "h1:" << *h1 << endl;
	cout << "h2:" << *h2 << endl;

	system("pause");
	return 0;
}