#pragma once
#ifndef SCREEN_H
#define SCREEN_H

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Screen {
	//friend class Window_mgr;												// Window_mgr的成员可以访问Screen类的私有部分
	friend void Window_mgr::clear(ScreenIndex);								// Window_mgr::clear必须在Screen类之前被声明
public:
	//typedef string::size_type pos;
	using pos = string::size_type;
	Screen() = default;
	Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht*wd,c){}	// cursor被其类内初始值初始化为0
	char get() const { return contents[cursor]; }							// 读取光标处的字符，隐式内联
	inline char get(pos ht, pos wd) const;									// 显式内联
	Screen &move(pos r, pos c);												// 能在之后被设为内联
public:
	void some_member() const;
public:
	Screen &set(char);
	Screen &set(pos, pos, char);
public:																		// 根据对象是否是const重载了display函数
	Screen &display(ostream &os){
		do_display(os); return *this;
	}
	const Screen &display(ostream &os) const {
		do_display(os); return *this;
	}
	
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
	mutable size_t	access_ctr;												// 即使在一个const对象内也能被修改
	void do_display(ostream &os) const { os << contents; }					// 该函数负责显示Screen的内容
};
inline Screen &Screen::move(pos r, pos c) {									// 可以在函数的定义处指定inline
	pos row = r * width;													// 计算行的位置
	cursor = row + c;														// 在行内将光标移动到指定的列
	return *this;															// 以左值的形式返回对象
}
char Screen::get(pos r, pos c) const {										// 已在函数内部声明成inline（可以在声明和定义的地方同时说明inline，但最好只在类外部定义的地方说明inline，这样可以使类更容易理解）
	pos row = r * width;
	return contents[row + c];												//返回给定列的字符
}
void Screen::some_member() const {
	++access_ctr;															// 保存一个计数值，用于记录成员函数被调用的次数
}
inline Screen &Screen::set(char c) {
	contents[cursor] = c;													// 设置当前光标所在位置的新值
	return *this;															// 将this对象作为左值返回
}

inline Screen & Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;											// 设定给定位置的新值
	return *this;												
}
#endif // !SCREEN_H