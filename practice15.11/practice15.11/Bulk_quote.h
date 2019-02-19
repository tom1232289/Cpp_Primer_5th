#pragma once
#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include "Quote.h"

class Bulk_quote :public Quote
{
public:
	Bulk_quote(const string &s, double p, size_t minq, double disc) :
		Quote(s, p),
		min_qt(minq),
		discount(disc) {	}
public:
	double net_price(size_t cnt) const override {
		if (cnt >= min_qt)
			return price * (1 - discount)*cnt;
		else
			return price * cnt;
	}
	void debug() override {
		Quote::debug();
		cout << "min_qt=" << min_qt << " discount=" << discount << endl;
	}
private:
	size_t min_qt;
	double discount;
};

#endif	// !BULK_QUOTE_H