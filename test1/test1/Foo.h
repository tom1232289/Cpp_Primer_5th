#pragma once

class Foo {
public:
	Foo();				// Ĭ�Ϲ��캯��
	Foo(const Foo&);	// �������캯��
	Foo& operator=(const Foo&);
};