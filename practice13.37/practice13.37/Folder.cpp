#include "Folder.h"

Folder::Folder(const Folder & f) :
	setMessages(f.setMessages)
{
	add_to_setMsgs(f);
}

Folder & Folder::operator=(const Folder & rhs)
{
	remove_to_setMsgs();
	setMessages = rhs.setMessages;
	add_to_setMsgs(rhs);
	return *this;
}

void Folder::save(Message & msg)
{
	setMessages.insert(&msg);
	msg.addFolder(this);
}

void Folder::remove(Message & msg)
{
	msg.remFolder(this);
	setMessages.erase(&msg);
}

void Folder::debug_print()
{
	cerr << "Folder contains " << setMessages.size() << " messages" << endl;
	int ctr = 1;
	for (auto m : setMessages) {
		cerr << "Message " << ctr++ << ":\n\t" << m->contents << endl;
	}
}

void Folder::add_to_setMsgs(const Folder & f)
{
	for (auto m : setMessages)
		m->addFolder(this);
}

void Folder::remove_to_setMsgs()
{
	for (auto m : setMessages)
		m->remFolder(this);
}