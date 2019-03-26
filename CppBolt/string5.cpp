/**
 *
 * \file string5_kesz.cpp
 *
 * Itt kell megvalĂłsĂ­tania a hiĂĄnyzĂł tagfĂźggvĂŠnyeket.
 * SegĂ­tsĂŠgĂźl megadtuk a C-ben megĂ­rt vĂĄltozatban (string1.c) hasznĂĄlt fĂźggvĂŠnyneveket.
 *
 * Ha valamit INLINE-kĂŠnt valĂłsĂ­t meg, akkor annak a .h-ba kell kerĂźlnie,
 * akĂĄr kĂ­vĂźl akĂĄr osztĂĄlyon belĂźl definiĂĄlja. (Az inline fĂźggvĂŠnyeknek minden
 * fordĂ­tĂĄsi egysĂŠgben elĂŠrhetĹknek kell lenniĂźk)
 * *
 * A tesztelĂŠskor ne felejtse el beĂĄllĂ­tani a header ĂĄllomĂĄnyban az ELKESZULT makrĂłt.
 * A VC sajĂĄt memĂłriafogyĂĄs ellenĹrzĹje csak debug mĂłdban (Debug->Start) mĹąkĂśdik!
 *
 */

#ifdef _MSC_VER
 // MSC ne adjon figyelmeztetĹ Ăźzenetet a stringkezelĹ fĂźggvĂŠnyekre.
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>             // KiĂ­ratĂĄshoz
#include <cstring>              // StringmĹąveletekhez

#include "memtrace.h"           // a standard headerek utĂĄn kell lennie
#include "string5.h"

using std::cin;
using std::ios_base;

/// Konstruktor: egy char karakterbĹl (createStrFromChar)
String::String(char ch) {
	// MeghatĂĄrozzuk a hosszĂĄt
	len = 1;
	// Lefoglalunk a helyet a hossznak + a lezarĂł nullĂĄnak
	pData = new char[len + 1];
	// BetesszĂźk a karaktert
	pData[0] = ch;
	pData[1] = '\0';
}


// Konstruktor: egy nullĂĄval lezĂĄrt char sorozatbĂłl (createStringFromCharStr)
String::String(const char *p) {
	// MeghatĂĄrozzuk a hosszĂĄt
	len = strlen(p);
	// Helyet foglalunk
	pData = new char[len + 1];
	// BemĂĄsoljuk a stringet, ami le van zĂĄrva 0-val Ă­gy hasznĂĄlhatĂł az strcpy is
	strcpy(pData, p);
}

// MĂĄsolĂł konstruktor
String::String(const String& s1) {
	// MeghatĂĄrozzuk a hosszĂĄt
	len = s1.len;
	// Helyet foglalunk
	pData = new char[len + 1];
	// BemĂĄsoljuk a stringet, ami le van zĂĄrva 0-val Ă­gy hasznĂĄlhatĂł az strcpy is
	strcpy(pData, s1.pData);
}

// operator=
String& String::operator=(const String& rhs_s) {
	if (this != &rhs_s) {
		delete[] pData;
		len = rhs_s.len;
		// Helyet foglalunk
		pData = new char[len + 1];
		// BemĂĄsoljuk a stringet, ami le van zĂĄrva 0-val Ă­gy hasznĂĄlhatĂł az strcpy is
		strcpy(pData, rhs_s.pData);
	}
	return *this;
}

// [] operĂĄtorok: egy megadott indexĹą elem REFERENCIĂJĂVAL tĂŠrnek vissza.
// indexhiba esetĂŠn dobjon egy const char * tĂ­pusĂş hibĂĄt!
char& String::operator[](unsigned int idx) {
	if (idx >= len) throw "String: indexelesi hiba";
	return pData[idx];
}

const char& String::operator[](unsigned int idx) const {
	if (idx >= len) throw "String: indexelesi hiba";
	return pData[idx];
}

// + operĂĄtor, ami kĂŠt stringet ad Ăśssze (concatString)
String String::operator+(const String& rhs_s) const {
	String temp;		// ide kerĂźl az eredmĂŠny
	// MeghatĂĄrozza az Ăşj string hosszĂĄt
	temp.len = len + rhs_s.len;
	// FelszabadĂ­tja a temp adattaerĂźletĂŠt
	delete[]temp.pData;
	// lefoglalja a memĂłriĂĄt az Ăşj stringnek.
	temp.pData = new char[temp.len + 1];
	// Az elejĂŠre bemĂĄsolja az elsĹ stringet
	strcpy(temp.pData, pData);
	// BemĂĄsolja a mĂĄsodik stringet.
	strcat(temp.pData, rhs_s.pData);

	return temp;		// visszatĂŠr az eredmĂŠnnyel

}
// << operator, ami kiĂ­r az ostream-re
std::ostream& operator<<(std::ostream& os, const String& s0) {
	os << s0.c_str();
	return os;
}

// << operĂĄtor, ami beolvas az istreamrĹl egy szĂłt
std::istream& operator>>(std::istream& is, String& s0) {
	unsigned char ch;
	s0 = String("");            // Ăźres string, ehhez fĹązĂźnk hozzĂĄ
	std::ios_base::fmtflags fl = is.flags(); // eltesszĂźk a rĂŠgi flag-eket
	is.setf(ios_base::skipws);			// az elejĂŠn eldobjuk a ws-t
	while (is >> ch) {
		is.unsetf(ios_base::skipws);	// utĂĄna pedig mĂĄr nem
		if (isspace(ch)) {
			is.putback(ch);             // na ezt nem kĂŠrjĂźk
			break;
		}
		else {
			s0 = s0 + ch;               // vĂŠgĂŠre fĹązzĂźk a karaktert
		}
	}
	is.setf(fl);						// visszaĂĄllĂ­tjuk a flag-eket
	return is;
}
