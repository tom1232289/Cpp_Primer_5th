#include "Foo.h"

Foo Foo::sorted() &&
{
	cout << "��ֵ���ð汾" << endl;
	sort(data.begin(), data.end());
	return *this;
}

Foo Foo::sorted() const &
{
	cout << "��ֵ���ð汾" << endl;
	Foo ret(*this);
// 	return ret.sorted();
	return Foo(*this).sorted();
}
