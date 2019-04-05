/**
 *  \file rajztabla.h
 *  Rajztabla osztály deklarációja
 */

#ifndef RAJZTABLA_H
#define RAJZTABLA_H

#include "alakzat.h"

class Rajztabla {
	Alakzat *alakzatok[100];
	size_t db;
public:
	Rajztabla() :db(0) {}
	void felrak(Alakzat* a) { alakzatok[db++] = a; }
	void rajzol();
	void mozgat(const Pont&);
	void torol();
	virtual ~Rajztabla() { torol(); }
	Rajztabla(const Rajztabla&);
	Rajztabla& operator=(const Rajztabla &);
};

#endif // RAJZTABLA_H
