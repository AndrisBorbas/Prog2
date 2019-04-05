/**
 *  \file szakasz.h
 *  Szakasz osztály deklarációja
 */
#ifndef SZAKASZ_H
#define SZAKASZ_H

#include "alakzat.h"

/// Szakasz osztály
class Szakasz : public Alakzat {
    Pont pv;    ///< szakasz végpontja az origóhoz (p0-hoz) képest
public:
    /// konstruktor 2 pontból
    /// @param p0 - kezdőpont
    /// @param pv - végpont
    /// @param sz - szín és átlátszóság
    Szakasz(const Pont& p0, const Pont& pv, Szin sz)
                     : Alakzat(p0, sz), pv(pv-p0) { }

    /// konstruktor 1 pontból és 2 hosszból
    /// @param p0 - kezdőpont
    /// @param xl - x irányú hossz
    /// @param yl - y irányú hossz
    /// @param sz - szín és átlátszóság
    Szakasz(const Pont& p0, int xl, int yl, Szin sz)
                     : Alakzat(p0, sz), pv(Pont(xl, yl)) { }

    /// Szakasz végpontjának lekérdezése
    /// @return szakasz végpontja
    Pont getpv() const { return pv+p0; }    // p0-hoz lépest relatívan tárolunk

    /// szakaszt rajzol
    void rajzol();	    // átdefiniáljuk a virt. fv-t.

	Alakzat* clone() { return new Szakasz(*this); }
};

/// Globális << operátor
std::ostream& operator<<(std::ostream& os, const Szakasz& k);

#endif // SZAKASZ_H
