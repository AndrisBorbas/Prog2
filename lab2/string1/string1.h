#ifndef STRING1_H
#define STRING1_H

/**
 * \file string1.h
 * (UTF-8 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * Dinamikus String létrehozása C-ben.
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

/**
 * String struktúra
 * A pData által mutatott dinamikus területen vannak a karakterek (a lezáró nullával együtt).
 * A len mező a tényleges hossz, amibe nem számít bele a lezáró nulla.
 */
typedef struct String {
    char *pData;        /// pointer az adatra
    unsigned int len;   /// hossz lezáró nulla nélkül
} String;

/**
 * Inicializálatlan struktúrát hoz alapállapotba
 * @param s0  - pointer az adatstruktúrára (String-re)
 */
void createString(String *s0);

/**
 * Sztring felszabadítása
 * Ha dinamikus memóriát használunk, gondoskodni kell a lefoglalt terület felszabadításról is.
 * Feltételezzük, hogy csak létező (inicializált) Stringre használjuk.
 * @param s0  - pointer a String-re
 */
void disposeString(String *s0);

/**
 * C sztringre konvertál, azaz visszaad egy pointert a tárolt,
 * nullával lezárt sztring-re.
 * Most így tárolunk, de nem feltétlen kell így tárolnunk.
 * Ez az interfész (fv.) elfedi a belső tárolást.
 * Feltételezzük, hogy a paraméterként megadott sztring létezik
 * @param s0  - pointer a String-re
 */
const char* StringC_str(const String *s0);

/**
 * Visszaadja a sztring tényleges hosszát (lezáró nulla nélkül).
 * Most így tárolunk, de nem feltétlen kell így tárolnunk.
 * Ez az interfész (fv.) elfedi a belső tárolást.
 * Feltételezzük, hogy a paraméterként megadott sztring létezik
 * @param s0  - pointer a String-re
 */
unsigned int StringLen(const String *s0);

/**
 * Kiírunk egy sztringet (debug célokra)
 * Feltételezzük, hogy a paraméterként megadott sztring létezik
 * @param s0  - pointer a String-re
 */
void printStringDbg(const String *s0);

/**
 * Sztringet készít egy karakterből
 * Feltételezzük, hogy a sztring nem létezik még (pData és len inicializálatlan).
 * Ha elfogy a memória, akkor assert error
 * @param s0  - pointer a String-re
 * @param ch - a karakter amiből elkészíti a Stringet
 */
void createStringFromChar(String *s0, char ch);

/**
 * Sztringet készít nullával lezárt karaktersorozatból (C-sztringből)
 * Feltételezzük, hogy a sztring nem létezik még (pData és len inicializálatlan).
 * Ha elfogy a memória, akkor assert error
 * @param s0 - pointer a String-re
 * @param p  - pointer a C sztringre (feltételezhetjük, hogy nem NULL)
 */
void createStringFromCstr(String *s0, const char *p);

/**
 * Stringet készít egy szringből
 * Feltételezzük, hogy a sztring nem létezik még (pData és len inicializálatlan).
 * Ha elfogy a memória, akkor assert error
 * @param s0  - pointer a String-re
 * @param s1  - pointer a másik String-re (Feltételezzük, hogy ez létezik!)
 */
void createStringFromString(String *s0, const String *s1);

/**
 * Két Sztringet fűz össze.
 * Az eredményt egy harmadikba (visszatérési érték) írja.
 * Feltételezzük, hogy a paraméterként megadott Stringek léteznek
 * Ha elfogy a memória, akkor assert error
 * @param s0  - pointer az egyik String-re
 * @param s1  - pointer a másik String-re
 * @return új String: A két sztring összefûzve.
 */
String addString2String(const String *s0, const String *s1);

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
String addChar2String(const String *s0, char ch);

/**
 * Egy megadott indexű elemmel tér vissza.
 * Feltételezzük, hogy a paraméterként megadott sztring létezik
 * Hibás index esetén assert error
 * @param s0  - pointer a String-re
 * @param idx - index
 * @return idx indexű karakter
 */
char charAtString(const String *s0, unsigned int idx);

#endif
