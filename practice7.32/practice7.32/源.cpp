// ��ϰ7.32���������Լ���Screen��Window_mgr,����clear��Window_mgr�ĳ�Ա����Screen����Ԫ��

//������˼·������԰������ඨ�����Ԫ��Ҳ���԰�������ĳ�Ա�����������Ԫ�����ѳ�Ա�����������Ԫʱ��Ҫ�ر�ע��������֯�ṹ��

//�����

#include<iostream>
#include<string>
#include<vector>
#include"Window_mgr.h"
using namespace std;


class Screen {
	friend void Window_mgr::clear(size_t);	// Window_mgr::clear������Screen��֮ǰ������
public:
	using pos = string::size_type;
	Screen() = default;
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c) {}	// cursor�������ڳ�ʼֵ��ʼ��Ϊ0
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
};

void Window_mgr::clear(size_t i) {
	Screen myScreen(10, 20, 'X');
	myScreen.contents = string(myScreen.height*myScreen.width, ' ');	// ���Ǹ�ѡ����Screen����Ϊ�հ�
}

