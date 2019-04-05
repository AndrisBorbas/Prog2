/**
 *  \file teglalap.cpp
 *  Teglalap osztály tagfüggvényinek megvalósítása
 */
#include "teglalap.h"

/// Téglalapot rajzoló rajzol fv.
void Teglalap::rajzol() {
    std::cout << "Rajzol: " << *this << std::endl;
}

/// Globális << operátor
std::ostream& operator<<(std::ostream& os, const Teglalap& t) {
    return os << "Teglalap " << (Alakzat&)t << ",p1=" << t.getp1();
}
