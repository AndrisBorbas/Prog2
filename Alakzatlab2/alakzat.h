/**
 *  \file alakzat.h
 *  Alakzat alaposztály deklarációja
 */
#ifndef ALAKZAT_H
#define ALAKZAT_H

#include <iostream>         // ostream miatt kell
#include "memtrace.h"       // így mindenki include-olni fogja, mert az alaposztályt minden fordítási egység
#include "pont.h"
#include "szin.h"
#include <vector>


 /// Alakzat abszrakt osztály
class Alakzat {
protected:
	Pont p0;                   ///< alakzat origója
	Szin sz;                   ///< alakzat színe
public:
	/// Konstruktor
	/// @param p0 - kezdőpont
	/// @param sz - szín és átlátszóság
	Alakzat(const Pont& p0, const Szin& sz) :p0(p0), sz(sz) {}

	/// Pozíció lekérdezése
	/// @return alakzat origója
	Pont getp0() const { return p0; }

	/// Szin lekérdezése
	/// @return alakzat színe
	Szin getsz() const { return sz; }

	/// mozgat: origóját eltolja
	/// @param d - eltolás vektora
	void mozgat(const Pont& d);

	/// rajzol
	virtual void rajzol() = 0;

	/// Destruktor virtuális, hogy lehessen dinamikus adattagja
	/// a származtatottnak
	virtual ~Alakzat() {}

	virtual Alakzat* clone() = 0;
};

/// Globális << operátor
std::ostream& operator<<(std::ostream&, const Alakzat&);

#endif // ALAKZAT_H
