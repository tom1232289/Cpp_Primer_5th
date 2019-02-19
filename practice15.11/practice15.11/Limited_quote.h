#pragma once
#ifndef LIMITED_QUOTE_H
#define LIMITED_QUOTE_H

#include "Quote.h"

class Limited_quote :public Quote
{
public:
	Limited_quote(const string &s,double p,size_t maxq,double disc):
		Quote(s,p),
		max_qt(maxq),
		discount(disc){	}
public:
	double net_price(size_t n) const override {
		if (n <= max_qt)
			return price * (1 - discount)*n;
		else
			return price * (1 - discount)*max_qt + price * (n - max_qt);
	}
private:
	size_t max_qt;
	double discount;
};

#endif	// !LIMITED_QUOTE_H