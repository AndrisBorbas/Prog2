/**
 * \file nem_oo_teszt.cpp
 * (UTF-8 kodolasu fajl. Allitsa at a megjenetes kodolasat,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * A C++ nem OO bővítéseinek gyakorlásához.
 *
 * Ékezetes kiírásokat csak a szorgalmi feladat tartalmaz.
 * Ha másutt is szeretne, akkor használja nem_oo_teszt.cpp fájlt.
 *
 * FELADATOK:
 *  1. Valósítsa meg a nem_oo.h állományban deklarált függvényeket!
 *  2. Valósítson meg a max.hpp fájlban, a Sajat névtéren belül egy olyan sablont, ami
 *     alaptípusok esetén a paraméterként kapott érték közül a nagyobbat adja.
 *  3. Specializálja a sablont a nem_oo.h állományban deklarált Komplex típusra
 *     úgy hogy a nagyobb abszolút értékű Komplex számot adja vissza!
 *  4. Ellenőrizze a megvalósított függvények és sablonok működését az alábbi
 *     tesztprogrammal! Értse meg a tesztprogramot! Segít a hibakeresésben!
 *     Most nem használjuk a gtest_lite makrókat, csupán egy-két programozott
 *     ellenőrzést végzünk. A kiírások helyességét Önnek kell ellenőriznie!
 *     (Ugye mennyivel macerásabb, mint programozottan ellenőrizni?)
 *  5. Szorgalmi feladat, ld. a fájl végén
 *
 */
#include <iostream>
#include <cstring>
#include <locale>

// Segédmakró, hogy windows-e
#define WINX defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)

// Ha Windows, akkor a karakterkészlet állítás miatt (szorgalmi feladatban) kell a windows.h
#if WINX
#include <windows.h>
#endif // WINX

#include "nem_oo.h"
#include "max.hpp"

#define SORHOSSZ 1000

using std::cout;
using std::cin;
using std::endl;

void setDefLang();  // alapértelmezett nyelvi környezet beállítása
void ekezetes_io(); // szorgalmi feladathoz

/* Ezt a tesztprogramot futtatja a JPORTA úgy, hogy a CPORTA definiált
 * Fordítsa le úgy is a programot és futtassa. */
//#define CPORTA

/* A szorgalmi feladathoz definiálja a SZORGALMI makrót */
///#define SZORGALMI

