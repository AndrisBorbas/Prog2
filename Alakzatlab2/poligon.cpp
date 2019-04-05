/**
 *  \file kor.cpp
 *  Poligon osztály tagfüggvényinek megvalósítása
 */

#include <stdexcept>
#include "poligon.h"

Pont Poligon::getcsp(size_t i) const {
    if (i >= np) throw std::out_of_range("Poligon: nincs ilyen csucspont!");
    if (i == 0) return p0;
    return pontok[i-1] + p0;    // p0-hoz képest relatívan tárolunk
}

void Poligon::add(const Pont& p) {
    Pont *tp = new Pont[np];
    for (size_t i = 0; i < np-1; i++)
        tp[i] = pontok[i];
    delete[] pontok;
    pontok = tp;
    pontok[np-1] = p - p0;      // kezdőponthoz képest relatívan tárolunk
    ++np;
}

void Poligon::rajzol() {
    std::cout << "Rajzol: " << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Poligon& k) {
    os << "Poligon " << (Alakzat&)k << ",csp=" << k.getnp();
    for (size_t i = 1; i < k.getnp(); ++i)
       os << ",p" << i << "=" << k.getcsp(i);
    return os;
}

