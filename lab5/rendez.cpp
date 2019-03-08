/**
 * \file rendez.cpp
 *
 * Egyszerű teszt modul az ékezetes karaktereket tartalmazó
 * String osztály kipróbálására.
 * Az összehasonlítás figyelembe veszi az LC_COLLATE beállítást
 *
 * A programból kiírt szövegkonstansok megjelenése azonban függ
 * a forrásfájl karakterkódolásától.
 * Ezt itt meglehetősen fapados módon feltételes include-dal próbáltuk
 * megoldani.
 * Igazi hordozható megoldást csak valamilyen lokalizációs technika
 * használata ad (pl. gettext, wxString, stb.)
 *
 */

#ifdef _MSC_VER
// MSC ne adjon figyelmeztető üzenetet a sztringkezelő függvényekre.
  #define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <clocale>
#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
# include <windows.h>
# include "rendez.h"    // latin-2 kódolású szövegek
#else
# include "rendez_u8.h" // UTF8 kódolású szövegek
#endif

#include "string5.h"

using std::cout;
using std::endl;
using std::cin;

#if ELKESZULT >= 11
/// Összehasonlító a qsorthoz
int cmp(const void* s1, const void* s2) {
    return strcoll((*(const String**)s1)->c_str(), (*(const String**)s2)->c_str());
}

void rendez() {
    cout << endl;
    cout << String(INDUL) << endl;

    const int N = 15;
    String szavak[N];   /// Itt lesznek a szavak
    String *poik[N];    /// Itt pedig a pointerek a rendezéshez
    int db;
    cout << String(IRJON) << N << String(SZOVEGET) << endl <<
            String(UTOLSO) << endl;
    cout << String(MINTA) << endl;

    for (db = 0; db < N && cin >> szavak[db]; ++db)
        poik[db] = &szavak[db];     /// címek tömbjét képezzük

    /// Pointerek tömbjét rendezzük
    qsort(poik, db, sizeof(String*), cmp);
    cout << "----- Rendezve: ------" << endl;
    for (int i = 0; i < db; ++i) {
        poik[i]->printDbg("");	    /// így a hossz is látszik UTF-8-nál nem egyezik meg a betűk számával
//        cout << *poik[i] << endl;
    }
}
#endif