int main() {
#ifndef CPORTA
    setDefLang();
#endif
#if !defined(CPORTA) && defined(SZORGALMI)
    ekezetes_io();  /// szorgalmi feladat függvénye, JPORTA-n nem futtatjuk
#endif

    try {           /// Minden egy nagy try-catch blokkban van a tesztelés miatt.
#ifndef CPORTA
        cout << "\nSajat atoi proba.\n\"100\" 10-es, 8-as, és 2-es szamrendszerben:" << endl;
#endif // CPORTA
        cout << sajat::atoi("100") << endl;     /// KIÍRÁS: 10-es számrendszerben: 100
        cout << sajat::atoi("100", 8) << endl;  /// KIÍRÁS: 8-asban: 64
        cout << sajat::atoi("100", 2) << endl;  /// KIÍRÁS: 2-esben: 4

       /// kipróbáljuk az strcat-ot:
#ifndef CPORTA
        cout << "\nSajat strcat proba:" << endl;
#endif // CPORTA
        char *str = sajat::strcat("Ez egy mondat.", " Ez kicsit hosszabb mondat.\n");
        cout << str;            /// KIÍRÁS: Ez egy mondat. Ez kicsit hosszabb mondat.
        delete[] str;           /// Nekünk kell felszabadítani!

       /// kipróbáljuk a max-ot
#ifndef CPORTA
        cout << "\nSajat max proba:" << endl;
#endif // CPORTA
        int i1 = 10;
        int i2 = 200;
#ifndef CPORTA
        cout << "max(" << i1 << ", " << i2 <<")= "; /// KIÍRÁS: max(10, 200)=
#endif // CPORTA
        cout << sajat::max(i1, i2) << endl;  /// KIÍRÁS: 200

        double d1 = 123.5;
        double d2 = -34.4;
#ifndef CPORTA
        cout << "max(" << d1 << ", " << d2 <<")= "; /// KIÍRÁS: max(123.5, -34.4)=
#endif // CPORTA
        cout << sajat::max(d1, d2) << endl; /// KIÍRÁS: 123.5
        sajat::Komplex k1 = { 1, -3};
        sajat::Komplex k2 = { -40, 100 };
#ifndef CPORTA
        cout << "max(" << k1 << ", " << k2 <<")= "; /// KIÍRÁS: max((1,-3j), (-40,100j))=
#endif // CPORTA
        cout <<  sajat::max(k1, k2) << endl;/// KIÍRÁS: (-40,100j)

        /// kipróbáljuk a unique-ot
        char test[] = "ssszia C+++++ + !";      /// sok ismétlődő kar.
#ifndef CPORTA
        cout << "\ntest tomb tartalma a uniq hivasa elott\n";
        memtrace::mem_dump(&test, sizeof(test));
#endif // CPORTA
        cout << test << endl;
        char *p = sajat::unique(test, test+strlen(test));
#ifndef CPORTA
        cout << "\nuniq hivasa utan p: " << (void*)p << endl;
        memtrace::mem_dump(&test, sizeof(test));    /// Segit megfigyelni a memóriatartalmat
#endif // CPORTA
        *p = 0;                      /// p az új sorozat végére mutat
        cout << test << endl;;      /// KIÍRÁS: szia C+ + !
#ifndef CPORTA
        if (strcmp(test, "szia C+ + !") != 0)
            cout << "*** Hibás a unique ****" << endl;
        if (p != test + 11)
            cout << "*** Hibas unique: nem jo a visszateresi ertek ***" << endl;
        char test2[19] = "sss\0zia C+++++ + !";      /// lezáró nullával együtt 19 byte hossz=18
        p = sajat::unique(test2, test2+18);
        *p = '#';
        if (memcmp(test2, "s\0zia C+ + !#", 13) != 0) {
            cout << "*** Hibas unique: \\0 végjelet keres, vagy nem jó visszatérési értéket ad. ***" << endl;
            memtrace::mem_dump(&test2, 19);
        }
#endif // CPORTA
#ifndef CPORTA
        cout << "Addig olvasunk, amig hibas szam nem jon:" << endl;
#endif // CPORTA
        int base = 9;				/// ebben a számrendszerben várjuk az első sort
#ifndef CPORTA
        cout << "Szamot varunk (base: " << base << "):";
#endif // CPORTA
        char buf1[SORHOSSZ];
        while (cin.getline(buf1, SORHOSSZ)) {       /// amíg van adat
            char buf2[SORHOSSZ];
            buf2[0] = 0;
#ifndef CPORTA
            cout << "Tetszoleges szoveget varunk: ";
#endif // CPORTA
            if (!cin.getline(buf2, SORHOSSZ))
                break;                              /// váratlanul fáj vége jött
            str = sajat::strcat(buf1, buf2);        /// két soronként összefűzzük az inputot
#ifndef CPORTA
            cout << "A ket sor osszefuzve: ";
#endif // CPORTA
            cout << str << endl;                    /// kiírjuk
#ifndef CPORTA
            cout << "Unique utan:";
#endif // CPORTA
            p = sajat::unique(str, str+strlen(str));
            *p = 0;
            cout << str << endl;
            delete[] str;                           /// nem kell tovább a string
#ifndef CPORTA
            cout << "A beolvasott szam atalakitva: ";
#endif // CPORTA
            int val = sajat::atoi(buf1, base); 	    /// átalakítás base rendszerből
            cout << val << endl; 			        /// kiírjuk
            base  = val % 9 + 2;			        /// ebben a számrendszerben várjuk legközelebb
#ifndef CPORTA
            cout << "Szamot varunk (base: " << base << "):";
#endif // CPORTA
        }
        cout << "Nem dobott kivetelt!" << endl;
    } catch (const char *p) {
        cout << "const char* kivetel jott: " << p << endl;
    } catch (...) {
        cout << "Baj van: Nem vart kivetel jott" << endl;
    }
    return 0;
}

