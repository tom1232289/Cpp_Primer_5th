#include <iostream>
#include <string>

using namespace std;

// ԭʼ��print����
void print(const int ia[], size_t size)
{
	for (size_t i = 0; i != size; ++i) {
		cout << ia[i] << endl;
	}
}

// ģ��汾��print����
template <typename T, size_t N>
void print(const T(&a)[N])
{
// 	for (size_t i = 0; i != N; ++i) {
// 		cout << a[i] << " ";
// 	}
// 	cout << endl;
	for (auto iter = begin(a); iter != end(a); ++iter)
		cout << *iter << " ";
	cout << endl;
}

int main()
{
	int a[6] = { 0,2,4,6,8,10 };
	print(a);

	string s[3] = { "Hello","World","!" };
	print(s);

	return 0;
}