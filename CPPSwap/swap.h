#ifndef _SWAP_H
#define _SWAP_H
/**
 * Feladat:
 * Valósítsa meg az alább deklarált függvényeket a swap.cpp fájlban úgy,
 * hogy a swap_teszt.cpp program hiba nélkül leforduljon, és helyesen mûködjön!
 *
 */

/**
 * A swap megvalósításához aligha kell dinamikus memóriakezelés.
 * Ezért ellenőrizni sem lenne szükséges.
 */
#include "memtrace.h"

/**
 * swap
 * Két bool adat felcserélése
 * @param a - egyik adat
 * @param b - másik adat
 */
void swap(bool& a, bool& b);

/**
 * swap
 * Két int adat felcserélése
 * @param a - egyik adat
 * @param b - másik adat
 */
void swap(int& a, int& b);

/**
 * swap
 * Két char adat felcserélése
 * @param a - egyik adat
 * @param b - másik adat
 */
void swap(char& a, char& b);

/**
 * swap
 * Két double adat felcserélése
 * @param a - egyik adat
 * @param b - másik adat
 */
void swap(double& a, double& b);

/**
 * swap
 * Két const char* adat (pointer) felcserélése
 * @param a - egyik pointer
 * @param b - másik pointer
 */
void swap(const char*& a, const char*& b);  /// Figyelje meg a ref. típus jelölését!

#endif  // _SWAP_H
