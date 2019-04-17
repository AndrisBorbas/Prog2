/*
 * \file halmaz_teszt.cpp
 *
 */

#ifndef CPORTA
#define ELKESZULT 4
#endif

/**
 * ELKESZULT == 0 estén az Ön által készített Set sablon létezését teszteli.
 * ELKESZULT == 1 esetén a Set működését teszteli néhány alaptípussal.
 * ELKESZULT >= 2 esetén a Set sablont a Point osztállyal teszteli.
 * TESZLEVEL >= 3 esetén az Ön által készített equal sablont teszteli
 * TEZSLEVEL == 4 esetén az Ön által készített equal specializációját teszteli
   (Point Y koordinátája nem vesz részt a hasonlításban)
 * TEZSLEVEL == 5 esetén az Ön által módosított Set sablont teszteli, ami sablon paraméterként
   kapja az összehasonlító függvényt, melynek alapértelmezett értéke az equal sablon
   Feltételezi, hogy van a ponthoz Xequal függvény, vagy funktor.
*/


#include <iostream>
#include <stdexcept>

#include "gtest_lite.h"
#include "integer.h"
#include "point.h"
#include "myset.hpp"

#ifndef ELKESZULT
#define ELKESZULT 2      // ha nem definiálta a myset.hpp-ben JPORTA-ra történő feltöltéskor akkor legyen 2
#endif

/// Tagfüggvények létezését tesztelő sablonok generálása nem fontos megértenie
CREATE_Has_(size)
CREATE_Has_(insert)
CREATE_Has_(isElement)

