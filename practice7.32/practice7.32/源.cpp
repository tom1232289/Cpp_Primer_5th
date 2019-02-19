// 练习7.32：定义你自己的Screen和Window_mgr,其中clear是Window_mgr的成员，是Screen的友元。

//【出题思路】类可以把其他类定义成友元，也可以把其他类的成员函数定义成友元。当把成员函数定义成友元时，要特别注意程序的组织结构。

//【解答】

#include<iostream>
#include<string>
#include<vector>
#include"Window_mgr.h"
using namespace std;


class Screen {
	friend void Window_mgr::clear(size_t);	// Window_mgr::clear必须在Screen类之前被声明
public:
	using pos = string::size_type;
	Screen() = default;
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c) {}	// cursor被其类内初始值初始化为0
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
};

void Window_mgr::clear(size_t i) {
	Screen myScreen(10, 20, 'X');
	myScreen.contents = string(myScreen.height*myScreen.width, ' ');	// 将那个选定的Screen重置为空白
}

