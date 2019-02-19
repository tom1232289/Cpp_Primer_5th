#pragma once
#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include "Disc_quote.h"

class Bulk_quote :public Disc_quote
{
public:
	Bulk_quote(const string &s,double p,size_t q,double disc):
		Disc_quote(s,p,q,disc){	}
	double net_price(size_t n) const override {
		if (n >= quantity)
			return price * (1 - discount)*n;
		else
			return price * n;
	}
};

#endif	// !BULK_QUOTE_H