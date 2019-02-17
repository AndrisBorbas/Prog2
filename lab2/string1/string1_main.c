/**
 * \file main.c
 *
 * (UTF-8 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * C nyelven létrehozott String modul kipróbálása.
 * Ha jól valósította meg a modul függvényeit akkor
 * A program a következő sorokat írja a standard kimenetre:
 * [1], x|
 * [4], alma|
 * a
 * [4], alma|
 * [5], xalma|
 * [8], almaalma|
 * [6], xalmaA|
 *
 * Figyelem:
 * UTF-8 kódolásban az ékezetes betűk a memóriában több bájtot foglalnak el.
 * Ha csak a kommentekben használ ékezetet, akkor nincs teendője.
 * Ha adatban, konstansban is, akkor ezt külön kell kezelni.
 * Ebben a feladatbab azonban ilyenre nem lesz szükség.
 */

#include <stdio.h>      /// Kiíratáshoz
/// malloc, new felüldefiniálásával készített memóriaszivárgás és konzisztencia ellenőrző
#include "memtrace.h"

#include "string1.h"     /// String modulunk fejlécállománya

/**
 *  Egyszerű program a függvények kipróbálásához.
 */
int main() {
    //
    String a; createStringFromChar(&a, 'x');      /// 'a' létrehozása
    printStringDbg(&a);	                /// Ezt kellene látni: [1], x|
    //
    String b; createStringFromCstr(&b, "alma");   /// 'b' létrehozása
    printStringDbg(&b);                 /// Ezt kellene látni: [4], alma|
    printf("[3], %c\n", charAtString(&b, 3));/// Ezt kellene látni: a
    //
    String c; createStringFromString(&c, &b);     /// 'c' létrehozása
    printStringDbg(&c);                 /// Ezt kellene látni: [4], alma|
    //
    String d = addString2String(&a, &b);/// Összefűzzük a két stringet egy újba
    printStringDbg(&d);                 /// Ezt kellene látni: [5], xalma|
    String e = addString2String(&b, &c);
    printStringDbg(&e);                 /// Ezt kellene látni: [8], almaalma|
    //
    disposeString(&e);                  /// e-t másra akarjuk használni, felszabadítjuk
    e = addChar2String(&d, 'A');        /// Ezt kellene látni: [6], xalmaA|
    printStringDbg(&e);
    //


	printf("a: 0x%p\n", a);
	printf("b: 0x%p\n", b);
	printf("c: 0x%p\n", c);
	printf("d: 0x%p\n", d);
	printf("e: 0x%p\n", e);

    disposeString(&e);
    disposeString(&d);
    disposeString(&c);
    disposeString(&b);
    disposeString(&a);
    return 0;
}

