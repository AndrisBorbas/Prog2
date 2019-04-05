/**
 *  \file kor.cpp
 *  Kor osztály tagfüggvényinek megvalósítása
 */
#include "kor.h"

/// Kört rajzoló rajzol fv.
void Kor::rajzol() {
    std::cout << "Rajzol: " << *this << std::endl;
}

/// Globális << operátor
std::ostream& operator<<(std::ostream& os, const Kor& k) {
    return os << "Kor " << (Alakzat&)k << ",r=" << k.getr();
}
