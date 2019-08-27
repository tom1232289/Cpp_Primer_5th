#pragma once

#ifndef DEBUGDELETE_H
#define DEBUGDELETE_H

#include <iostream>

using namespace std;

// ���������࣬�Ը���ָ��ִ��delete
class DebugDelete
{
public:
	DebugDelete(ostream &s = std::cerr) :os(s) {}
	// ���κκ���ģ����ͬ��T�������ɱ������ƶ�
	template <typename T>
	void operator()(T *p) const {
		os << "deleting shared_ptr" << endl;
		delete p;
	}
private:
	ostream &os;
};

#endif // !DEBUGDELETE_H