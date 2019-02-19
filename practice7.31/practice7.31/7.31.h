// 练习7.31：定义一对类X和Y，其中X包含一个指向Y的指针，而Y包含一个类型为X的对象。

// 【出题思路】理解类的声明和定义。声明的作用是告知程序类的名字合法可用；定义的作用是规定类的细节。

// 【解答】
#pragma once
#include<iostream>

class X;	// 声明类型X
class Y {	// 定义类型Y
	X* x;
};
class X {	// 定义类型X
	Y y;
};