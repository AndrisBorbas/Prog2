/**
 *  \file haromszog.cpp
 *  Haromszog osztály tagfüggvényinek megvalósítása
 */
#include "haromszog.h"

/// Háromszög rajzoló rajzol fv.
void Haromszog::rajzol() {
    std::cout << "Rajzol: " << *this << std::endl;
}

/// Globális << operátor
std::ostream& operator<<(std::ostream& os, const Haromszog& h) {
    return os << "Haromszog " << (Alakzat&)h << ",p1=" << h.getp1() << ",p2=" << h.getp2();
}
