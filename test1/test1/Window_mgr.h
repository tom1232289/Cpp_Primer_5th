#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Screen.h"
using namespace std;

class Window_mgr {
public:
	using ScreenIndex = vector<Screen>::size_type;	// 窗口中每个屏幕的编号
	void clear(ScreenIndex);
	ScreenIndex addScreen(const Screen&);	// 向窗口添加一个Screen，返回它的编号
private:
	vector<Screen> screens{ Screen(24,80,' ') };	//这个Window_mgr追踪的Screen默认情况下，一个Window_mgr包含一个标准尺寸的空白Screen
};
void Window_mgr::clear(ScreenIndex i) {
	Screen &s = screens[i];	// s是一个Screen的引用，指向我们想清空的那个屏幕
	s.contents = string(s.height*s.width, ' ');	// 将那个选定的Screen重置为空白
}
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s) {	// 首先处理返回类型，之后我们才进入Window_mgr的作用域
	screens.push_back(s);
	return screens.size() - 1;
}