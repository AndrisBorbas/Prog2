#pragma once

#define ELKESZULT 7

#include <iostream>

template <typename Iter>
void printEach(Iter first, Iter last, std::ostream& os = std::cout, const char * sep = ", ") {
	while (true) {
		os << *first++;
		if (first == last) {
			os << std::endl;
			break;
		}
		else {
			os << sep;
		}
	}
}

template <typename Iter>
int szamol_ha_negativ(Iter first, Iter last) {
	int db = 0;
	while (first != last) {
		if (*first++ < 0) {
			db++;
		}
	}
	return db;
}

template <typename T>
class nagyobb_mint {
	T t;
public:
	nagyobb_mint(T x) :t(x) {}
	bool operator()(T x) {
		return x > t;
	}
};

template <typename Iter, typename Pred>
int szamol_ha(Iter first, Iter last, Pred pred) {
	int db = 0;
	while (first != last) {
		if (pred(*first++)) {
			db++;
		}
	}
	return db;
}