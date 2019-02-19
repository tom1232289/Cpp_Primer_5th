#include "String.h"

int main()
{
	String s1("One"), s2("Two");
	cout << s1 << " " << s2 << endl;
	String s3(s2);
	cout << s1 << " " << s2 << " " << s3 << endl;
	s3 = "Three";
	cout << s1 << " " << s2 << " " << s3 << endl;

	getchar();
	return 0;
}