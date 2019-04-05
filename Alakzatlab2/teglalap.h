/**
 *  \file teglalap.h
 *  Téglalap osztály deklarációja
 */
#ifndef TEGLALAP_H
#define TEGLALAP_H

#include "alakzat.h"

/// Teglalap osztály
/// Tengelyekkel párhuzamos oldalú téglalap
class Teglalap : public Alakzat {
    Pont p1;  ///< szemben levő csúcspont
public:
    /// Konstruktor
    /// @param p0 - kezdőpont
    /// @param p1 - szemközti csúcspont
    /// @param sz - szín és átlátszóság
    Teglalap(const Pont& p0, const Pont& p1, Szin sz)
                    :Alakzat(p0, sz), p1(p1-p0)  // ös ossztály inic
                    {}

    /// Másik csúcspont lekérdezése
    /// @return másik csúcspont
    Pont getp1() const { return p1+p0; }        // p0-hoz képest relatívan tárolunk

    /// téglalapot rajzol
    void rajzol();

	Alakzat* clone() { return new Teglalap(*this); }
};

/// Globális << operátor
std::ostream& operator<<(std::ostream& os, const Teglalap& t);

#endif // TEGLALAP_H
