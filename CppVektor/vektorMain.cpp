/**
 * \file vektorMain.cpp
 *
 * Tesztprogram a Vektor osztály teszteléséhez.
 * Értse meg a programot és készítse el a vektor.cpp-ben a hiányzó tagfüggvényeket!
 *
 * Megj: A nagy házi feladat teszteléséhez is hasonló tesztelési metódust ajánlunk, azaz
 * a standard inputról olvasott adat vezérelje, hogy melyik teszteset fusson le.
 * Természetesen a feladattól függhet, hogy ez a módszer használható vagy nem, mint ahogy az
 * is, hogy a gtest_lite makrói használhatóak-e.
 *
 *
 *** FONTOS ***
 * A MEMTRACE makró minden fordítási egységben definiált kell, hogy legyen!
 * Ezt legkényelmesebben projekt szintű beállítással tudja elérni.
 *   (Projekt->Build options->#defines)
 *
 */

#include <iostream>
#include <ctime>
#include <iomanip>
#include "vektor.h"
#include "gtest_lite.h" // tesztelést segítő makrók

using std::cout;
using std::endl;
using std::cin;

/// Segédfüggvény a beolvasások előtti üzenetek kiírásához
/// CPORTA-n nem kérünk ilyen kiírásokat
inline void prompt(const char *msg) {
#ifndef CPORTA
    cout << msg;
#endif // CPORTA
}

// konstruktorok, kezdőértékek és indexoperátor tesztje
void test_1() {
    // Konstruktorok tesztje
    TEST(Vektor, konst) {
        Vektor::setDefSize(10);
        Vektor::setDefValue(0);
        EXPECT_NO_THROW(Vektor v0);
        Vektor v0;
        EXPECT_EQ(10u, v0.size());   // méretre 10-et várunk
        cout << "v0 merete: "<< v0.size() << endl;
        Vektor v1(5, 8);
        EXPECT_EQ(5u, v1.size());   // méretre 5-öt várunk
        cout << "v1 merete: "<< v1.size() << endl;
    } END

    // kezdőértékkel való feltöltés és indexelés tesztje
    TEST(Vektor, index) {
        Vektor::setDefSize(10);
        Vektor::setDefValue(0);
        Vektor v0;
        for (size_t i = 0; i < v0.size(); ++i) {
          EXPECT_NO_THROW(v0[i]);   // nem várunk kivételt
          EXPECT_EQ(0, v0[i]) << "*** kezdoertek?";      // minden eleme 0
        }
        EXPECT_THROW(v0[10], const char *); // túl nagy
        EXPECT_THROW(v0[11], const char *); // ez is
        EXPECT_THROW(v0[-1], const char *); // túl kicsi
        Vektor v1(5, 8);
        for (size_t i = 0; i < v1.size(); ++i) {
          EXPECT_NO_THROW(v1[i]);   // nem várunk kivételt
          EXPECT_EQ(8, v1[i])  << "*** kezdoertek?";      // minden eleme 8
        }
        EXPECT_THROW(v1[8], const char *);  // túl nagy
        EXPECT_THROW(v1[9], const char *);  // ez is
        EXPECT_THROW(v1[-1], const char *); // túl kicsi
    } END

    // másoló konstruktor és indexelés tesztje
    TEST(Vektor, copy) {
      Vektor::setDefSize(10);
      Vektor::setDefValue(0);
      Vektor v0, v1(5, -1), v2(6, 1);
      EXPECT_NO_THROW(Vektor v3 = v2);
      Vektor v3 = v2;
      EXPECT_EQ(6u, v3.size());
      cout << "v3 merete: "<< v3.size() << endl;
      for (size_t i = 0; i < v3.size(); ++i) {
        EXPECT_NO_THROW(v3[i]); // nem várunk kivételt
        EXPECT_EQ(1, v3[i]) << "*** Az adat elromlott! copy ctor?";    // minden eleme 1
      }
      EXPECT_THROW(v3[6], const char *);  // túl nagy
      EXPECT_THROW(v3[7], const char *);  // ez is
      EXPECT_THROW(v3[-1], const char *); // túl kicsi
    } END

    // értékadás és indexelés tesztje
    TEST(Vektor, assign) {
      Vektor::setDefSize(20);
      Vektor::setDefValue(0);
      Vektor v0, v1(25, -1);
      EXPECT_NO_THROW(v1 = v0);
      EXPECT_EQ(20u, v1.size());
      cout << "v1 merete: "<< v1.size() << endl;
      for (size_t i = 0; i < v1.size(); ++i) {
        EXPECT_NO_THROW(v1[i]); // nem várunk kivételt
        EXPECT_EQ(0, v1[i]) << "*** Az adat elromlott a masolaskor";
      }
      EXPECT_THROW(v1[20], const char *);  // túl nagy
      EXPECT_THROW(v1[21], const char *);  // ez is
      EXPECT_THROW(v1[-3], const char *);  // túl kicsi
    } END

    // értékadás önmagának és indexelés tesztje
    TEST(Vektor, selfassign) {
      Vektor::setDefSize(5);
      Vektor::setDefValue(5.5);
      Vektor v0, v1(25, -1);
      EXPECT_NO_THROW(v0 = v0);
      EXPECT_EQ(5u, v0.size());
      cout << "v0 merete: "<< v0.size() << endl;
      for (size_t i = 0; i < v0.size(); ++i) {
        EXPECT_NO_THROW(v0[i]); // nem várunk kivételt
        EXPECT_EQ(5.5, v0[i])  << "*** Az adat elromlott a masolaskor";
      }
      EXPECT_THROW(v0[6], const char *);  // túl nagy
      EXPECT_THROW(v0[7], const char *);   // ez is
      EXPECT_THROW(v0[-1], const char *);  // túl kicsi
    } END
}


