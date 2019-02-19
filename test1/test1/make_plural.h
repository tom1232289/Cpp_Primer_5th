#pragma once
#ifndef MAKE_PLURAL_INCLUDE
#define MAKE_PLURAL_INCLUDE

#include<iostream>
#include<string>

using namespace std;

inline string make_plural(size_t ctr, const string &word, const string &ending) {
	return (ctr > 1) ? word + ending : word;
}

#endif // !MAKE_PLURAL_INCLUDE
