#include "HasPtr.h"	

int main()
{
	HasPtr hp("hi mom!");
	HasPtr hp2(hp);
	HasPtr hp3 = hp;
	hp2 = "hi dad!";
	hp3 = "hi son!";
	swap(hp2, hp3);
	cout << "hp:" << *hp << endl;
	cout << "hp2:" << *hp2 << endl;
	cout << "hp3:" << *hp3 << endl;

	getchar();
	return 0;
}