// CPORTA ellenőrzi a kimenetet
void test_2() {
    Vektor::setDefSize(500);
    Vektor::setDefValue(-1);
    Vektor v;
    cout << "v merete: "<< v.size() << endl;
    cout << "v[0] = " << v[0] << endl;
    v[-1];  // szép kis kivételt generálunk, hogy megtudjuk a neptun kódját
}

//
void test_3() {
    Vektor::setDefSize(10);
    Vektor::setDefValue(0);
    Vektor v0, v1(5, -1), v2(6, 2);

    // konstans  tagfüggvények tesztje
    TEST(Vektor, const) {
      const Vektor v3 = v2;
      EXPECT_EQ(6u, v3.size());
      cout << "v3 merete: "<< v3.size() << endl;
      for (size_t i = 0; i < v3.size(); ++i) {
        EXPECT_NO_THROW(v3[i]); // nem várunk kivételt
        EXPECT_EQ(2, v3[i]);    // minden eleme 2
      }
      EXPECT_THROW(v3[6], const char *);  // túl nagy
      EXPECT_THROW(v3[7], const char *);  // ez is
      EXPECT_THROW(v3[-20], const char *); // túl kicsi

      // elengedünk egy kivételt a konstansra is a neptun miatt
      v3[-99];
    } END
}

void test_4() {
    // Beolvassa n-et (egész)
    prompt("vektor merete: ");
    size_t n; cin >> n;
    Vektor::setDefSize(n);   // ez lesz a default méret

    // Beolvassa a default kezdõértéket és beállítja
    prompt("  kezdoerteke: ");
    double val; cin >> val;
    Vektor::setDefValue(val);

    // Beolvas még egy egész értéket (ezzel kicsit módosít majd)
    prompt("  szorzo1: ");
    int mul1 = 0; cin >> mul1;

    prompt("  szorzo2: ");
    int mul2 = 0; cin >> mul2;

    // Létrehozunk egy 5xn-es mátrixot default értékekkel;
    const int m = 5;
    Vektor vt[m];

    // szorzás tesztje
    TEST(Vektor, Mul) {
        cout << std::fixed;
        // minden elemet megszorzunk (mul1+i+j)-vel változtatunk
        for (int i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++)
                vt[i][j] *= mul1 + i + j;

            cout << "vt[" << i << "](" << vt[i].size() << "): ";
            const Vektor v0 = vt[i];

            vt[i] = mul2 * v0;  // Most pedig megszorozzuk mul2-vel
            for (size_t j = 0; j < n; j++) {
                EXPECT_DOUBLE_EQ(val*(mul1+i+j)*mul2, vt[i][j]);
                cout << std::setw(8) << std::setprecision(0) << vt[i][j];
            }
            cout << endl;
        }
    } END
}

int main() {
	// alapételmezett értékek tesztelése
    try
    {
        Vektor v0;
        cout << "alapertelmezett ertekek: " << v0.size() << " " << v0[1] << endl;
    }
    catch (...)
    {
        cout << "alapertelmezett ertekkel valo letrehozas soran kivetel keletkezett." << endl;
		return 1;
    }

    int testNr;
    const char *prompt_txt = "Teszteset (1-4) (0: vege): ";
    prompt(prompt_txt);
    while (cin >> testNr && testNr != 0) {  // * 0-ig, vagy amíg tud számot olvasni
        try {
            switch (testNr) {
                case 1: test_1(); break;
                case 2: test_2(); break;
                case 3: test_3(); break;
                case 4: test_4(); break;
            }
            cout << endl;
          } catch (const char *p) {
            cout << p << endl << endl;
        } catch (...) {
            cout << "Baj van!" << endl;
        }
        prompt(prompt_txt);
    }
    return 0;
}
