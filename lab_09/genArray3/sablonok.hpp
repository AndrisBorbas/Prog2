#pragma once

#define ELKESZULT 17

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

/// F�ggv�nysablon, ami ki�rja egy generikus t�mb adatait
/// Felt�telezz�k, hogy a generikus t�mbnek van: 
///�� - ForwardIteratora, size(), valamint capacity() tagf�ggv�nye
/// @param T�� - sablon param�ter: iter�toros t�mb t�pus
/// @param txt - ki�rand� sz�veg
/// @param arr - konkr�t t�mb
/// @param os� - output steram 
template <class T>
void PrintArray(const char *txt, const T& arr, std::ostream& os = std::cout) {
	os << txt << " size=" << arr.size()
		<< " capacity=" << arr.capacity() << std::endl;
	os << "\t data=";
	printEach(arr.begin(), arr.end(), os, ",");

}

template <typename T>
class ostreamFunctor {
	std::ostream& os;
	std::string sep;
public:
	ostreamFunctor(std::ostream& os, std::string sep) :os(os), sep(sep) {}
	void operator()(T x) {
		os << x << sep;
	}
};

template <typename InputIterator, class Func>
Func forEach(InputIterator first, InputIterator last, Func func) {
	while (first != last) {
		func(*first++);
	}
	return func;
}