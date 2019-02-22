/**
 * \file komplex.h
 * (UTF-8 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 *
 * Az előadáson látott Komplex osztályhoz hasonló osztály és a
 * hozzá kapcsolódó globális függvények deklarációja.
 */
#ifndef KOMPLEX_H
#define KOMPLEX_H

/**
 * Az Ön feladata a komplex.cpp fájlban megvalósítani (definiálni) a hiányzó függvényeket.
 * Ahogyan halad a megvalósítással egyre több tesztesetet kell lefuttatni,
 * ezért az ELKESZULT makró értéket a készültségi foknak megfelelően állítsa be az
 * elkeszult.h fájlban!
 * Ne hagyjon ki feladatot, sorban haladjon!
 *
 * Ebben a fájlban nem kell módosítania semmit.
 */

#include "elkeszult.h"

/// Komplex osztály deklarációja
/// Lesz olyan feladat, amelynél ezt is bővítenie kell!
class Komplex {
    double re, im;
public:
    /// 0, 1 és 2 paraméteres konstruktor
    /// @param re - valós rész
    /// @param im - képzetes rész
    Komplex(double re = 0, double im = 0);

    /// Valós rész lekérdezése
    /// @return - valós rész
    double getRe() { return re; }   /// tipikusan konstans tagfüggvény itt csak demó

///---- Egy példa a konstans tagfüggvényre, logikusan nem itt a helye -----///
    /// Abszolút érték lekérdezése
    /// @return - abszolút érték
    double abs() const;

#if ELKESZULT >= 1
    // konstansra is alkalmazható lekérdező függvények
    /// Valós rész lekérdezése
    /// @return - valós rész
    double getRe() const;

    /// Képzetes rész lekérdezése
    /// @return - képzetes rész
    double getIm() const;
#endif

#if ELKESZULT >= 2
    // beállító függvények
    /// Valós részt beállító függvény
    /// @param r - valós rész
    void setRe(double re);

    /// Képzetes részt beállító függvény
    /// @param im - képzetes rész
    void setIm(double im);
#endif

#if ELKESZULT >= 3
    // összehasonlítás
    /// Egyenlőség vizsgálat
    /// @param rhs_k - jobb oldali operandus (Komplex)
    /// @return true - ha a képzetes és a valós rész is azonos, egyébként false
    bool operator==(const Komplex& rhs_k) const;

    /// Egyenlőtlenség vizsgálat
    /// @param rhs_k - jobb oldali operandus (Komplex)
    /// @return hamis - ha a képzetes és a valós rész is azonos, egyébként false
    bool operator!=(const Komplex& rhs_k) const;
#endif

#if ELKESZULT >= 4
    // összeadás, a + nem módosítja önmagát ezért konstans fv.
    /// Komplex + Komplex
    /// @param rhs_k - jobb oldali operandus (Komplex)
    /// @return egy új komplex adat - a két komplex adat összege
    Komplex operator+(const Komplex& rhs_k) const;

    /// Komplex + double
    /// @param rhs_d - jobb oldali operandus (double)
    /// @return egy új komplex adat - a két adat összege
    Komplex operator+(double rhs_d) const;
#endif

#if ELKESZULT >= 5
    /// double + Komplex csak globális függvénnyel valósítható meg,
    /// mivel a bal oldal nem osztály.
    /// Ld. az osztály deklarációja után!
#endif

#if ELKESZULT >= 6
    // a += művelet viszont módosítja önmagát!
    /// Komplex + Komplex
    /// @param rhs_k - jobb oldali operandus (Komplex)
    /// @return eredeti (bal oldali) objektum ref., amihez hozzáadtuk rhd_k-t
    Komplex& operator+=(const Komplex& rhs_k);

    /// Komplex + double
    /// @param rhs_d - jobb oldali operandus (double)
    /// @return eredeti (bal oldali) objektum ref., amihez hozzáadtuk rhd_d-t
    Komplex& operator+=(double rhs_d);
#endif

#if ELKESZULT >= 8
    /// komplex konjugált
    /// ~Komplex
    /// @return egy új adat, amiben a konjugált érték van
    Komplex operator~() const;
#endif

#if ELKESZULT >= 9
    // szorzás, a * nem módosítja önmagát ezért konstans fv.
    /// Komplex * Komplex
    /// @param rhs_k - jobb oldali operandus (Komplex)
    /// @return egy új komplex adat - a két komplex adat szorzata
    Komplex operator*(const Komplex& rhs_k) const;

    /// Komplex * double
    /// @param rhs_d - jobb oldali operandus (double)
    /// @return egy új komplex adat - a két adat szorzata
    Komplex operator*(double rhs_d) const;

    /// double * Komplex csak globális függvénnyel valósítható meg,
    /// mivel a bal oldal nem osztály
    /// Ld. az osztály deklarációja után!

    // a *= művelet viszont módosítja önmagát!
    /// Komplex * Komplex
    /// @param rhs_k - jobb oldali operandus (Komplex)
    /// @return eredeti (bal oldali) objektum ref., amit megszorosztunk
    Komplex& operator*=(const Komplex& rhs_k);

    /// Komplex + double
    /// @param rhs_d - jobb oldali operandus (double)
    /// @return eredeti (bal oldali) objektum ref., amit megszoroztunk
    Komplex& operator*=(double rhs_d);
#endif
};

///////////////////// Globális függvények /////////////////////////////////
/// Fontos!
/// Ezek nem az osztály tagfüggvényei, habár az osztály adatával dolgoznak
///

#if ELKESZULT >= 5
// double + Komplex csak globális függvénnyel valósítható meg,
// mivel a bal oldal nem osztály
/// double + Komplex
/// @param lhs_d - bal oldali operandus (double)
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return egy új komplex adat - a két adat összege
Komplex operator+(double lhs_d, const Komplex& rhs_k);
#endif

#if ELKESZULT >= 7
// cout << Komplex is csak globális függvénnyel valósítható meg, mivel
// az baloldali osztály (ostream) nincs a kezünkben, nem módosítható
/// Kiírás egy ostream-re
/// @param os - bal oldali operandus (ostream)
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return ostream&, hogy fűzhető legyen
std::ostream& operator<<(std::ostream& os, const Komplex& rhs_k);

/// Beolvasás egy istream-ről
/// @param is - bal oldali operandus (istream)
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return istream&, hogy fűzhető legyen
std::istream& operator>>(std::istream& is, Komplex& rhs_k);
#endif

#if ELKESZULT >= 9
// double * Komplex csak globális függvénnyel valósítható meg,
// mivel a bal oldal nem osztály
/// double * Komplex
/// @param lhs_d - bal oldali operandus (double)
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return egy új komplex adat - a két adat szorzata
Komplex operator*(double lhs_d, const Komplex& rhs_k);
#endif

#endif  // KOMPLEX_H
