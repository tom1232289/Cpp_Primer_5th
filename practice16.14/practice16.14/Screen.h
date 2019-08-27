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
	// ��ȡ��괦������
	char get() const { return contents[cursor]; }
	inline char get(int r, int c) const;	// ��ʽָ������
	Screen & clear(char c = bkground);
private:
	static const char bkground = ' ';
public:
	Screen &move(int r, int c);
	Screen &set(char c);
	Screen &set(int r, int col, char ch);
	// ����display����ͨ�汾��const�汾
	Screen &display(std::ostream &os) {
		do_display(os);
		return *this;
	}
	const Screen &display(std::ostream &os) const {
		do_display(os);
		return *this;
	}
private:
	// ʵ�������ʾ�ĺ���
	void do_display(std::ostream &os) const { os << contents; }
private:
	int cursor = 0;
	string contents;
};

template<int H, int W>
inline char Screen<H, W>::get(int r, int c) const
{
	int row = r*W;	// ������λ��
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
	int row = r*W;		// ������λ��
	cursor = row + c;	// ������ƶ�������ָ����
	return *this;		// ���ص�ǰ������ֵ��
}

template<int H, int W>
inline Screen<H, W> & Screen<H, W>::set(char c)
{
	contents[cursor] = c;	// ����괦����������Ϊ��ֵ
	return *this;			// ���ص�ǰ������ֵ��
}

template<int H, int W>
inline Screen<H, W> & Screen<H, W>::set(int r, int col, char ch)
{
	contents[r*W + col] = ch;	// ���ø���λ������Ϊ��ֵ
	return *this;				// ���ص�ǰ������ֵ��
}

#endif	// !SCREEN_H