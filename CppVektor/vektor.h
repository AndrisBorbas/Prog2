#ifndef VEKTOR_H
#define VEKTOR_H
/**
 * \file vektor.h
 *
 * CppVektor Jporta feladat Vektor osztály deklarációja
 *
 * Az Ön feladata a hiányzó függvények megvalósítása a veltor.cpp fájlban.
 *
 * Ebben a fájlban nem kell módosítania semmit, ugyanakkor célszerű a megvalósítandó tagfüggvények
 * deklarációi kommentekkel együtt átmásolni a vektor.ccp-be, és azokat átalakítani definíciókká.
 * Másolásnál ügyeljen arra, hogy a kontextus (scope) megváltozik.
 */

#include "memtrace.h"
/**
 * Dinamikus valós vektor.
 * A konstruktor a statikus tagokból inicializál
 */
class Vektor {
    double *pVec;               // vektor elemeit tartalmazó din. memóriaterület címe
    size_t nElements;           // vektor elmeinek száma
    static size_t defSize;      // vektor alapértelmezett mérete
    static double defValue;     // vektor elemeinek alapértelmezett kezdőértéke
public:
    /// Konstruktor.
    /// Statikus adattagokból inicializál
    /// @param size  - vektor mérete
    /// @param value - kezdőérték, amivel feltölti a vektort
    Vektor(size_t size = defSize, double value = defValue) :nElements(size) {
        pVec = new double[nElements];
        for (size_t i = 0; i < nElements; i++)
            pVec[i] = value;
    }

    /// Másoló konstruktor. Készítse el a vektor.cpp fájlban!
    Vektor(const Vektor&);

    /// Destruktor. Készítse el a vektor.cpp fájlban!
    ~Vektor();

    /// Méret lekérdezése.
    size_t size() const { return nElements; }

    /// Alapértelmezett méret beállítása
    /// @param size  - vektor def. mérete
    static void setDefSize(size_t size) { defSize = size; }

    /// Alapértelmezett érték beállítása
    /// @param value - def. kezdőérték, amivel feltölti a vektort
    static void setDefValue(double value) { defValue = value; }

    /// Értékadó operátor. Készítse el a vektor.cpp fájlban!
    Vektor& operator=(const Vektor&);

    /// Indexoperátorok. Készítse el a vektor.cpp fájlban!
    /// Túlcímzés esetén az Ön Neptun-kódját tartalmazó const char* típusú kivételt dob!
    /// @param idx - index értéke
    /// @return    - referencia az adott elemre
    double& operator[](size_t idx);
    const double& operator[](size_t idx) const;
};

/// Szorzás: Valós * Vektor. Készítse el a vektor.cpp fájlban!
/// @param val - valós érték (bal oldali operandus)
/// @param vec - vektor, aminek minden elemét megszorozzuk (jobb oldali operandus)
Vektor operator*(double val, const Vektor& vec);

#endif

