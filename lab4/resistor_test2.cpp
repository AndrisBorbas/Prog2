/**
 * \file resistor_test2.cpp
 *
 * Ohmikus ellenállást megvalósító osztály tesztesetei gtest_lite eszközkészletével
 * megvalósítva a 4. laborfeladathoz.
 * A feladat elsősorban az implicit tagfüggvények létrejöttét, használatát mutatja be.
 *
 * A laborfeladat megoldásához ebben az állományban nem kell módosítani.
 *
 * Az elkeszult.h-ban definiált ELKESZULT makró vezérli az egyes tesztesetek
 * fordítását. A legutolsó teszteset az ELKESZULT értékét vizsgálja.
 *
 */
#include <iostream>
#include <sstream>
#include "gtest_lite.h"
#include "resistor.h"


int main() {
  GTINIT(std::cin);       // Csak C(J)PORTA működéséhez kell

  Resistor r;

  TEST(Resistor, HazibanAdottR) {
    double d = r.getR();
    EXPECT_EQ(93., d) << "Jporta feladatban megadott default ertekkel hasonlitson!" << std::endl;
  } END

  Resistor r1(1000), r2(3000);

  TEST(Resistor, EgyPareteresKonsruktor) {
    double d = r1.getR();	  	            // 1000
    EXPECT_DOUBLE_EQ(1000., d);
  } END

  TEST(Resistor, Masolo) {
    Resistor r11 = r1;
    double d = r11.getR();                 // 1000
    EXPECT_DOUBLE_EQ(1000., d);
  } END

  TEST(Resistor, Osszeg) {
    double d = (r1 + r2).getR();           // 4000
    EXPECT_DOUBLE_EQ(4000., d);
  } END

  TEST(Resistor, SetDef) {
    Resistor::setDef(20);
    Resistor rt[5];
    double d = rt[3].getR();                // 20
    EXPECT_DOUBLE_EQ(20., d);
  } END

  TEST(Resistor, Ertekadas) {
    r1 = r2;
    double d = r1.getR();	  	            // 3000
    EXPECT_DOUBLE_EQ(3000., d);
  } END


#if ELKESZULT >= 5
  TEST(ResistorTest, getI) {				// getI
    const Resistor r0(2);
    EXPECT_DOUBLE_EQ(6.06, r0.getI(12.12));
  } END
#endif

#if ELKESZULT >= 6
  TEST(ResistorTest, getU) {				// getU
    const Resistor r0(12.12);
    EXPECT_DOUBLE_EQ(24.24, r0.getU(2));
  } END
#endif

#if ELKESZULT >= 7
  TEST(ResistorTest, EQ) {				    // operator==
    const Resistor r0(12345.6789);
    const Resistor r1(123456789);           // r1 ez pont a 10-szerese r0-nak
    EXPECT_TRUE(r0 == r0);                  // önmagával
    EXPECT_FALSE(r0 == r1);

	Resistor r2 = 10000 * r0;               // számítás nem lesz pontos
    EXPECT_TRUE(r2 == r1);

    r2 = r2 + Resistor(1e-5);               // de ha tényleg eltér?
    EXPECT_FALSE(r2 == r1);

    const Resistor r3(1e-18);               // kis értéknél hogy viselkedik?
    r2 = r3 + Resistor(1e-18);
    EXPECT_FALSE(r3 == r1);
  } END
#endif

#if ELKESZULT >= 8
  TEST(ResistorTest, Inserter) {
    std::ostringstream oss;     // stringstream-be írunk, és szövegesen hasonlítunk !
    oss << Resistor(8.45) << '\t' << Resistor(100);
    EXPECT_STREQ("8.45\t100", oss.str().c_str());
} END
#endif // ELKESZULT >= 8

/// Itt a vége
  if (ELKESZULT < 6)
    FAIL() << "\nLegalabb az elso ot feladatot oldja meg!" << std::endl;

  if (ELKESZULT == 8 && !gtest_lite::test.fail())
    std::cout << "Szuper! Mind kesz" << std::endl;
  else
    std::cout << "EKESZULT = " << ELKESZULT << std::endl;

  GTEND(std::cerr);       // Csak C(J)PORTA működéséhez kell
  return 0;
}
