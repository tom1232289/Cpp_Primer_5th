#pragma once

#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <vector>
#include "Screen.h"

using namespace std;

template <int H,int W>
class Window_mgr
{
public:
	void clear(size_t i);	// 按照编号将指定的Screen重置为空白
	void show();		// 输出屏幕
	template <int H,int W>
	size_t addScreen(const Screen<H,W> &s);	// 增加屏幕
private:
	template <int H,int W>
	vector<Screen<H, W>> screens{ Screen(H,W,'*') };	// 默认情况下，一个window_mgr包含一个全是'*'的Screen
};

template <int H,int W>
void Window_mgr::clear(size_t i)
{
	Screen<H, W> &s = screens[i];
	s.contents = string(H, W, ' ');
}

template <int H,int W>
void Window_mgr::show()
{
	for (auto &c : screens) {
		c.display(std::cout);
	}
}

template <int H,int W>
size_t Window_mgr::addScreen(const Screen<H, W> &s)
{
	screens.push_back(s);
	return screens.size() - 1;	// 返回添加的Screen的编号
}

#endif	// !WINDOW_MGR_H