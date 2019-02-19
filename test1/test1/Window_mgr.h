#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Screen.h"
using namespace std;

class Window_mgr {
public:
	using ScreenIndex = vector<Screen>::size_type;	// ������ÿ����Ļ�ı��
	void clear(ScreenIndex);
	ScreenIndex addScreen(const Screen&);	// �򴰿����һ��Screen���������ı��
private:
	vector<Screen> screens{ Screen(24,80,' ') };	//���Window_mgr׷�ٵ�ScreenĬ������£�һ��Window_mgr����һ����׼�ߴ�Ŀհ�Screen
};
void Window_mgr::clear(ScreenIndex i) {
	Screen &s = screens[i];	// s��һ��Screen�����ã�ָ����������յ��Ǹ���Ļ
	s.contents = string(s.height*s.width, ' ');	// ���Ǹ�ѡ����Screen����Ϊ�հ�
}
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s) {	// ���ȴ��������ͣ�֮�����ǲŽ���Window_mgr��������
	screens.push_back(s);
	return screens.size() - 1;
}