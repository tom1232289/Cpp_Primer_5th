#include "String.h"
#include <vector>

int main()
{
	String s1("One"), s2("Two");
	cout << s1 << " " << s2 << endl;
	String s3(s2);
	cout << s1 << " " << s2 << " " << s3 << endl;
	s3 = "Three";
	cout << s1 << " " << s2 << " " << s3 << endl;

	vector<String> vecs;
	vecs.reserve(4);
	vecs.push_back(s1);
	cout << endl;
	vecs.push_back(std::move(s2));
	cout << endl;
	vecs.push_back("Three");
	cout << endl;
	vecs.push_back("Four");
	cout << endl;
	for (auto &s : vecs)
		cout << s << " ";

	getchar();
	return 0;
}