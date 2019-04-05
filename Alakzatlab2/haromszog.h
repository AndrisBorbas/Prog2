/**
 *  \file haromszog.h
 *  Haromszog osztály deklarációja
 */
#ifndef HAROMSZOG_H
#define HAROMSZOG_H

#include "alakzat.h"

/// Haromszog osztály
class Haromszog : public Alakzat {
    Pont p1;  ///< második csúcspont
    Pont p2;  ///< harmadik csúcspont
public:
    /// Konstruktor
    /// @param p0 - kezdőpont
    /// @param p1 - második csúcspont
    /// @param p2 - harmadik csúcspont
    /// @param sz - szín és átlátszóság
    Haromszog(const Pont& p0, const Pont& p1, const Pont &p2, Szin sz)
                    :Alakzat(p0, sz), p1(p1-p0), p2(p2-p0)  // ős osztály inic.
                    {}

    /// Második csúcspont lekérdezése
    /// @return második csúcspont
    Pont getp1() const { return p1+p0; }        // p0-hoz képest relatívan tárolunk

    /// Harmadik csúcspont lekérdezése
    /// @return harmadik csúcspont
    Pont getp2() const { return p2+p0; }        // p0-hoz képest relatívan tárolunk

    /// háromszöget rajzol
    void rajzol();

	Alakzat* clone() { return new Haromszog(*this); }
};

/// Globális << operátor
std::ostream& operator<<(std::ostream& os, const Haromszog& t);

#endif // HAROMSZOG_H
