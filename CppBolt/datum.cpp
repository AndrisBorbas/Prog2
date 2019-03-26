/**
 * \file datum.h
 *
 * Datum osztály tagfüggvényinek megvalósítása (definíciója)
 */
#define _CRT_SECURE_NO_WARNINGS			// VS ne nyafogjon a localtime miatt

#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>

#include "memtrace.h"
#include "datum.h"

using std::setw;
using std::setfill;

/// Paraméter nélkül hívható konstruktor.
/// Mai napot állítja be
Datum::Datum() {
    time_t tim;
    tim = time(NULL);       // lekérdezzük a jelenlegi időt
    struct tm *tp = localtime(&tim);  // átalakítjuk
    ev = tp->tm_year+1900;
    ho = tp->tm_mon+1;
    nap = tp->tm_mday;

}

/// Globális inserter eeee-hh-nn formában
/// @param os - output stream referencia
/// @param s - Datum referencia
/// @return output stream referencia
std::ostream& operator<<(std::ostream& os, const Datum& d) {
    return os << setw(4) << d.getEv() << "-"
       << setw(2) << setfill('0') << d.getHo() << "-"
       << setw(2) << d.getNap();
}
