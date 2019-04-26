#include <iostream>
#include <string>
#include <sstream>

#include "sablonok.hpp"
#include "fancy_iterators.hpp"
#include "gtest_lite.h"

/// Ellenőrizzük, hogy a sablonok.hpp-ben definiálta-e az ELKESZULT makrót
#ifndef ELKESZULT
#define ELKESZULT 0     /// ha mégse definiálta
#endif

#if ELKESZULT < 0       /// ha hibásan definiálta
#undef ELKESZULT
#define ELKESZULT 0
#endif
/// ------- Ellenőrző rész vége ----------


int itomb[] = { 1, 8, -3, 4, 5 };
double dtomb[] = { 1.2, -2.1, 3.91, -4.1, 5.1, -10 };

int main() {
    GTINIT(std::cin);       // Csak C(J)PORTA működéséhez kell

#if ELKESZULT == 1
    /// kiírás cout-ra, paraméter: [first, last)
    printEach(itomb, itomb+5);
    std::cout << std::endl;
    printEach(dtomb, dtomb+5);
#endif // TESZLEVEL == 1

#if ELKESZULT == 2
    /// paraméterként megadható a stream is
    printEach(itomb, itomb+5, std::cout);
    std::cout << std::endl;
    // default paraméterrel is kipróbáljuk
    printEach(dtomb, dtomb+5);
#endif // TESZLEVEL == 2

#if ELKESZULT >= 3
    /// paraméterként megadható a formátum is
    TEST(printEach, format) {
        std::stringstream out;
        printEach(itomb, itomb+4, out, "; ");
        EXPECT_EQ(std::string("1; 8; -3; 4\n"), out.str());
        out.str("");
        printEach(itomb, itomb+3, out, "// ");
        EXPECT_EQ(std::string("1// 8// -3\n"), out.str());
    END }
#endif // ELKESZULT >=3


#if ELKESZULT >= 4
    /// Annak vizsgálata, hogy a pre/post-inkremens operátorokon
    /// kívül használ-e más aritmetikai operátort a printEach.
    /// Ha használt, akkor nem fog lefordulni ez a rész.
    /// Javítsa a kódot.
    counting_iterator<int> i1(10), i2(15);      /// speciális iterátor ami sorozatot ad
    printEach(i1, i2);
#endif // ELKESZULT >= 4

#if ELKESZULT >= 5
    /// Számol ha sablon tesztjei
    TEST(szamol_ha_negativ, int) {
        EXPECT_EQ(1, szamol_ha_negativ(itomb, itomb+5));
    END }

    TEST(szamol_ha_negativ, double) {
        EXPECT_EQ(3, szamol_ha_negativ(dtomb, dtomb+6));
    END }
#endif // ELKESZULT >=5

#if ELKESZULT >= 6
    /// Nagyobb mint funktor tesztjei
    TEST(nyagobb_mint3, int) {
        nagyobb_mint<int> nm_3(3);  // konstruktor megjegyzi a 3-at
        EXPECT_TRUE(nm_3(4));       // meghívjuk a függvényhívás operátorát
    END }

    TEST(nyagobb_mint10, int) {
        nagyobb_mint<int> nm_10(10);  // konstruktor megjegyzi a 10-et
        EXPECT_FALSE(nm_10(4));       // meghívjuk a függvényhívás operátorát
    END }

    TEST(nyagobb_mint314, double) {
        nagyobb_mint<double> nm314(3.14);  // konstruktor megjegyzi a 3.14-et
        EXPECT_TRUE(nm314(4));       // meghívjuk a függvényhívás operátorát
    END }
#endif // ELKESZULT >=6


#if ELKESZULT >= 7
    /// szamol_ha funktorral
    TEST(szamol_ha, int) {
        EXPECT_EQ(3, szamol_ha(itomb, itomb+5, nagyobb_mint<int>(3)));
    END }

    TEST(szamol_ha, double) {
        EXPECT_EQ(2, szamol_ha(dtomb, dtomb+6, nagyobb_mint<double>(3.14)));
    END }
#endif // ELKESZULT >=7

 /// Itt a vége
    std::cout << "ELKESZULT = " << ELKESZULT << std::endl;
    if (ELKESZULT < 2 && !gtest_lite::test.fail())
      FAIL() << "\nMind a 7 feladatot oldja meg!" << std::endl;

    if (ELKESZULT >= 7 && !gtest_lite::test.fail())
      std::cout << "Szuper! Mind kesz" << std::endl;

    GTEND(std::cerr);       // Csak C(J)PORTA működéséhez kell
    return 0;
}
