#pragma once
#ifndef FOLDER_H
#define FOLDER_H

#include "Message.h"

class Folder
{
	friend class Message;
public:
	Folder() = default;
	~Folder() { remove_to_setMsgs(); }
	Folder(const Folder &f);
	Folder & operator=(const Folder &rhs);

public:
	void save(Message &msg);
	void remove(Message &msg);
	void debug_print();

private:
	void addMsg(Message *msg) { setMessages.insert(msg); }
	void remMsg(Message *msg) { setMessages.erase(msg); }
	void add_to_setMsgs(const Folder &f);
	void remove_to_setMsgs();

private:
	set<Message*> setMessages;
};

#endif	// !FOLDER_H