#pragma once
#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H

#include "Quote.h"

class Disc_quote :public Quote
{
public:
	Disc_quote(const string &s, double p, size_t q, double disc) :
		Quote(s, p),
		quantity(q),
		discount(disc) {	}
	double net_price(size_t n) const = 0;
protected:
	size_t quantity;
	double discount;
};

#endif	// !DISC_QUOTE_H