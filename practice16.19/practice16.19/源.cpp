#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
void print(const T &c)
{
	for (typename T::size_type i = 0; i != c.size(); ++i) {
		cout << c.at(i) << " ";
	}
	cout << endl;
}

int main()
{
	string s = "Hello!";
	print(s);

	vector<int> vi = { 0,2,4,6,8 };
	print(vi);

	return 0;
}