#pragma once
#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include<string>
using namespace std;

class Book {
	friend std::istream& operator>>(std::istream&, Book&);
private:
	string sName, sISBN, sAuthor, sPublisher;
	double price = 0;
public:
	Book() = default;
	Book(const string &n, const string &I, const string &a, const string &p, const double pr) :sName(n), sISBN(I), sAuthor(a), sPublisher(p), price(pr) {}
	Book(istream &is) { is >> *this; }
};
std::istream&
operator>>(std::istream& in, Book& s)
{
	double price;
	in >> s.sName >> s.sISBN >> s.sAuthor >> s.sPublisher >> s.price;
	// check that the inputs succeeded
	if (!in)
		s = Book();	// input failed: reset object to default state
	return in;
}
#endif// !BOOK_H