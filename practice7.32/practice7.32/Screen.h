#pragma once
#ifndef SCREEN_H
#define SCREEN_H

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Screen {
	//friend class Window_mgr;												// Window_mgr�ĳ�Ա���Է���Screen���˽�в���
	friend void Window_mgr::clear(ScreenIndex);								// Window_mgr::clear������Screen��֮ǰ������
public:
	//typedef string::size_type pos;
	using pos = string::size_type;
	Screen() = default;
	Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht*wd,c){}	// cursor�������ڳ�ʼֵ��ʼ��Ϊ0
	char get() const { return contents[cursor]; }							// ��ȡ��괦���ַ�����ʽ����
	inline char get(pos ht, pos wd) const;									// ��ʽ����
	Screen &move(pos r, pos c);												// ����֮����Ϊ����
public:
	void some_member() const;
public:
	Screen &set(char);
	Screen &set(pos, pos, char);
public:																		// ���ݶ����Ƿ���const������display����
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
	mutable size_t	access_ctr;												// ��ʹ��һ��const������Ҳ�ܱ��޸�
	void do_display(ostream &os) const { os << contents; }					// �ú���������ʾScreen������
};
inline Screen &Screen::move(pos r, pos c) {									// �����ں����Ķ��崦ָ��inline
	pos row = r * width;													// �����е�λ��
	cursor = row + c;														// �����ڽ�����ƶ���ָ������
	return *this;															// ����ֵ����ʽ���ض���
}
char Screen::get(pos r, pos c) const {										// ���ں����ڲ�������inline�������������Ͷ���ĵط�ͬʱ˵��inline�������ֻ�����ⲿ����ĵط�˵��inline����������ʹ���������⣩
	pos row = r * width;
	return contents[row + c];												//���ظ����е��ַ�
}
void Screen::some_member() const {
	++access_ctr;															// ����һ������ֵ�����ڼ�¼��Ա���������õĴ���
}
inline Screen &Screen::set(char c) {
	contents[cursor] = c;													// ���õ�ǰ�������λ�õ���ֵ
	return *this;															// ��this������Ϊ��ֵ����
}

inline Screen & Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;											// �趨����λ�õ���ֵ
	return *this;												
}
#endif // !SCREEN_H