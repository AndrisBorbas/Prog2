#ifndef STRING_H
#define STRING_H
/**
 * \file string5.h
 *
 * Ez a fájl tartalmazza a String osztály deklarációját és inline függvényeit.
 */

#include <iostream>

/**
 * String osztály.
 * A pData-ban vannak a karakterek (a lezáró nullával együtt),
 * len a hossz.A hosszba nem számít bele a lezáró nulla.
 */
class String {
    char *pData;    ///< pointer az adatra
    size_t len;     ///< hossz lezáró nulla nélkül
public:


    /// Hossz lekérdezése.
    /// @return Sztring hossza
	size_t size() const { return len; }


    /// Default konstruktor
    /// String() :pData(0), len(0) {}
    /// helyett ""-val inicializáljuk a const char*-osban

    /// C-sztringet ad vissza
    /// @return pinter egy '\0'-val lezárt (C) sztringre
    const char* c_str() const { return pData;}

    /// Konstruktor egy char karakterből
    /// @param ch - karakter
    String(char ch);

    /// Konstruktor egy nullával lezárt char sorozatból
    /// Ez a deafault is!
    /// @param p - pointer egy C sztringre
    String(const char *p = "");

    /// Másoló konstruktor
    /// @param s1 - String, amiből létrehozzuk az új String-et
    String(const String& s1);

    /// Destruktor
    virtual ~String() { delete[] pData; }

    /// Kiírunk egy Stringet (debug célokra)
    /// Előtte kiírunk egy tetszőleges szöveget.
    /// @param txt - nullával lezárt szövegre mutató pointer
    void printDbg(const char *txt = "") const {
        std::cout << txt << "[" << len << "], "
                  << (pData ? pData : "(NULL)") << std::endl;
    }

    /// Értékadó operátor.
    /// @param rhs_s - jobboldali String
    /// @return baoldali (módosított) string (referenciája)
    String& operator=(const String& rhs_s);

    /// Két Stringet összefűz
    /// @param rhs_s - jobboldali String
    /// @return új String, ami tartalmazza a két stringet egmás után
    String operator+(const String& rhs_s) const ;

    /// Sztrinhez karaktert összefűz
    /// @param rhs_c - jobboldali karakter
    /// @return új String, ami tartalmazza a sztringet és a karaktert egymás után
    String operator+(char rhs_c) const { return *this + String(rhs_c);}

    /// A string egy megadott indexű elemének REFERENCIÁJÁVAL tér vissza.
    /// @param idx - charakter indexe
    /// @return karakter (referencia)
    ///         Indexelési hiba esetén const char* kivételt dob.
    char& operator[](unsigned int idx);

    /// A string egy megadott indexű elemének REFERENCIÁJÁVAL tér vissza.
    /// @param idx - karakter indexe
    /// @return karakter (referencia)
    ///         Indexelési hiba esetén const char* kivételt dob (assert helyett).
    const char& operator[](unsigned int idx) const;
};

/// Globális függvények:
/// kiír az ostream-re
/// @param os - ostream típusú objektum
/// @param s0 - String, amit kiírunk
/// @return os
std::ostream& operator<<(std::ostream& os, const String& s0);

/// Beolvas az istream-ről egy szót egy string-be.
/// @param is - istream típusú objektum
/// @param s0 - String, amibe beolvas
/// @return is
std::istream& operator>>(std::istream& is, String& s0);

/// Karakterhez sztringet fűz
/// @param ch - karakter
/// @param str - String
/// @return új String, ami tartalmazza a karaktert és a sztringet egymás után
inline String operator+(char ch, const String& str) { return String(ch) + str; }

#endif
