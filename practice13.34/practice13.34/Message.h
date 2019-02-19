#pragma once
#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <string>
#include <set>

using namespace std;

class Folder;
class Message
{
	friend class Folder;
	friend void swap(Message &lhs, Message &rhs);
public:
	explicit Message(const string &s = string()) :
		contents(s) {	}
	~Message();
	Message(const Message &msg);
	Message & operator=(const Message &rhs);

public:
	void save(Folder &f);
	void remove(Folder &f);

private:
	void add_to_setFolders(const Message &msg);
	void remove_to_setFolders();

private:
	string contents;
	set<Folder*> setFolders;
};

#endif	// !MESSAGE_H