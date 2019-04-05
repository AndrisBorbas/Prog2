/**
 *  \file szakasz.cpp
 *  Szakasz osztály tagfüggvényinek megvalósítása
 */
#include "szakasz.h"

/// Szakaszt rajzoló rajzol fv.
void Szakasz::rajzol() {
    std::cout << "Rajzol: " << *this << std::endl;
}

/// Globális << operátor
std::ostream& operator<<(std::ostream& os, const Szakasz& sz) {
    return os << "Szakasz " << (Alakzat&)sz << ",pv=" << sz.getpv();
}
