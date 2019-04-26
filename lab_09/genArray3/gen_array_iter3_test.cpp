/**
 * Egyszerű program az iterátoros generikus tömb kipróbálásához.
 */

#include <iostream>
#include <stdexcept>
#include <sstream>

#include "integer.h"
#include "sablonok.hpp"
#include "gen_array_iter3.hpp"
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

using std::cout;
using std::endl;

/// Összegző funktor (6. részfeladathoz)
/// ELKESZULT == 16-hoz
struct Sum {
    int sum;
    Sum(int s=0) :sum(s) {}
    void operator()(int i) { sum += i;}
};

/// Egyszerű C tömbök, amiből majd az adatokat vesszük
int itomb[] = { -5, 11, 13, -2, -1, 0, 1, -82, 3, 4 };
double dtomb[] = { .0,  .1,  .2,  .3,  4.4, -12.4, 8.7  };
const char* txtomb[] = { "C#" , "C", "C++", "Java", "C++11" };

int main() {
    printEach(itomb, itomb+4, std::cout);

    try {
		/// az int tömbből létrehozuk az intarr0-át
		Array<int> intarr0(itomb, itomb+10);
		/// a double tömbből létrehozzuk a dblarr0-át
		Array<double, 20> dblarr0(dtomb, dtomb+7);
        /// const char* tömbből pedig létrehozzuk a txarray-t
        Array<const char*> txarray(txtomb, txtomb+5);

#if ELKESZULT <= 11  // csak az elején, hogy máskor ne zavarjon a kivétel
		/// szándékosan rosszul indexelünk
        cout << intarr0.at(112);
#endif // ELKESZULT <= 11

#if ELKESZULT >= 12
        /// Kiírjuk a tömböket.
        PrintArray("intarr0", intarr0);
        PrintArray("dblarr0", dblarr0);
        PrintArray("txarray", txarray);

        /// Adatokat is kiírja?
        TEST(PrintArray, adat) {
            char cpp[] = "C++";
            Array<char, 10> carr(cpp, cpp+3);               /// létrehozzuk

            std::stringstream out;                          /// ide ír, az out adatfolyamba
            PrintArray("cpp", carr, out);
            // out-nak a sztring "arcát" összehasonlítjuk az elvárt sztringgel
            EXPECT_EQ(std::string("cpp size=3 capacity=10\n\t data=C,+,+\n"), out.str()) << "== Nem jo a kiiras formatuma!\n";
        END }
#endif // ELKESZULT >= 12

#if ELKESZULT >= 13
		/// Ellenőrizzük az Array post-inkremens iterátorát:
        Array<int>::iterator i1, i2;
        i1 = i2 = intarr0.begin();
        if (i1 != i2++) { cout << "** HIBAS az iterator post-inkremens operatora **\n"; }
#endif // ELKESZULT >= 13

#if ELKESZULT >=14
        /// intarr0-ból létrehozzuk az intarr1-et
		Array<int, 100> intarr1(intarr0.begin(), intarr0.end());
        /// Kiírjuk az elemeket.
        PrintArray("\nintarr1", intarr1);
#endif // ELKESZULT >= 14

#if ELKESZULT >= 15
        // Számlálja össze az intarr1-ben az 5-nél nagyobb elemeket!
        // Használja a korábban elkészített szamol_ha sablont!
		nagyobb_mint<int> mint5(5);
        int db = szamol_ha(intarr1.begin(), intarr1.end(), mint5);
        cout << "\nintarr1-ben 5-nel nagyobb: ";
        cout << db << " db" << endl;
#endif // ELKESZULT >= 15

#if ELKESZULT >= 16
        Sum s = forEach(intarr1.begin(), intarr1.end(), Sum());
        cout << "\nintarr0 osszegzes forEach segitsegevel: " << s.sum << endl;
#endif // ELKESZULT >= 16

#if ELKESZULT >= 17
        cout << "intarr0 kiiras forEach segtisegevel: ";
        ostreamFunctor<int> out(cout, ",");
        forEach(intarr1.begin(), intarr1.end(), out);
        cout << endl;
#endif // ELKESZULT >= 17

#if ELKESZULT >= 18
        /// Itt valamilyen memóriaszemét lesz
		cout << "\nMemoriaszemet: " << intarr1.at(12) << endl;

		/// Itt meg nincs memóriaszemét. Miért?
        Array<Integer,100> Ia;
        cout << "Ez meg nulla: "<< Ia.at(12) << endl;
#endif // ELKESZULT >= 18

    } catch (std::exception& e) { // az out_of_range, és a runtime_error is az exception
                                  // osztályból származik. Így azok kompatibilisek
								  // az alaposztállyal
        cout << e.what() << endl;
    }
}

