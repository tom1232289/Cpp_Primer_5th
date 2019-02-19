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
	Message(Message &&msg);
	Message & operator=(Message &&rhs);

public:
	void save(Folder &f);
	void remove(Folder &f);
	void debug_print();

private:
	void add_to_setFolders(const Message &msg);
	void remove_to_setFolders();
	void addFolder(Folder *f) { setFolders.insert(f); }
	void remFolder(Folder *f) { setFolders.erase(f); }
	void move_Folder(Message *msg);

private:
	string contents;
	set<Folder*> setFolders;
};

#endif	// !MESSAGE_H