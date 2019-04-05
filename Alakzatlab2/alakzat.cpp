/**
 *  \file kor.cpp
 *  Alakzat osztály tagfüggvényinek megvalósítása
 */
#include "alakzat.h"

/// mozgat - eltolja az alakzat origóját
/// @param d - eltolás vektora
void Alakzat::mozgat(const Pont& d) {
    Szin tsz = sz; 	/// tényleges rajzolási szín elmentése
    sz = BACKGND;   // rajzolási szín legyen a háttér színe
    rajzol(); 		// A vonal letörlés az eredeti helyről
    p0 += d;  	    // mozgatás: a pozíció változik
    sz = tsz;		// rajzolási szín a tényleges szín
    rajzol(); 		// A vonal felrajzolása az új pozícióra
}

/// Globális << operátor
std::ostream& operator<<(std::ostream& os, const Alakzat& a) {
    return os << "p0=" << a.getp0() << ",szin=" << a.getsz();
}
