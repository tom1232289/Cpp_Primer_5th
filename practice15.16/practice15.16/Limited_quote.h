#pragma once
#ifndef LIMITED_QUOTE_H
#define LIMITED_QUOTE_H

#include "Disc_quote.h"

class Limited_quote :public Disc_quote
{
public:
	Limited_quote(const string &s,double p,size_t maxq,double disc):
		Disc_quote(s,p,maxq,disc){	}
public:
	double net_price(size_t n) const override {
		if (n <= quantity)
			return price * (1 - discount)*n;
		else
			return price * (1 - discount)*quantity + price * (n - quantity);
	}
};

#endif	// !LIMITED_QUOTE_H