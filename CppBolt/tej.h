#ifndef TEJ_H
#define TEJ_H

/**
 * \file tej.h
 *
 * Tej osztály deklarációja és inline függvényei
 */

#include "aru.h"

/// Tej osztály.
/// spec attribútuma a tej fajtája, és szírtartalma
class Tej :public Aru {
    double zsir;        ///< tej zsírtartalma %%)
    String spec;        ///< tej fajtája
  public:
    /// Konstruktor beállítja az attribútumokat (ősosztályét is)
    /// @param zsir - tej zsírtartalma
    /// @param ar - tej egységára
    /// @param spec - tej fajtája
    Tej(double zsir, double ar, const char *spec = "")
        :Aru("Tej", "liter", ar), zsir(zsir), spec(spec) {}

    /// Attribútumok kiírása egy stream-re
    /// @param os - output stream referencia
    /// @return output stream referencia
    std::ostream& print(std::ostream& os) const {
        return os << megnevezes << " "
                  << zsir << "% " << spec << "; "
                  << ar << "Ft/" << egyseg;
    }
};

#endif // TEJ_H

