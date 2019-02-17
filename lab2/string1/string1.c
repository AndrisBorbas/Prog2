/**
 * \file string1.c
 * (UTF-8 kodolasu fajl. Allitsa/konvertalja at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * Dinamikus sztring létrehozása C-ben.
 * A példa a C++ osztály fogalmának megértését készíti elő.
 * Az egységesség kedvéért minden sztring paramétert pointerrel adtunk át.
 * A kód kihasználja, hogy a c90-es szabványtól a free(NULL) használata legális.
 *
 * Figyelem:
 * UTF-8 kódolásban az ékezetes betűk a memóriában több bájtot foglalnak el.
 * Ha csak a kommentekben használ ékezetet, akkor nincs teendője.
 * Ha adatban, konstansban is, akkor ezt külön kell kezelni.
 * Ebben a feladatbab azonban ilyenre nem lesz szükség.
 */

#include <stdio.h>              // Kiíratáshoz
#include <stdlib.h>             // malloc miatt
#include <string.h>             // Stringműveletekhez
#include <assert.h>             // hibakezeléshez

/// malloc, new felüldefiniálásával készített memóriaszivárgás és konzisztencia ellenőrző
#include "memtrace.h"           // a standard headerek után kell lennie

#include "string1.h"            /// saját sztring header

/**
 * Inicializálatlan struktúrát hoz alapállapotba
 * @param s0  - pointer az adatstruktúrára (String-re)
 */
void createString(String *s0) {
    s0->pData = NULL;
    s0->len = 0;
}

/**
 * Sztring felszabadítása
 * Ha dinamikus memóriát használunk, gondoskodni kell a lefoglalt terület felszabadításról is.
 * Feltételezzük, hogy csak létező (inicializált) Stringre használjuk.
 * @param s0  - pointer a String-re
 */
void disposeString(String *s0) {
    free(s0->pData);		// felszabadítjuk
	s0->len = 0;
}

/**
 * C sztringre konvertál, azaz visszaad egy pointert a tárolt,
 * nullával lezárt sztring-re.
 * Most így tárolunk, de nem feltétlen kell így tárolnunk.
 * Ez az interfész (fv.) elfedi a belső tárolást.
 * Feltételezzük, hogy a paraméterként megadott sztring létezik
 * @param s0  - pointer a String-re
 */
const char* StringC_str(const String *s0) {
    return s0->pData;
}

/**
 * Visszaadja a sztring tényleges hosszát (lezáró nulla nélkül).
 * Most így tárolunk, de nem feltétlen kell így tárolnunk.
 * Ez az interfész (fv.) elfedi a belső tárolást.
 * Feltételezzük, hogy a paraméterként megadott sztring létezik
 * @param s0  - pointer a String-re
 */
unsigned int StringLen(const String *s0) {
    return s0->len;
}

/**
 * Kiírunk egy sztringet (debug célokra)
 * Feltételezzük, hogy a paraméterként megadott sztring létezik
 * @param s0  - pointer a String-re
 */
void printStringDbg(const String *s0) {
    printf("[%d], %s|\n", s0->len, s0->pData);
}

/**
 * Sztringet készít egy karakterből
 * Feltételezzük, hogy a sztring nem létezik még (pData és len inicializálatlan).
 * Ha elfogy a memória, akkor assert error
 * @param s0  - pointer a String-re
 * @param ch - a karakter amiből elkészíti a Stringet
 */
void createStringFromChar(String *s0, char ch) {
    /// Meghatározzuk a hosszát
    s0->len = 1;
    /// Lefoglalunk a helyet a hossznak + a lezáró nullának
    s0->pData = malloc(s0->len+1);
    assert(s0->pData != NULL);   // nincs jobb ötletünk a hibajelzésre; (később lesz)
    /// Betesszük a karaktert
    s0->pData[0] = ch;
    s0->pData[1] = '\0';

/// A memóriahibák figyelését tesztelendő csúnyán beleírunk a memóriába
 //s0->pData[-4] = '#';
}

