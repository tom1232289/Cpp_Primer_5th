#pragma once
class Debug {
public:
	constexpr Debug(bool b = true) :hw(b), io(b), other(b) {  }
	constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {  }
	constexpr bool any() { return hw || io || other; }
private:
	bool hw;
	bool io;
	bool other;
};