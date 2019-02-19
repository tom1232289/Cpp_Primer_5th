#include "String.h"
#include <vector>
#include <algorithm>

int main()
{
	String s1("One"), s2("Two");
	cout << s1 << " " << " " << s2 << " " << endl << endl;
	String s3(s2);
	cout << s1 << " " << s2 << " " << s3 << " " << endl << endl;
	s3 = s1;
	cout << s1 << " " << s2 << " " << s3 << " " << endl << endl;
	s3 = String("Three");
	cout << s1 << " " << s2 << " " << s3 << endl << endl;

	vector<String> vs;
// 	vs.reserve(4);
	vs.push_back(s1);
	cout << endl;
	vs.push_back(std::move(s2));
	cout << endl;
	vs.push_back(String("Three"));
	cout << endl;
	vs.push_back("Four");
	cout << endl;
	for_each(vs.begin(), vs.end(), [](const String &s) {cout << s << " "; });

	getchar();
	return 0;
}