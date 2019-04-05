/**
 *  \file rajztabla.cpp
 *   Rajztábla osztály tagfüggvényinek megvalósítása
 */

#include <stdexcept>
#include "rajztabla.h"

void Rajztabla::rajzol() {
	for (unsigned int i = 0; i < db; i++) {
		alakzatok[i]->rajzol();
	}
}

void Rajztabla::mozgat(const Pont& d) {
	for (size_t i = 0; i < db; i++)
		alakzatok[i]->mozgat(d);
}

void Rajztabla::torol() {
	for (unsigned int i = 0; i < db; i++) {
		if (alakzatok[i] != nullptr) {
			delete alakzatok[i];
		}
	}
	db = 0;
}

Rajztabla::Rajztabla(const Rajztabla &r) {
	db = r.db;
	for (unsigned int i = 0; i < db; i++) {
		alakzatok[i] = r.alakzatok[i]->clone();
	}
}

Rajztabla & Rajztabla::operator=(const Rajztabla &rhs) {
	if (this != &rhs) {
		torol();
		db = rhs.db;
		for (unsigned int i = 0; i < db; i++) {
			alakzatok[i] = rhs.alakzatok[i]->clone();
		}
	}
	return (*this);
}
