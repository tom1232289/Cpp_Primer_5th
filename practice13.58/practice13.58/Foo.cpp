#include "Foo.h"

Foo Foo::sorted() &&
{
	cout << "右值引用版本" << endl;
	sort(data.begin(), data.end());
	return *this;
}

Foo Foo::sorted() const &
{
	cout << "左值引用版本" << endl;
	Foo ret(*this);
// 	return ret.sorted();
	return Foo(*this).sorted();
}