/**
 * Ellenőrizzük, hogy valóban készített-e max sablont:
 *  Specializáljuk, ha tudjuk, akkor tényleg sablon.
 */
namespace sajat {
    template<>
    bool max(bool a, bool b) { return 0;} /// Nem használjuk, csak trükk:
    /// Ha itt fordítási hibát kap, akkor nem sablonnal oldotta meg a max függvényt!
}

/**
 * SZORGALMI FELADAT:
 *
 *  megoldásához definiája a SZORGALMI makrót.
 *
 *  Az ekezetes_io() függvény egy lehetőséget mutat az ékezetes karakterek C++ kódból való kiírására/kezelésére.
 *  Elemezze, értse meg a kódrészletet.
 *  A karakterkódolás gyötrelmeit jól összefoglalja Czirkos Zoltán anyaga:
 *     https://infoc.eet.bme.hu/karakterkodolas/
 *
 *  Egy magyar nyelvűre állított Windows általában Windows-1250 karakterkódolást használ,
 *  ami lényegében megfelel a Latin-2 kódolásnak.
 *  Annak ellenére, hogy az UTF-8 széles körben támogatott, a pár soros programokban, akár még a
 *  házi feladatokban is a sztringek kezeléséhez a Latin-2 kódolás használatát javaslom,
 *  mert 1 betűt mindig 1 karakteren kódol, így a tároláshoz szükséges bájtok száma megegyezik
 *  a betűk számával.
 *  Bonyolultabb, valós használatra készült programokban pedig el kell rejteni a kódolás részleteit
 *  megfelelő osztályok használatával.
 *
 *  Egy szövegfájl kódolásának megváltoztatására számos módszer van pl:
 *    1. Megnyitás notepad++ segítségével, mentés a kívánt kódolással
 *    2. CodeBlocks editorával: Edit->File encoding
 *    3. Visual Studio: File -> Save as -> Save gombon megjelenő lefelé mutató nyíl
 *    4. iconv konverter használata (https://www.gnu.org/software/libiconv)
 *
 *  A CodeBlocks alapértelmezett kódolási módja a
 *          Settings -> Editor -> Other settings -> Encoding menüben állítható
 *
 */
void ekezetes_io() {
    cout << "Árvíztűrő tükörfúrógép" << endl << endl;
    cout << "Ha a fenti szoveg nem olvashato, akkor karakterkodolast kell valtani!\n"
         << "A forrasfajl atkodolasahoz ld. a SZORGALMI feladat kommentjeit!" << endl << endl;
    cout << "Írj be egy szöveget: ";
    char buf1[SORHOSSZ];
    cin.getline(buf1, SORHOSSZ);
    cout << "Ezt írtad: " << buf1 << endl;
}

/**
 * A futtató környezetnek megfelelő alapértelmezett nyelvi környezetet állít be
 * WinX esetén kódlapot is állít
*/
void setDefLang() {
    /// Operációs rendszer szinten alapértelmezett nyelvi környezet beállítása.
    char *p = setlocale(LC_ALL, "");

    /// Ha ennek a fájlnak a karakterkódolása nem egyezik meg az alapértelmezett kódolással,
    /// akkor az ékezetes kiírások nem jól látszanak.
    /// Alapértelmezett kódolásra váltás CodeBlocks-ban: Edit->File encoding -> System default
#if WINX
    if (strstr(p, ".1250") != NULL) { /// Windows-1250-es kódolást használ.
        SetConsoleCP(1250);
        SetConsoleOutputCP(1250);
    } else {                          /// esetleg UTF-8 ?
        SetConsoleCP(65001);
        SetConsoleOutputCP(65001);
    }
#endif
    cout << "\nA beállított nyelvi környezet: " << p << endl;
}

