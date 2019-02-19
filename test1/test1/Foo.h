#pragma once

class Foo {
public:
	Foo();				// 默认构造函数
	Foo(const Foo&);	// 拷贝构造函数
	Foo& operator=(const Foo&);
};