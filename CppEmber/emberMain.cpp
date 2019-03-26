/*
 * \file emberMain.cpp
 *
 * Tesztprogram az Ember, Hallgato és a Kutato osztályok teszteléséhez.
 *
 * Értse meg a programot és készítse el az ember.h állományt!
 *
 * Megj: A nagy házi feladat teszteléséhez is hasonló tesztelési metódust ajánlunk.
 *
 *
 *** FONTOS ***
 * A MEMTRACE makrónak minden fordítási egységben definiált kell, hogy legyen!
 * Ezt legkényelmesebben projekt szintű beállítással tudja elérni.
 *   (Projekt->Build options->#defines)
 *
 */

#include <iostream>
#include <ctime>
#include "ember.h"
#include "hallgato.h"
#include "kutato.h"
#include "gtest_lite.h" // tesztelést segítő makrók
#include "memtrace.h"

using std::cout;
using std::endl;
using std::cin;



// Segédfüggvény a beolvasások előtti üzenetek kiírásához
// JPORTA-n nem kérünk ilyen kiírásokat
inline void prompt(const char *msg) {
#ifndef CPORTA
    cout << msg;
#endif // CPORTA
}

// Ember referenciát kap. kiír és ellenőriz
void kiirEll(Ember& e, int ma, const char* nev, const char *fogl, int szul) {
    EXPECT_STREQ(nev, e.getNev());
    cout << "Nevem: " << e.getNev() << endl;
    EXPECT_EQ(ma-szul, e.getKor(ma));
    cout << "Korom: " << e.getKor(ma) << endl;
    EXPECT_STREQ(fogl, e.foglalkozas()) << "!** virtualis a foglalkozas?" << endl;
    cout << "Foglalkozasom: " << e.foglalkozas() << endl;
    EXPECT_EQ(2020-szul, e.getKor(2020));
    cout << "2020-ban " << e.getKor(2020) << " eves leszek" << endl;
    cout << endl;
}

// Ember pointert kap. kiír és ellenőriz
void kiirEllp(Ember *p, int ma, const char* nev, const char *fogl, int szul) {
    EXPECT_STREQ(nev, p->getNev());
    cout << "Nevem: " << p->getNev() << endl;
    EXPECT_EQ(ma-szul, p->getKor(ma));
    cout << "Korom: " << p->getKor(ma) << endl;
    EXPECT_STREQ(fogl, p->foglalkozas());
    cout << "Foglalkozasom: " << p->foglalkozas() << endl;
    EXPECT_EQ(2020-szul, p->getKor(2020));
    cout << "2020-ban " << p->getKor(2020) << " eves leszek" << endl;
    cout << endl;
}

// Ember adattagjainak láthatósági tesztje
// Hallgató nevének (neptun) tesztje
void test_1(int ma) {
    TEST(test1, kiir) {  // lehetne finomabban a teszteket
      Hallgato en;
      cout << "Nevem: " << en.getNev() << endl;
      cout << "Korom: " << en.getKor(ma) << endl;
      EXPECT_STREQ("Hallgato", en.foglalkozas());
      cout << "Foglalkozasom: " << en.foglalkozas() << endl;
      cout << "2020-ban " << en.getKor(2020) << " eves leszek" << endl << endl;
    } ENDM
}

// Hallgató teszt ember referenciával
void test_2(int ma) {
    TEST(tesz2, kiir) {
      Hallgato butus("Buta Toni", "BT1234", 1975);
      kiirEll(butus, ma, "Buta Toni", "Hallgato", 1975); // kiírja és ellenőrzi az adatokat
    } ENDM
}

// másoló konstruktor és a kivételkezelés működésének ellenőrzése
void test_3(int ma) {
    TEST(test3, kiir) {
      Hallgato toni("Okos Toni", "TUDOR6", 1970);
      Hallgato valaki = toni;	// másoló konstruktor próba

      EXPECT_STREQ("TUDOR6", valaki.getNeptun()); // lemásolódott a neptun is? Ki másolta le?
      Ember *okos = &valaki;
      kiirEllp(okos, ma, "Okos Toni", "Hallgato", 1970); // kiírja és ellenőrzi az adatokat

      // Azt várjuk, hogy kivételt dobjon
      EXPECT_THROW(cout << okos->getKor(1900), const char*) << "!** virtualis a getkor?" << endl;
      cout << "1900-ban hany eves voltal?" << endl;
      cout << okos->getKor(1900) << endl;
    } ENDM // nem jut ide a kivétel miatt
}

// Komplex teszt
void test_4(int ma) {
    TEST(test4, kkir) {
      Hallgato en;        // Annak a NEPTUN-kódja és születési éve, aki az Ember osztályt készítette
      Hallgato toni("Okos Toni", "TUDOR6", 1970);
      Hallgato butus("Buta Toni", "BT1234", 1975);
      Hallgato valaki = butus;	// másoló konstruktor próba
      Kutato cppFather("Bjarne Stroustrup", 1950);

      toni = toni;        // értékadás önmagának
      en = valaki;        // értékadás

      EXPECT_STREQ("BT1234", en.getNeptun()); // lemásolódott a neptun is? Ki másolta le?
      kiirEll(en, ma, "Buta Toni", "Hallgato", 1975);

      kiirEll(cppFather, ma, "Bjarne Stroustrup", "Kutato", 1950); // értékparaméterként kapja

      Ember *gatto = new Hallgato("Hall Gatto", "GAT123", 1987);  // dinamikus példány

      kiirEll(*gatto, ma, "Hall Gatto", "Hallgato", 1987);

      kiirEll(toni, ma, "Okos Toni", "Hallgato", 1970);
      EXPECT_STREQ("TUDOR6", toni.getNeptun()); // neptun is jó?

      // dinamikus példány törlése alaposztály pointerére hivatkozva
      cout << "Megszuntetes is megy az alaposztaly felol?" << endl;
      cout << "Kiderul, ha kilep a programbol!" << endl << endl;
      delete gatto;
    } ENDM
}

int main() {
  Ember e;
  time_t act = time(NULL);
  struct tm *lt = localtime(&act);
  int ma = lt->tm_year+1900;
  int testNr;
  const char *prompt_txt = "Teszteset (1-4) (0: vege): ";
  prompt(prompt_txt);
  while (cin >> testNr && testNr != 0) {  // * 0-ig, vagy amíg tud számot olvasni
    try {
      switch (testNr) {
        case 1: test_1(ma); break;
        case 2: test_2(ma); break;
        case 3: test_3(ma); break;
        case 4: test_4(ma); break;
      }
    } catch (const char *p) {
      cout << p << endl << endl;
    } catch (...) {
      cout << "Baj van!" << endl;
    }
    cout << endl;
    prompt(prompt_txt);
  }
  return 0;
}
