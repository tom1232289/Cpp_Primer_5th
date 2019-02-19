#pragma once
#ifndef TREE_H
#define TREE_H
#include<iostream>
#include<string>
using namespace std;

class Tree {
private:
	string sName;
	size_t age;
	double height;
public:
	Tree() = default;
	Tree(const string &s, size_t a, double h) :sName(s), age(a), height(h) {}
};
#endif // !TREE_H
