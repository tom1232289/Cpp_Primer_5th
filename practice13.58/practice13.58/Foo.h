#pragma once
#ifndef FOO_H
#define FOO_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Foo
{
public:
	Foo sorted() && ;
	Foo sorted() const &;
private:
	vector<int> data;
};

#endif	// !FOO_H