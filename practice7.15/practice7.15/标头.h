#pragma once
#include<iostream>
#include<string>
using namespace std;

class Person {
private:
	string strName;
	string strAddress;
//¹¹Ôìº¯Êý
public:
	Person() = default;
	Person(const string &name):strName(name){}
	Person(const string &name,const string &address):strName(name),strAddress(address){}
	Person(istream &is) { is >> *this; }
public:
	string getName() const { return strName; }
	string getAddress() const { return strAddress; }
};