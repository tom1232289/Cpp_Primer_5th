#include <iostream>

using namespace std;

template <typename T, size_t N>
const T * begin(const T (&a)[N])
{
	return &a[0];
}

template <typename T, size_t N>
const T * end(const T(&a)[N])
{
	return &a[0] + N;
}

int main()
{
	int a[6] = { 0,2,4,6,8,10 };
	for (auto iter = begin(a); iter != end(a); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;

	return 0;
}