#pragma once
#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H
#include<iostream>
#include<string>
#include<vector>
#include"Screen.h"
using namespace std;

class Window_mgr {
public:
	using ScreenIndex = vector<Screen>::size_type;	// 窗口中每个屏幕的编号
	void clear(ScreenIndex);
private:
	vector<Screen> screens{ Screen(24,80,' ') };	//这个Window_mgr追踪的Screen默认情况下，一个Window_mgr包含一个标准尺寸的空白Screen
};
void Window_mgr::clear(ScreenIndex i) {
	Screen &s = screens[i];	//s是一个Screen的引用，指向我们想清空的那个屏幕
	s.contents = string(s.height*s.width, ' ');	// 将那个选定的Screen重置为空白
}
#endif // !WINDOW_MGR_H
