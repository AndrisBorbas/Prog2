// Fájl: fuggvenyeim.cpp
// Ebben találhatók a függvények prototípusai,
// típusok, konstansok, egyéb deklarációk

#ifndef FUGGVENYEIM_H
#define FUGGVENYEIM_H
/*
 * csere
 * Két int adat felcserélése
 * @param a - egyik adat
 * @param b - másik adat
 */
void csere(int& a, int& b);


double polinom(const double& x, const double * egyutthatok, const int& fokszam);
/*
 * max
 * Két int adat közül a nagyobb
 * @param a - egyik adat
 * @param b - másik adat
 */
// Ez egy inline függvény, amit minden fordítási
// egységben definiálni kell.
inline int max(int a, int b) { return a > b ? a : b; }

#endif // FUGGVENYEIM_H
