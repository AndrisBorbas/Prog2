/**
 * \file swap.h
 *
 * Feladat:
 * Valósítsa meg a swap.h fájlban deklarált függvényeket a swap.cpp fájlban úgy,
 * hogy ez a program hiba nélkül leforduljon, és helyesen működjön!
 *
 * A program bemutatja a gtest_lite makróinak használatát.
 * A makrók működését nem kell megértenie, mivel számos még nem tanult megoldást
 * tartalmaznak.
 *
 */

#include <iostream>
#include "gtest_lite.h"
#include "swap.h"

int main() {

    GTINIT(std::cin);       // Csak C(J)PORTA működéséhez kell

    TEST(Swap, int) {       // Teszt eset kezdete. A paraméterekből csak kiírás lesz
        int a = 1, b = 100;
        int a0 = a, b0 = b;
        swap(a, b);
        EXPECT_EQ(b0, a);   // a két paraméter azonosságát várjuk
        EXPECT_EQ(a0, b);   // a két paraméter azonosságát várjuk
    } END

    TEST(Swap, char) {      // Teszt eset kezdete.
        char a = 'A', b = 'Z';
        char a0 = a, b0 = b;
        swap(a, b);
        EXPECT_EQ(b0, a);   // két paraméter azonosságát várjuk
        EXPECT_EQ(a0, b);
    } END

    TEST(Swap, bool) {      // Teszt eset kezdete.
        bool a = true, b = false;
        bool a0 = a, b0 = b;
        swap(a, b);
        EXPECT_EQ(b0, a);   // két paraméter azonosságát várjuk
        EXPECT_EQ(a0, b);
    } END

    TEST(Swap, double) {    // Teszt eset kezdete
        double a = 123.56, b = 8.954;
        double a0 = a, b0 = b;
        swap(a, b);
        EXPECT_EQ(b0, a);   // a swap nem számított eredmény, ezért lehet EQ
        EXPECT_EQ(a0, b);   // egyébként EXPECT_DOUBLE_EQ kellene
    } END

    TEST(Swap, char*) {     // Teszt eset kezdete
        const char *a = "Hello", *b = "C++";
        const char *a0 = a, *b0 = b;
        swap(a, b);
        EXPECT_EQ(b0, a); // két paraméter azonosságát várja
        EXPECT_EQ(a0, b);
    } END

    GTEND(std::cerr);   // Csak C(J)PORTA működéséhez kell

    return 0;
}
