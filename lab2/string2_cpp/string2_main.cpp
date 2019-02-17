/**
 * \file string2_main.cpp
 * (UTF-8 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * C++ nyelvre átírt dinamikus String működését teszteli.
 *
 * Ha a javasolt sorrendben oldja meg a feladatot, akkor lépésről-lépésre
 * tesztelheti az elkészített függvényeket. Ehhez a string1.h fájlban definiált
 * ELKESZULT makró értékét kell megfelelően változtatni.
 *
 * A C verzióval ellentétben nem csak szemrevételezéssel ellenőrizzük az egyes
 * függvények helyességét, hanem a gtest_lite EXPECT_... makróival is.
 *
 * Megjegyzések:
 * _1 A C változatnál látott szöveges kiírások csak akkor látszanak, ha a
 * DEBUG azonosító (makró) projekt szinten definiált.
 *
 * _2 Ha a CPORTA azonosító (makró) projekt szinten definiált, akkor a
 * gtest_lite tesztek eredménye, csak hiba estén jelenik meg.
 *
 */

/**
 *
 * A példa a dinamikus memória használatánál előforduló hibákat
 * a labor útmutatóban ismertetett memtrace módszerrel ellenőrzi.
 *
 * Az ellenőrzés aktivizálásához minden fájl elején definiálni kell
 * a MEMTRACE makrót. Ezt célszerű fordítási opcióként megadni.
 * (ld. a labor útmutatójában)
 */

#include <cstring>          /// Sztringműveletekhez

/// malloc, new felüldefiniálásával készített memóriaszivárgás és konzisztencia ellenőrző
#include "memtrace.h"       /// a standard headerek után kell lennie
#include "gtest_lite.h"

#include "string2.h"

using std::cout;
using std::endl;

int main() {
    GTINIT(std::cin);       // Csak C(J)PORTA működéséhez kell

    TEST(String2, Inic) {
      String a; createString(a);
      EXPECT_EQ(0u, StringLen(a));       /// 0 hosszúságúnak kell lennie
      EXPECT_EQ((char const*)(NULL), StringC_str(a));   /// null pointert várunk
    } END

    String a; createString(a, 'x');      /// 'a' létrehozása
    TEST(String2, FromChar) {
      EXPECT_EQ(1u, StringLen(a));       /// 1 hosszúságúnak kell lennie
      EXPECT_STREQ("x", StringC_str(a)); /// és x-nek kell benne lenni
      printStringDbg(a);	             /// Ezt kellene látni (ld. 1_ megjegyzést): [1], x|
    } END

// Ha létezik a createString(String&, const char*) függvény.
#if ELKESZULT >= 1
    String b; createString(b, "alma");   /// 'b' létrehozása
    TEST(String2, FromCstr) {
      EXPECT_EQ(4u, StringLen(b));       /// 4 hosszúságúnak kell lennie
      EXPECT_STREQ("alma", StringC_str(b));
      printStringDbg(b);                 /// Ezt kellene látni (ld. 1_ megjegyzést): [4], alma|
    } END
#endif

// Ha létezik a createString(String&, const String&) függvény.
#if ELKESZULT >= 2
    String c; createString(c, b);        /// 'c' létrehozása
    TEST(String2, FromStr) {
      EXPECT_EQ(4u, StringLen(b));
      EXPECT_STREQ("alma", StringC_str(b));
      printStringDbg(b);                 /// Ezt kellene látni (ld. 1_ megjegyzést): [4], alma|
    } END
#endif

// Ha létezik a charAtString(const String& s0, unsigned int idx) függvény.
#if ELKESZULT >= 3
    TEST(String2, CharAt3) {
      char ch;
      EXPECT_NO_THROW(ch = charAtString(b, 3));
      EXPECT_EQ('a', ch);
    #ifdef DEBUG
      cout << charAtString(b, 3) << endl; /// Ezt kellene látni (ld. 1_ megjegyzést): a
    #endif
    } END

    TEST(String2, CharAt4) {
      EXPECT_THROW(charAtString(b, 4), const char*);
    } END

    TEST(String2, CharAt_1) {
      EXPECT_THROW(charAtString(b, -1), const char*);
    } END
#endif

// Ha létezik az addString(cont String&, char) függvény.
#if ELKESZULT >= 4
    String d = addString(a, b);  /// Összefűzzük a két stringet egy újba
    TEST(String2, AddStr2Str1) {
      EXPECT_EQ(5u, StringLen(d));
      EXPECT_STREQ("xalma", StringC_str(d));
      printStringDbg(d);                 /// Ezt kellene látni (ld. 1_ megjegyzést): [5], xalma|
    } END
#endif

// Ha létezik az addString(const String&, const String& b) függvény.
#if ELKESZULT >= 5
    String e = addString(b, c);
    TEST(String2, AddStr2Str2) {
      EXPECT_EQ(8u, StringLen(e));
      EXPECT_STREQ("almaalma", StringC_str(e));
      printStringDbg(e);                 /// Ezt kellene látni (ld. 1_ megjegyzést): [8], almaalma|
    } END
//
    disposeString(e);                    /// e-t másra akarjuk használni, felszabadítjuk
    e = addString(d, 'A');
    TEST(String2, AddStr2Str2) {
      EXPECT_EQ(6u, StringLen(e));
      EXPECT_STREQ("xalmaA", StringC_str(e));
      printStringDbg(e);                 /// Ezt kellene látni (ld. 1_ megjegyzést): [6], xalmaA|
    } END
#endif

// Attól függően, hogy mi keletkezett, fel kell szabadítani a lefoglalt területeket
#if ELKESZULT >= 5
    disposeString(e);
#endif
#if ELKESZULT >= 4
    disposeString(d);
#endif
#if ELKESZULT >= 2
    disposeString(c);
#endif
#if ELKESZULT >= 1
    disposeString(b);
#endif
    disposeString(a);

    if (ELKESZULT < 3)
        FAIL() << "Legalabb az elso harom feladatot oldja meg!" << std::endl;

    if (ELKESZULT == 5 && !gtest_lite::test.fail())
        std::cout << "Szuper! Mind kesz" << endl;
    else
        std::cout << "EKESZULT = " << ELKESZULT << std::endl;

    GTEND(std::cerr);       // Csak C(J)PORTA működéséhez kell
    return 0;
}