/**
 * Sztringet készít nullával lezárt karaktersorozatból (C-sztringből)
 * Feltételezzük, hogy a sztring nem létezik még (pData és len inicializálatlan).
 * Ha elfogy a memória, akkor assert error
 * @param s0 - pointer a String-re
 * @param p  - pointer a C sztringre (feltételezhetjük, hogy nem NULL)
 */
void createStringFromCstr(String *s0, const char *p) {
    // Meghatározzuk a hosszát
    s0->len = strlen(p);
    // Helyet foglalunk
    s0->pData = (char*)malloc(s0->len+1);
    assert(s0->pData != NULL);   // nincs jobb ötletünk a hibajelzésre; (később lesz)
    // Bemásoljuk a sztringet, ami le van zárva 0-val így használható az strcpy is
    strcpy(s0->pData, p);
	s0->pData[s0->len] = '\0';
}

/**
 * Stringet készít egy szringből
 * Feltételezzük, hogy a sztring nem létezik még (pData és len inicializálatlan).
 * Ha elfogy a memória, akkor assert error
 * @param s0  - pointer a String-re
 * @param s1  - pointer a másik String-re (Feltételezzük, hogy ez létezik!)
 */
void createStringFromString(String *s0, const String *s1) {
    // Meghatározzuk a hosszát
    s0->len = s1->len;
    // Helyet foglalunk
    s0->pData = (char*)malloc(s0->len+1);
    assert(s0->pData != NULL);   // nincs jobb ötletünk a hibajelzésre; (később lesz)
    // Bemásoljuk a sztringet, ami le van zárva 0-val így használható az strcpy is
    strcpy(s0->pData, s1->pData);
	s0->pData[s0->len] = '\0';
}

/**
 * Két Sztringet fűz össze.
 * Az eredményt egy harmadikba (visszatérési érték) írja.
 * Feltételezzük, hogy a paraméterként megadott Stringek léteznek
 * Ha elfogy a memória, akkor assert error
 * @param s0  - pointer az egyik String-re
 * @param s1  - pointer a másik String-re
 * @return új String: A két sztring összefûzve.
 */
String addString2String(const String *s0, const String *s1) {
    String res;		// ide kerül az eredmény
    // Meghatározza az új sztring hosszát
    res.len = s0->len + s1->len;
    // Helyet foglalunk
    res.pData = (char*)malloc(res.len+1);
    assert(res.pData != NULL);   // nincs jobb ötletünk a hibajelzésre; (később lesz)
    // Az elejére bemásolja az első sztringet
    strcpy(res.pData, s0->pData);
    // Bemásolja a második sztringet.
    strcat(res.pData, s1->pData);
    return res;		// visszatér az eredménnyel
}

/**
 * Sztring végéhez karaktert ad.
 * Az eredményt egy harmadikba (visszatérési érték) írja.
 * Feltételezzük, hogy a paraméterként megadott sztring létezik
 * Ha elfogy a memória, akkor assert error
 * @param s0 - pointer a String-re
 * @param ch - a karakter amit hozzáfűz
 * @return új String
 *
 * Ez a függvény visszavezeti a feladatot a korábbiakra.
 * Ezért ezt elkészítettük, de a megvalósításba memória szivárgás
 * hiba csúszott
 */
String addChar2String(const String *s0, char ch) {
    String res, temp;
    createStringFromChar(&temp, ch);    /// char-ból sztring
    res = addString2String(s0, &temp);
	disposeString(&temp);
    return res;
}

/**
 * Egy megadott indexű elemmel tér vissza.
 * Feltételezzük, hogy a paraméterként megadott sztring létezik
 * Hibás index esetén assert error
 * @param s0  - pointer a String-re
 * @param idx - index
 * @return idx indexű karakter
 */
char charAtString(const String *s0, unsigned int idx) {
    assert(idx < s0->len);
    return s0->pData[idx];
}
