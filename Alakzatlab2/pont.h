/**
 *  \file pont.h
 *  Pont osztály deklarációja
 */
#ifndef PONT_H
#define PONT_H
#include <iostream>         // ostream miatt kell

/// Pont osztály
/// Az egyszerűség kedvéért minden tagja publikus.
/// Így nem kell getter, meg setter.
/// Csak azok az operatorok lettek megvalósítva, melyeket használ a demó
struct Pont {
    int x;      ///< x koordináta
    int y;      ///< y koordináta
    Pont(int x = 0, int y = 0) :x(x), y(y) {}

    /// += operator
    /// @param rhs_p - jobb oldali operandus (Pont)
    /// @return saját maga megnövelve
    Pont& operator+=(const Pont& rhs_p);

    /// + operator
    /// @param rhs_p - jobb oldali operandus (Pont)
    /// @return új objektum (Pont) a két pont összege
    Pont operator+(const Pont& rhs_p) const;
    /// @return megvá pont

    /// - operator
    /// @param rhs_p - jobb oldali operandus (Pont)
    /// @return új új objektum (Pont) a két pont különbsége
    Pont operator-(const Pont& rhs_p) const;
};

/// Globális <<< operátor
/// @param os - ostream
/// @param p - pont
std::ostream& operator<<(std::ostream& os, const Pont& p);

#endif // PONT_H
