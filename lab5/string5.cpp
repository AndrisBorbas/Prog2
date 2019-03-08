/**
 *
 * \file string5.cpp
 *
 * Itt kell megvalósítania a hiányzó tagfüggvényeket.
 * Segítségül megadtuk a C++ nem OO eszközeinek felhasználásával készített String-kezelő
 * függvényke neveit.
 *
 * Ha valamit INLINE-ként valósít meg, akkor annak a string5.h-ba kell kerülnie,
 * akár kívül akár osztályon belül definiálja. (Az inline függvényeknek minden
 * fordítási egységben elérhetőknek kell lenniük)
 * *
 * A teszteléskor ne felejtse el beállítani a string5.h állományban az ELKESZULT makrót.
 *
 */

#ifdef _MSC_VER
// MSC ne adjon figyelmeztető üzenetet a C sztringkezelő függvényeire
  #define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>             // Kiíratáshoz
#include <cstring>              // Sztringműveletekhez

#include "memtrace.h"           // a standard headerek után kell lennie
#include "string5.h"


/// Konstruktorok: egy char karakterből (createString)
///                egy nullával lezárt char sorozatból (createString)

String::String(char c) {
	len = 1;
	pData = new char[len + 1];
	pData[0] = c;
	pData[1] = '\0';
}

String::String(char* s) {
	len = strlen(s);
	pData = new char[len + 1];
	strcpy(pData, s);
}

String::String(const char* s) {
	len = strlen(s);
	pData = new char[len + 1];
	strcpy(pData, s);
}

/// Másoló konstruktor: String-ből készít (createString)

String::String(const String& rhs) {
	len = rhs.len;
	pData = new char[len + 1];
	strcpy(pData, rhs.pData);
}

/// Destruktor (disposeString)

String::~String() {
	delete[] pData;
}

/// operator=

String& String::operator=(const String& rhs) {
	if (this != &rhs) {
		delete[] pData;
		len = rhs.len;
		pData = new char[len + 1];
		strcpy(pData, rhs.pData);
	}
	return *this;
}

/// [] operátorok: egy megadott indexű elem REFERENCIÁJÁVAL térnek vissza (charAtString)
/// indexhiba esetén const char * kivételt dob!



/// + operátorok:
///                 String-hez jobbról karaktert ad (addString)
///                 String-hez String-et ad (addString)

String String::operator+(const String& rhs) const{
	String temp;
	temp.len = len + rhs.len;
	temp.pData = new char[temp.len + 1];
	strcpy(temp.pData, pData);
	strcat(temp.pData, rhs.pData);
	return temp;
}

String String::operator+(const char rhs) const{
	String temp;
	temp.len = len + 1;
	temp.pData = new char[temp.len + 1];
	strcpy(temp.pData, pData);
	temp.pData[temp.len - 1] = rhs;
	temp.pData[temp.len] = '\0';
	return temp;
}

/// << operator, ami kiír az ostream-re


/// >> operátor, ami beolvas az istream-ről egy szót
