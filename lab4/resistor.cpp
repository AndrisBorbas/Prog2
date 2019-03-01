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
#include "gtest_lite.h"

  /// Konstruktor.
  /// R alapértelmezett értéket (defR-t) kap
Resistor::Resistor() {
#ifndef NO_STATIC
	R = defR;
	Pr("ctor0");
#endif
}

/// Konstruktor.
/// @param r - ellenállás értéke [ohm]
Resistor::Resistor(double r) {
	R = r;
	Pr("ctor1");
}

#if ELKESZULT >= 2
/// Másoló konstruktor.
/// @param rhs - objektum amiről a másolatot kell létrehozni
Resistor::Resistor(const Resistor& rhs) :R(rhs.R){
	Pr("copy");
}
#endif  // ELKESZULT == 2

#if ELKESZULT >= 3
/// Destruktor
Resistor::~Resistor() {
	Pr("dtor");
}
#endif  // ELKESZULT == 3

#if ELKESZULT >= 4
/// Értékadás
/// @param rhs - jobb oldali operandus (a bal a *this)
/// @return - referencia saját magára, hogy fűzhető legyen
Resistor& Resistor::operator=(const Resistor& rhs) {
	Pr("assign");
	this->R=rhs.R;
	return *this;
}
#endif  // ELKESZULT == 4

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

#if ELKESZULT >= 5
/// Ellenálláson folyó áram
/// @param u - áram
/// @return  - áram
double Resistor::getI(double u) const {
	return (u / this->R);
}
#endif  // ELKESZULT >= 5

#if ELKESZULT >= 6
/// Ellenálláson eső feszültség
/// @param i - áram
/// @return  - feszültség
double Resistor::getU(double i) const {
	return (i * this->R);
}
#endif  // ELKESZULT >= 6

#if ELKESZULT >= 7
/// Két ellenállás összehasonlítása.
/// @param r - ellenállás
/// @return  - true, ha azonos
bool Resistor::operator==(const Resistor& r) const {
	return gtest_lite::almostEQ(r.R, this->R);
}
#endif  // ELKESZULT == 7

#if ELKESZULT >= 8
std::ostream& operator<<(std::ostream& os, const Resistor& rhs) {
	os << rhs.getR();
	return os;
}
#endif  // ELKESZULT == 8