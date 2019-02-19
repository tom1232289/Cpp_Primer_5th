#include "Message.h"

Message::~Message()
{
	remove_to_setFolders();
}

Message::Message(const Message & msg):
	contents(msg.contents),
	setFolders(msg.setFolders)
{
	add_to_setFolders(msg);
}

Message & Message::operator=(const Message & rhs)
{
	remove_to_setFolders();
	contents = rhs.contents;
	setFolders = rhs.setFolders;
	add_to_setFolders(rhs);
	return *this;
}

void Message::save(Folder & f)
{
	setFolders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder & f)
{
	f.remMsg(this);
	setFolders.erase(&f);
}

void Message::add_to_setFolders(const Message &msg)
{
	for (auto f : msg.setFolders)
		f->addMsg(this);
}

void Message::remove_to_setFolders()
{
	for (auto f : setFolders)
		f->remMsg(this);
}

void swap(Message & lhs, Message & rhs)
{
	lhs.remove_to_setFolders();
	rhs.remove_to_setFolders();
	using std::swap;
	swap(lhs.contents, rhs.contents);
	swap(lhs.setFolders, rhs.setFolders);
	lhs.add_to_setFolders(lhs);
	rhs.add_to_setFolders(rhs);
}
