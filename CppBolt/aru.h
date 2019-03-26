#ifndef ARU_H
#define ARU_H

/**
 * \file aru.h
 *
 * Aru osztály deklarációja és globális függvényei
 */

#include <iostream>
#include "string5.h"

/// Aru osztály.
///
class Aru {
  protected:
    String megnevezes;  ///< áru megnevezése
    String egyseg;      ///< áru mennyiségi egysége (db, liter, kg, ...)
    double ar;          ///< áru egységára
  public:

    /// Konstruktor beállítja az attribútumokat
    /// @param nev - áru megnevezése
    /// @param egység - áru mennyiségi egysége szövegesen (db, liter, kg, ...)
    /// @param ar - áru egységára
    Aru(const char *nev, const char *egyseg, double ar)
        :megnevezes(nev), egyseg(egyseg), ar(ar) {}

    /// Megnevezés lekérdezése
    /// @return - megnevezés
    String getNev() const { return megnevezes; }

    /// Mennyiségi egység lekérdezése
    /// @return - mennyiségi egység
    String getEgys() const { return egyseg; }

    /// Egységár lekérdezése
    /// @return - egységár
    double getAr() const { return ar; }

    /// Attribútumok kiírása egy stream-re
    /// @param os - output stream referencia
    /// @return output stream referencia
    virtual std::ostream& print(std::ostream& os) const {
        return os << megnevezes << ": " << ar << "/" << egyseg;
    }

    /// Virtuális destruktor
    virtual ~Aru() {}
};

/// Globális inserter
/// @param os - output stream referencia
/// @param s - Aru referencia
/// @return output stream referencia
inline std::ostream& operator<<(std::ostream& os, const Aru& a) {
    return a.print(os);
}

#endif // ARU_H
