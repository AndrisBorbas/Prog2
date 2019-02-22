/**
 * \file komplex.cpp
 *
 * Komplex osztályt megvalósító függvények definíciója.
 *
 * Folytassa a megvalósítást sorrendben a komplex.h fájlban levő feladatoknak megfelelően!
 *
 */


#include <iostream>         // Valószínű, hogy a kiíráshoz majd kell
#include <iomanip>          // ... és ez is.
#include <cmath>            // az sqrt miatt kell.

#include "komplex.h"        // Ebben van a Komplex osztály, és néhány globális függvény deklarációja

 ///using namespace std;  // ha nagyon kell, akkor csak itt nyissuk ki a névteret, a headerben soha!

 /// Előre elkészített tagfüggvények

 /// 0, 1 és 2 paraméteres konstruktor
 /// Figyelje meg, hogy a default argumentumokat CSAK a deklarációnál
 /// adtuk meg!
Komplex::Komplex(double r, double im) {
	re = r; // ha nincs névütközés, nem kell kiírni a this-t
	this->im = im;
}

///---- Egy példa a konstans tagfüggvényre, ehhez hasonlóan kell
///     elkészíteni a gettereket az 1. feladatban (ELKESZULT=1)
/// Abszolút érték lekérdezése
/// @return - abszolút érték
double Komplex::abs() const { return sqrt(re*re + im * im); }

#if ELKESZULT >= 1

double Komplex::getRe() const { return re; }

double Komplex::getIm() const { return im; }

#endif

#if ELKESZULT >= 2
// beállító függvények
/// Valós részt beállító függvény
/// @param r - valós rész
void Komplex::setRe(double re) {
	this->re = re;
}

/// Képzetes részt beállító függvény
/// @param im - képzetes rész
void Komplex::setIm(double im) {
	this->im = im;
}
#endif

#if ELKESZULT >= 3
// 3. feladathoz (ELKESZULT 3)
// összehasonlítás
/// Egyenlőtlenség vizsgálat
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return hamis - ha a képzetes és a valós rész is azonos, egyébként false

bool Komplex::operator==(const Komplex& rhs_k) const {
	return (this->im == rhs_k.im && this->re == rhs_k.re);
}

bool Komplex::operator!=(const Komplex& rhs_k) const {
	return !(*this == rhs_k);
}
#endif

#if ELKESZULT >= 4
// összeadás, a + nem módosítja önmagát ezért konstans fv.
/// Komplex + Komplex
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return egy új komplex adat - a két komplex adat összege
Komplex Komplex::operator+(const Komplex& rhs_k) const {
	Komplex add(0, 0);
	add.setRe(this->re + rhs_k.re);
	add.setIm(this->im + rhs_k.im);
	return add;
}

/// Komplex + double
/// @param rhs_d - jobb oldali operandus (double)
/// @return egy új komplex adat - a két adat összege
Komplex Komplex::operator+(double rhs_d) const {
	Komplex add(0, 0);
	add.setRe(this->re + rhs_d);
	add.setIm(this->im);
	return add;
}
#endif



#if ELKESZULT >= 6
// 6. feladathoz (ELKESZULT 6)
// a += művelet viszont módosítja önmagát!
	/// Komplex + Komplex
	/// @param rhs_k - jobb oldali operandus (Komplex)
	/// @return eredeti (bal oldali) objektum ref., amihez hozzáadtuk rhd_k-t
Komplex& Komplex::operator+=(const Komplex& rhs_k) {
	this->re += rhs_k.re;
	this->im += rhs_k.im;
	return *this;
}

/// Komplex + double
/// @param rhs_d - jobb oldali operandus (double)
/// @return eredeti (bal oldali) objektum ref., amihez hozzáadtuk rhd_d-t
Komplex& Komplex::operator+=(double rhs_d) {
	re += rhs_d;
	return *this;
}
#endif


#if ELKESZULT >= 8
/// komplex konjugált
/// ~Komplex
/// @return egy új adat, amiben a konjugált érték van
Komplex Komplex::operator~() const {
	return Komplex(this->re, (this->im)*-1);
}
#endif

#if ELKESZULT >= 9
// szorzás, a * nem módosítja önmagát ezért konstans fv.
/// Komplex * Komplex
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return egy új komplex adat - a két komplex adat szorzata
Komplex operator*(const Komplex& rhs_k) const;

/// Komplex * double
/// @param rhs_d - jobb oldali operandus (double)
/// @return egy új komplex adat - a két adat szorzata
Komplex operator*(double rhs_d) const;

/// double * Komplex csak globális függvénnyel valósítható meg,
/// mivel a bal oldal nem osztály
/// Ld. az osztály deklarációja után!

// a *= művelet viszont módosítja önmagát!
/// Komplex * Komplex
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return eredeti (bal oldali) objektum ref., amit megszorosztunk
Komplex& operator*=(const Komplex& rhs_k);

/// Komplex + double
/// @param rhs_d - jobb oldali operandus (double)
/// @return eredeti (bal oldali) objektum ref., amit megszoroztunk
Komplex& operator*=(double rhs_d);
#endif


#if ELKESZULT >= 5
/// double + Komplex csak globális függvénnyel valósítható meg,
/// mivel a bal oldal nem osztály.
/// Ld. az osztály deklarációja után!
Komplex operator+(double lhs_d, const Komplex& rhs_k) {
	Komplex add(0, 0);
	add.setRe(rhs_k.getRe() + lhs_d);
	add.setIm(rhs_k.getIm());
	return add;
}

#endif

#if ELKESZULT >= 7
// cout << Komplex is csak globális függvénnyel valósítható meg, mivel
// az baloldali osztály (ostream) nincs a kezünkben, nem módosítható
/// Kiírás egy ostream-re
/// @param os - bal oldali operandus (ostream)
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return ostream&, hogy fűzhető legyen
std::ostream& operator<<(std::ostream& os, const Komplex& rhs_k) {
	if (rhs_k.getIm() >= 0)
		os << rhs_k.getRe() << "+" << rhs_k.getIm() << "j";
	else
		os << rhs_k.getRe() << rhs_k.getIm() << "j";
	return os;
}

/// Beolvasás egy istream-ről
/// @param is - bal oldali operandus (istream)
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return istream&, hogy fűzhető legyen
std::istream& operator>>(std::istream& is, Komplex& rhs_k) {
	double r, i;
	char j;
	is >> r >> i >> j;
	rhs_k.setRe(r);
	rhs_k.setIm(i);
	return is;
}
#endif

#if ELKESZULT >= 9
// double * Komplex csak globális függvénnyel valósítható meg,
// mivel a bal oldal nem osztály
/// double * Komplex
/// @param lhs_d - bal oldali operandus (double)
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return egy új komplex adat - a két adat szorzata
Komplex operator*(double lhs_d, const Komplex& rhs_k);
#endif