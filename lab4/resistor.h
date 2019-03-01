#ifndef RESISTOR_H
#define RESISTOR_H
/**
 * \file resistor.h
 *
 * Az CPP Ellenallas Jporta feladat Resistor osztálya
 * a 4. laborgyakorlathoz kiegészítve
 *
 * Az Ön feladata a Jporta feladathoz elkészített resistor.cpp fájt kiegészíteni a hiányzó függvényekkel.
 * Ahogyan halad a megvalósítással egyre több tesztesetet kell lefuttatni,
 * ezért az ELKESZULT makró értéket a készültségi foknak megfelelően állítsa be az
 * elkeszult.h fájlban!
 * Ne hagyjon ki feladatot, sorban haladjon!
 *
 * Ebben a fájlban nem kell módosítania semmit, ugyanakkor célszerű a megvalósítandó tagfüggvények
 * deklarációi kommentekkel együtt átmásolni a resistor.ccp-be, és azokat átalakítani definíciókká.
 * Másolásnál ügyeljen arra, hogy a kontextus (scope) megváltozik.
 */

#include <iostream>

#ifdef DEBUG
# define Pr(str) std::cout << str <<std::endl
#else
# define Pr(...)
#endif

#include "elkeszult.h"

/**
 * Ohmikus ellenállás
 */
class Resistor {
    double R;              	// az ellenállás értéke ohmban
    static double defR;  	// ellenállás alapértelmezett értéke ohmban
public:

    /// Konstruktor.
    /// Alapértelmezett értéket (defR) kap
    Resistor();

    /// Konstruktor.
    /// @param r - ellenállás értéke [ohm]
    Resistor(double r);

    /// Default ellenállásérték beállítása
    /// @param r - ellenállás értéke [ohm]
    static void setDef(double r);

    /// Ellenállás értékének lekérdezése.
    /// @return - ellenállás értéke [ohm]
    double getR() const {
        return R;
    }

    /// Két ellenállás soros kapcsolása.
    /// @param r - ellenállás
    /// @return  - eredő ellenállású Resistor
    Resistor operator+(const Resistor& r) const;

    /// Két ellenállás párhuzamos kapcsolása.
    /// @param r - ellenállás
    /// @return  - eredő ellenállású Resistor
    Resistor operator%(const Resistor& r) const;


/// -------- Itt következnek az elkészítendő tagfüggvények --------

#if ELKESZULT >= 2
    /// Másoló konstruktor.
    /// @param rhs - objektum amiről a másolatot kell létrehozni
    Resistor(const Resistor& rhs);
#endif  // ELKESZULT == 2

#if ELKESZULT >= 3
    /// Destruktor
    ~Resistor();
#endif  // ELKESZULT == 3

#if ELKESZULT >= 4
    /// Értékadás
    /// @param rhs - jobb oldali operandus (a bal a *this)
    /// @return - referencia saját magára, hogy fűzhető legyen
    Resistor& operator=(const Resistor& rhs);
#endif  // ELKESZULT == 4

#if ELKESZULT >= 5
    /// Ellenálláson folyó áram
    /// @param u - áram
    /// @return  - áram
    double getI(double u) const;
#endif  // ELKESZULT >= 5

#if ELKESZULT >= 6
    /// Ellenálláson eső feszültség
    /// @param i - áram
    /// @return  - feszültség
    double getU(double i) const;
#endif  // ELKESZULT >= 6

#if ELKESZULT >= 7
    /// Két ellenállás összehasonlítása.
    /// @param r - ellenállás
    /// @return  - true, ha azonos
    bool operator==(const Resistor& r) const;
#endif  // ELKESZULT == 6

};

/// --- Globális függvények, operátorok ------

/// Többszörös: n darab egyforma r ellenállás összege (soros kapcsolása).
/// @param n   - darabszám
/// @param rhs - ellenállás (jobb oldali operandus)
/// @return    - eredő ellenállású Resistor
Resistor operator*(int n, const Resistor& rhs);

/// Inserter.
/// Ellenállás adatainak kiírása std::ostream-re
/// @param os  - ouput stream
/// @param rhs - a kíírandó Resistor (jobb oldali operandus)
/// @return  - output stream
std::ostream& operator<<(std::ostream& os, const Resistor& rhs);

#endif



