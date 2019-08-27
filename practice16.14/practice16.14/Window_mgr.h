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
	void clear(size_t i);	// ���ձ�Ž�ָ����Screen����Ϊ�հ�
	void show();		// �����Ļ
	template <int H,int W>
	size_t addScreen(const Screen<H,W> &s);	// ������Ļ
private:
	template <int H,int W>
	vector<Screen<H, W>> screens{ Screen(H,W,'*') };	// Ĭ������£�һ��window_mgr����һ��ȫ��'*'��Screen
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
	return screens.size() - 1;	// ������ӵ�Screen�ı��
}

#endif	// !WINDOW_MGR_H