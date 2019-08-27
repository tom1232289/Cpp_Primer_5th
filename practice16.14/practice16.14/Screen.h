#pragma once

#ifndef SCREEN_H
#define SCREEN_H

#include <string>

using namespace std;

template <int H, int W>
class Screen
{
public:
	Screen() :contents(H*W, ' ') {}
	Screen(char c) :contents(H*W, c) {}
	friend class Window_mgr;
public:
	// 获取光标处的内容
	char get() const { return contents[cursor]; }
	inline char get(int r, int c) const;	// 显式指定内联
	Screen & clear(char c = bkground);
private:
	static const char bkground = ' ';
public:
	Screen &move(int r, int c);
	Screen &set(char c);
	Screen &set(int r, int col, char ch);
	// 重载display：普通版本和const版本
	Screen &display(std::ostream &os) {
		do_display(os);
		return *this;
	}
	const Screen &display(std::ostream &os) const {
		do_display(os);
		return *this;
	}
private:
	// 实际完成显示的函数
	void do_display(std::ostream &os) const { os << contents; }
private:
	int cursor = 0;
	string contents;
};

template<int H, int W>
inline char Screen<H, W>::get(int r, int c) const
{
	int row = r*W;	// 计算行位置
	return contents[row + c];
}

template<int H, int W>
inline Screen<H, W> & Screen<H, W>::clear(char c)
{
	contents = string(H*W, c);
	return *this;
}

template<int H, int W>
inline Screen<H, W> & Screen<H, W>::move(int r, int c)
{
	int row = r*W;		// 计算行位置
	cursor = row + c;	// 将光标移动到此行指定列
	return *this;		// 返回当前对象（左值）
}

template<int H, int W>
inline Screen<H, W> & Screen<H, W>::set(char c)
{
	contents[cursor] = c;	// 将光标处的内容设置为新值
	return *this;			// 返回当前对象（左值）
}

template<int H, int W>
inline Screen<H, W> & Screen<H, W>::set(int r, int col, char ch)
{
	contents[r*W + col] = ch;	// 设置给定位置内容为新值
	return *this;				// 返回当前对象（左值）
}

#endif	// !SCREEN_H