#pragma once
#ifndef BASKET_H
#define BASKET_H

#include <iostream>
#include <set>
#include <memory>
#include "Quote.h"

using namespace std;

class Basket
{
public:
	void add_item(const shared_ptr<Quote> &sale) {
		items.insert(sale);
	}
	double total_receipt(ostream &os) const;
private:
	static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs) {
		return lhs->isbn() < rhs->isbn();
	}
private:
	multiset<shared_ptr<Quote>, decltype(compare)*> items{ compare };
};

#endif	// !BASKET_H