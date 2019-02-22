#ifndef _RESISTOR_H
#define _RESISTOR_H

/**
 * \file resistor.h
 *   (UTF-8 kodolasu fajl. Allitsa at a megjenetes kodolasat,
 *    ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * Ohmikus ellenállás
 */

#define NO_STATIC

class Resistor {
    double R;              	// az ellenállás értéke ohmban
#ifndef NO_STATIC
    static double defR;  	// ellenállások alapértelmezett értéke ohmban
                            // ezt a statikus adattagot külön meg kell valósítani
                            // az osztályon kívül.
#endif
public:

    /// Konstruktor.
    /// R alapértelmezett értéket (defR-t) kap
    Resistor();

    /// Konstruktor.
    /// @param r - ellenállás értéke [ohm]
    Resistor(double r);

#ifndef NO_STATIC
    /// Alapértelmezett ellenállásérték beállítása
    /// @param r - ellenállás értéke [ohm]
    static void setDef(double r);
#endif

    /// Ellenállás értékének lekérdezése.
    /// @return - ellenállás értéke [ohm]
    double getR() const {
        return R;
    }

    /// Két ellenállás soros kapcsolása.
    /// @param r - ellenállás
    /// @return  - eredőként létrejövő ellenállás
    Resistor operator+(const Resistor& r) const;

    /// Két ellenállás párhuzamos kapcsolása.
    /// @param r - ellenállás
    /// @return  - eredőként létrejövő ellenállás
    Resistor operator%(const Resistor& r) const;

};

/// Többszörös: n darab egyforma r ellenállás összege (soros kapcsolása).
/// @param n - darabszám, ha n <= 0, akkor kivételt dob
/// @param r - ellenállás
/// @return  - eredőként létrejövő ellenállás
Resistor operator*(int n, const Resistor& r);

#endif  // _RESISTOR_H

