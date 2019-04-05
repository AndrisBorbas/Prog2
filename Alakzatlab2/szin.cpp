/**
 *  \file szin.cpp
 *  Szin függvényeinek megvalósítása
 */
#include "szin.h"

// Szinek szövegkonstansai
static const char* szinek[] = { "BLACK", "WHITE", "RED", "GREEN", "BLUE" } ;

/// Globális << operátor
/// Nincs ellenőrzés a túlindexelésre !
std::ostream& operator<<(std::ostream& os, Szin sz) {
     return os << szinek[sz];
}
