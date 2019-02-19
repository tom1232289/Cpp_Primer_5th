#include "String.h"

allocator<char> String::alloc;

String::String(const String & s):
	p(alloc.allocate(s.sz)),
	sz(s.sz)
{
	cout << "¿½±´¹¹Ôìº¯Êý" << endl;
	uninitialized_copy(s.p, s.p + s.sz, p);
}

String & String::operator=(const String & rhs)
{
	cout << "¿½±´¸³ÖµÔËËã·û" << endl;
	auto newp = alloc.allocate(rhs.sz);
	uninitialized_copy(rhs.p, rhs.p + rhs.sz, newp);
	free();
	p = newp;
	sz = rhs.sz;
	return *this;
}

String::String(const char * cp):
	p(alloc.allocate(strlen(cp))),
	sz(strlen(cp))
{
	uninitialized_copy(cp, cp + strlen(cp), p);
}

String::String(size_t n, char c):
	p(alloc.allocate(n)),
	sz(n)
{
	uninitialized_fill_n(p, sz, c);
}

String::String(initializer_list<char> il):
	p(alloc.allocate(il.size())),
	sz(il.size())
{
	uninitialized_copy(il.begin(), il.end(), p);
}

String & String::operator=(const char * cp)
{
	sz = strlen(cp);
	auto newp = alloc.allocate(sz);
	uninitialized_copy(cp, cp + sz, newp);
	free();
	p = newp;
	return *this;
}

String & String::operator=(char c)
{
	auto newp = alloc.allocate(1);
	p = newp;
	*p = c;
	sz = 1;
	return *this;
}

String::String(String && s) noexcept:
	p(s.p),
	sz(s.sz)
{
	s.p = nullptr;
	s.sz = 0;
}

String & String::operator=(String && rhs) noexcept
{
	if (this != &rhs) {
		free();
		p = rhs.p;
		sz = rhs.sz;
		rhs.p = nullptr;
		rhs.sz = 0;
	}
	return *this;
}

ostream & print(ostream & os, const String & s)
{
	for (auto it = s.begin(); it != s.end(); ++it)
		os << *it;
	return os;
}

String operator+(const String & lhs, const String & rhs)
{
	return add(lhs, rhs);
}

String add(const String & lhs, const String & rhs)
{
	String sum;
	sum.sz = lhs.sz + rhs.sz;
	sum.p = String::alloc.allocate(sum.sz);
	uninitialized_copy(lhs.begin(), lhs.end(), sum.p);
	uninitialized_copy(rhs.begin(), rhs.end(), sum.p + lhs.sz);
	return sum;
}

void swap(String & lhs, String & rhs)
{
	using std::swap;
	swap(lhs.p, rhs.p);
	swap(lhs.sz, rhs.sz);
}

ostream & operator<<(ostream & os, const String & rhs)
{
	return print(os, rhs);
}
