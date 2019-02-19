#include "Message.h"
#include "Folder.h"

Message::~Message()
{
	remove_to_setFolders();
}

Message::Message(const Message & msg) :
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

Message::Message(Message && msg) :
	contents(std::move(msg.contents))
{
	move_Folder(&msg);
	msg.contents = "";
}

Message & Message::operator=(Message && rhs)
{
	if (this != &rhs) {
		remove_to_setFolders();
		contents = std::move(rhs.contents);
		move_Folder(&rhs);
		rhs.contents = ""; 
	}
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

void Message::debug_print()
{
	cerr << "Message:\n\t" << contents << endl;
	cerr << "Appears in " << setFolders.size() << " Folders" << endl;
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

void Message::move_Folder(Message *msg)
{
	setFolders = std::move(msg->setFolders);
	for (auto f : setFolders) {
		f->remMsg(msg);
		f->addMsg(this);
	}
	msg->setFolders.clear();
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