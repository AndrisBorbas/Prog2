/**
 * \file resistor.cpp
 *   (UTF-8 kodolasu fajl. Allitsa at a megjenetes kodolasat,
 *    ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * Ohmikus ellenállást modellező osztály megvalósítása
 */

 /**
  * Itt kell megvalósítani a resistor.h-ban deklarált nem inline függvényeket.
  * A Jportára ezt a fájlt kell feltölteni.
  */

#include "resistor.h"

	/// Konstruktor.
	/// R alapértelmezett értéket (defR-t) kap
	Resistor::Resistor() {
#ifndef NO_STATIC
		R = defR;
#endif
	}

	/// Konstruktor.
	/// @param r - ellenállás értéke [ohm]
	Resistor::Resistor(double r) {
		R = r;
	}

	/// Alapértelmezett ellenállásérték beállítása
	/// @param r - ellenállás értéke [ohm]
#ifndef NO_STATIC
	double Resistor::defR = 93;

	void Resistor::setDef(double r) {
		defR = r;
	}
#endif

	/// Két ellenállás soros kapcsolása.
	/// @param r - ellenállás
	/// @return  - eredőként létrejövő ellenállás
	Resistor Resistor::operator+(const Resistor& r) const {
		return Resistor(this->R + r.R);
	}

	/// Két ellenállás párhuzamos kapcsolása.
	/// @param r - ellenállás
	/// @return  - eredőként létrejövő ellenállás
	Resistor Resistor::operator%(const Resistor& r) const {
		return Resistor(1 / ((1 / this->R) + (1 / r.R)));
	}

/// Többszörös: n darab egyforma r ellenállás összege (soros kapcsolása).
/// @param n - darabszám, ha n <= 0, akkor kivételt dob
/// @param r - ellenállás
/// @return  - eredőként létrejövő ellenállás
Resistor operator*(int n, const Resistor& r) {
	if (n <= 0) {
		throw "F0PQGO";
	}
	else {
		return Resistor(double(n*r.getR()));
	}
}