int main() {
 GTINIT(std::cin);       // Csak C(J)PORTA működéséhez kell

#if ELKESZULT == 0
    /// Csak azt vizsgálja, hogy a sablon példányosítható-e, keletkeznek-e az előírt tagfüggvények,
    /// és a keletkezett kód lefordul-e.

    //példányosítjuk int-re
    Set<int> int_set;

    TEST(int, sanity) {
    if (!_Has_size<Set<int> >::member)
        FAIL() << "== Nincs size tagfuggveny! ==\n";
    if (!_Has_insert<Set<int> >::member)
        FAIL() << "== Nincs insert tagfuggveny! ==\n";
    if (!_Has_isElement<Set<int> >::member)
        FAIL() << "== Nincs isElement tagfuggveny! ==\n";
    } ENDM

    //példányosítjuk char-ra
    Set<char> char_set;

    TEST(char, sanity) {
    if (!_Has_size<Set<char> >::member)
        FAIL() << "== Nincs size tagfuggveny! ==\n";
    if (!_Has_insert<Set<char> >::member)
        FAIL() << "== Nincs insert tagfuggveny! ==\n";
    if (!_Has_isElement<Set<char> >::member)
        FAIL() << "== Nincs isElement tagfuggveny! ==\n";
    } ENDM

#endif  // ELKESZULT == 0

#if ELKESZULT >= 1
    /// insert és isElement tesztelése int-re
    TEST(int, insert) {
        Set<int> s0;
        s0.insert(1);
        s0.insert(2);
        EXPECT_TRUE(s0.isElement(1)) << "== Betettuk, de nincs benne! ==\n";
        EXPECT_TRUE(s0.isElement(2)) << "== Betettuk, de nincs benne! ==\n";
        EXPECT_FALSE(s0.isElement(0)) << "== Nem tettuk be, de benne van! ==\n";
        EXPECT_EQ((size_t)2, s0.size()) << "== Nem jo meretet! ***\n";
        s0.insert(1);
        EXPECT_EQ((size_t)2, s0.size()) << "== Azonos elem utan nem jo a meretet! ==\n";
    } ENDM

    /// kivétel dobás tesztelése int-re
    TEST(int, exception) {
        Set<int, 1> s0;
        EXPECT_NO_THROW(s0.insert(1));
        EXPECT_THROW(s0.insert(2), const char*);
    } ENDM

    /// insert és isElement tesztelése char-ra
    TEST(char, insert) {
        Set<char> s0;
        s0.insert('a');
        EXPECT_TRUE(s0.isElement('a'));
        EXPECT_FALSE(s0.isElement('b'));
    } ENDM

    /// insert és isElement tesztelése Integer-re
    TEST(Integer, insert) {
        Set<Integer> s0;
        s0.insert(Integer(1));
        EXPECT_TRUE(s0.isElement(Integer(1)));
        EXPECT_FALSE(s0.isElement(Integer(120)));
    } ENDM
#endif // ELKESZULT >= 1

#if (ELKESZULT >= 2 && ELKESZULT < 4) || ELKESZULT == 5
    /// insert és isElement tesztelése Point-ra, amikor mindkét koordináta számít az összehasonlításban
    TEST(Point, insert) {
        Set<Point> s0;
        s0.insert(Point(1, 2));
        EXPECT_TRUE(s0.isElement(Point(1, 2)));
        EXPECT_FALSE(s0.isElement(Point(1)));
        EXPECT_FALSE(s0.isElement(Point(100)));
    } ENDM
#endif // (ELKESZULT >= 2 && ELKESZULT < 4) || ELKESZULT == 5

#if ELKESZULT >= 3
    /// equal függvény tesztelése int-re
    TEST(int, equal) {
        int a = 1, b = 1;
        EXPECT_TRUE(equal(a, b));
        EXPECT_FALSE(equal(a, 2));
    } ENDM
#endif // ELKESZULT >=3


#if ELKESZULT == 3
    /// equal függvény tesztelése Point-ra, amikor mindkét koordináta számít az összehasonlításban
    TEST(Point, equal) {
        Point a, b, c(0,1), d(1,1), e(1,0);
        EXPECT_TRUE(equal(a, b));
        EXPECT_FALSE(equal(a, c));
        EXPECT_FALSE(equal(a, d));
        EXPECT_FALSE(equal(a, e));
    } ENDM

#endif // ELKESZULT == 3

#if ELKESZULT == 4
    /// equal függvény tesztelése Point-ra, amikor csak az x koordináta számít az összehasonlításban
    TEST(Point, Xequal) {
        Point a, b, c(0,1), d(1,1), e(1,0);
        EXPECT_TRUE(equal(a, b));
        EXPECT_TRUE(equal(a, c));
        EXPECT_FALSE(equal(a, d));
        EXPECT_FALSE(equal(a, e));
    } ENDM

    /// insert és isElement tesztelése Point-ra, amikor csak az x koordináta számít az összehasonlításban
    TEST(Point, insert) {
        Set<Point> s0;
        s0.insert(Point(1, 2));
        EXPECT_TRUE(s0.isElement(Point(1, 8)));
        EXPECT_FALSE(s0.isElement(Point(100)));
    } ENDM
#endif // ELKESZULT == 4

#if ELKESZULT == 5
    /// Xequal függvény tesztelése
    TEST(Point, Xequal2) {
        Point a, b, c(0,1), d(1,1), e(1,0);
        EXPECT_TRUE(Xequal(a, b));
        EXPECT_TRUE(Xequal(a, c));
        EXPECT_FALSE(Xequal(a, d));
        EXPECT_FALSE(Xequal(a, e));
    } ENDM

    TEST(Point, insert) {
        /// insert és isElement tesztelése Point-ra az Xequal függvénnyel, mint sablonparaméterrel
        Set<Point, 20, Xequal> s0;
        s0.insert(Point(1));
        EXPECT_TRUE(s0.isElement(Point(1, 8)));
        EXPECT_FALSE(s0.isElement(Point(100)));
    } ENDM
#endif // ELKESZULT == 5

/// Itt a vége
    std::cout << "ELKESZULT = " << ELKESZULT << std::endl;
    if (ELKESZULT < 2 && !gtest_lite::test.fail())
      FAIL() << "\nLegalabb az elso ket feladatot oldja meg!" << std::endl;

    if (ELKESZULT >= 4 && !gtest_lite::test.fail())
      std::cout << "Szuper! Mind kesz" << std::endl;

    GTEND(std::cerr);       // Csak C(J)PORTA működéséhez kell
    return 0;
}
