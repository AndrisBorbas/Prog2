/**
 * \file PString_test.cpp
 *
 * Tesztprogram az PString osztály teszteléséhez.
 *
 * Ha elakad, érdemes ELKSZULT 0-val kezdeni!
 *
 */

#include <iostream>
#include <sstream>

#include "memtrace.h"     // a standard header-ek után kell lennie
#include "pstring.h"
#include "gtest_lite.h"

using std::cout;
using std::cin;
using std::endl;

// Érdemes ELKESZULT 0-val kezdeni!
#define ELKESZULT 14

/// Tagfüggvények létezését tesztelő sablonok generálása
CREATE_Has_(String)
CREATE_Has_(Serializable)

/// PString paraméterű függvény
void f(const PString&) {}

int main() {
    GTINIT(std::cin);       // Csak C(J)PORTA működéséhez kell

#if ELKESZULT >= 0
    TEST(Elkeszult0, sanity_check) {
      if (_Has_String<PString>::member == false)
        FAIL() << "Feltehetoleg nem oroklessel oldotta meg!" << endl;

      if (_Has_Serializable<PString>::member == false)
        FAIL() << "Feltehetoleg nem oroklessel oldotta meg!" << endl;

      if (_Is_Types<PString, String>::convertable == false)
        FAIL() << "PString nem komvertalhato String-ge!" << endl;

      if (_Is_Types<String, PString>::convertable == false)
        FAIL() << "String nem komvertalhato PString-ge!" << endl;
    } ENDM
#endif

/**
 *  1. A paraméter nélkül hívható konstruktora üres sztringet hozzon létre!
 */
#if ELKESZULT >= 1
    TEST(Elkeszult1, construct) {
      PString ures;
      EXPECT_EQ((size_t)0, ures.size()) << "Baj van a string hosszaval" << endl;
    } ENDM
#endif

/**
 *  2. Van olyan tagfüggvénye ( c_str() ), ami C-sztringgel, azaz nullával lezárt
 *     karaktersorozatra mutató pointerrel (const char *) tér vissza.
 */
#if ELKESZULT >= 2
    TEST(Elkeszult2, emptyStr) {
      PString ures;
      EXPECT_EQ((size_t)0, ures.size()) << "Baj van a string hosszaval" << endl;
      EXPECT_STREQ("", ures.c_str()) << "Nem ures sztring jott letre" << endl;
    } ENDM
#endif

/**
 * 3. Van olyan konstruktora, ami karakterből hoz létre sztringet.
 */
#if ELKESZULT >= 3
    TEST(Elkeszult3, fromChr) {
      char ch = 'a';
      PString a(ch);
      EXPECT_EQ((size_t)1, a.size()) << "Baj van a string hosszaval" << endl;
      EXPECT_STREQ("a", a.c_str()) << "Karakterbol sztring letrehozasa nem sikerult!" << endl;
      String b('a');    // konstansból is megy?
      EXPECT_STREQ("a", b.c_str()) << "Karakterbol sztring letrehozasa nem sikerult!" << endl;
    } ENDM
#endif

/**
 *  4. Van olyan konstruktora, ami C-sztringből (const char*) hoz létre sztringet.
 *  A const char* konstruktor lemásolja a sztringet, nem csak a pointert.
 */
#if ELKESZULT >= 4
    TEST(Elkeszult4, FromCstr) {
      const char *hello = "Hello sztring";
      PString a(hello);
      EXPECT_EQ(strlen(hello), a.size()) << "Baj van a string hosszaval" << endl;
      EXPECT_STREQ(hello, a.c_str()) << "C-sztringbol string letrehozasa nem sikerult!" << endl;

      char cpp[] = { 'C', '+', '+', '\0' };
      PString b(cpp);
      cpp[0] = 'X';
      EXPECT_STRNE(cpp, b.c_str()) << "FromCstr: le kellett volna masolni a karaktertombot!" << endl;
    } ENDM
#endif

/**
 *  5. Az osztályból létrehozott objektum legyen átadható értékparaméterként!
 */
#if ELKESZULT >= 5
    TEST(Elkeszult5, ctor) {
      const char *hello = "Hello sztring";
      PString a(hello);
      PString b = a;
      EXPECT_EQ(strlen(hello), b.size()) << "Baj van a string hosszaval!" << endl;
      EXPECT_STREQ(hello, b.c_str()) << "Baj van a masolo konstruktorral!" << endl;

      if (a.c_str() == b.c_str())     // Ha a két pointer egyezik, akkor nem másolta le az adatot
         FAIL()  << "!** ctor: nem elegendo a pointereket lemasolni!" << endl;
      EXPECT_STREQ(hello, a.c_str()) << "Masolo kontsr. elromlott a forras!" << endl;
      EXPECT_EQ(strlen(hello), a.size()) << "Masolo konstr. alatt elromlott a forras hossza!" << endl;
      const PString c = a;
      String d = c;     // konstansból is megy?
      EXPECT_STREQ(hello, d.c_str()) << "Baj van a masolo konstruktorral" << endl;
    } ENDM
#endif

/**
 *  6. Támogassa a többszörös értékadást (b = a = a)!
 */
#if ELKESZULT >= 6
    TEST(Elkeszult6, opAssign) {
      const char *hello = "Hello sztring";
      PString a(hello);
      PString b("Duma1"), c("Duma2");
      EXPECT_STRNE(a.c_str(), b.c_str());
      a = a;
      EXPECT_EQ(strlen(hello), a.size()) << "Baj van az ertekadassal: a = a hossz" << endl;
      EXPECT_STREQ(hello, a.c_str()) << "Baj van az ertekadassal: a = a" << endl;
      c = b = a;
      if (a.c_str() == b.c_str())     // Ha a két pointer egyezik, akkor nem másolta le az adatot
         FAIL()  << "!** op=: nem elegendo a pointereket lemasolni!" << endl;
      EXPECT_EQ(strlen(hello), a.size()) << "Ertekedasnal elromlott a forras hossza!" << endl;
      EXPECT_STREQ(hello, a.c_str()) << "Ertekadasnal elromlott a forras!" << endl;
      EXPECT_EQ(strlen(hello), b.size()) << "Ertekedas: nem jo a hossz!" << endl;
      EXPECT_STREQ(hello, b.c_str()) << "Ertekadas nem sikerult!" << endl;
      EXPECT_EQ(strlen(hello), c.size()) << "Ertekedas: nem jo a hossz!" << endl;
      EXPECT_STREQ(hello, c.c_str()) << "Ertekadas nem sikerult!" << endl;
      const PString d("Konst.");
      c = d;        // konstansból is megy?
      EXPECT_EQ(c.size(), c.size()) << "Ertekedas konstansbol: nem jo a hossz!" << endl;
      EXPECT_STREQ(d.c_str(), c.c_str()) << "Ertekadas konstansbol nem sikerult!" << endl;
    } ENDM
#endif

/**
 *  7. Legyenek olyan operátorai (operator+), amivel a sztring végéhez sztringet
 *     és karaktert lehet fűzni!
 */
#if ELKESZULT >= 7
    TEST(Elkeszult7, strPlusStr) {
      PString a("Hello ");
      PString b("sztring");
      PString c;
      c = a + b;
      EXPECT_STREQ("Hello sztring", c.c_str()) << "Nem sikerult a + String muvelet!" << endl;
      EXPECT_STREQ("Hello ", a.c_str()) << "A + muvelet elrontja a bal oldalt?" << endl;
      EXPECT_STREQ("sztring", b.c_str()) << "A + muvelet elrontja a jobb oldalt?" << endl;
      const String a1 = a, b1 = b;
      String c1;
      c1 = a1 + b1;          // konstansból is megy?
      EXPECT_STREQ("Hello sztring", c1.c_str()) << "Nem sikerult a + String muvelet!" << endl;
    } ENDM

    TEST(Elkeszult7, strPlusChr) {
      PString a("Hello ");
      PString b;
      b = a + 'B';
      EXPECT_STREQ("Hello B", b.c_str()) << "Nem sikerult a + char muvelet!" << endl;
      EXPECT_STREQ("Hello ", a.c_str()) << "A + muvelet elrontja a bal oldalt?" << endl;
      const String a1 = a;
      PString b1;
      b1 = a1 + 'B';          // konstansból is megy?
      EXPECT_STREQ("Hello B", b1.c_str()) << "Nem sikerult a + char muvelet!" << endl;
      EXPECT_STREQ("Hello ", a1.c_str()) << "A + muvelet elrontja a bal oldalt?" << endl;

    } ENDM
#endif

/**
 *  8. Lehessen karakterhez is sztringet fűzni a + operátorral!
 */
#if ELKESZULT >= 8
    TEST(Elkeszult8, chrPlusStr) {
      PString a("ello");
      PString b;
      char h = 'H';
      b = h + a;
      EXPECT_STREQ("Hello", b.c_str()) << "Nem sikerult char + Str muvelet!" << endl;
      EXPECT_STREQ("ello", a.c_str()) << "A + muvelet elrontja a jobb oldalt?" << endl;
      PString b1;
      b1 = 'H' + a;  // konstanssal is megy?
      EXPECT_STREQ("Hello", b.c_str()) << "Nem sikerult char + Str muvelet!" << endl;
    } ENDM
#endif

/**
 *  9. A tárolt a karakterek legyenek elérhetőek a szokásos módon indexeléssel!
 *     Az indexeléssel elért elem legyen használható balértékként is!
 *     A konstans objektumok is legyenek indexelhetők.
 *     Az indexelés operátor hiba esetén dobjon const char * kivételt!
 */
#if ELKESZULT >= 9
    TEST(Elkeszult9, index) {
      PString a("Hello 678");
      EXPECT_NO_THROW(a[0]);
      EXPECT_NO_THROW(a[7]);
      EXPECT_NO_THROW(a[8]);
      EXPECT_THROW(a[9], const char *);
      EXPECT_THROW(a[-1], const char *);
      EXPECT_EQ('7', a[7]);
      a[7] = '.';
      EXPECT_EQ('.', a[7]);
    } ENDM
#endif

/**
 * 10. Készítsen olyan << operátort, amivel egy sztring kiírható egy ostream típusú
 *     objektumra!
 */
#if ELKESZULT >= 10
    TEST(Elkeszult10, insert) {
      PString a("Hello sztring");
      std::stringstream ss;
      ss << a;
      EXPECT_STREQ("Hello sztring", ss.str().c_str());
    } ENDM
#endif

/**
 * 11. Készítsen olyan fűzhető >> operátort, amivel be tud olvasni egy szót egy sztring-be!
 *     A beolvasó működjön úgy, mint a scanf %s, azaz a szó végét white space határolja!
 *     A szó eleji white space karaktereket pedig el kell dobni.
 *    *Megj: az istream wshite space kezelése a flags() tagfüggvénnyel szabályozható
 */
#if ELKESZULT >= 11
    TEST(Elkeszult11, extract) {
      PString a("Hello   sztring \n Lajos12");
      std::stringstream ss;
      ss << a;
      String in1, in2, in3;
      ss >> in1 >> in2;         // fűzhetőnek kell lenni
      while (ss >> in3);        // csak kicsit gonosz a teszt !
      EXPECT_STREQ("Hello", in1.c_str());
      EXPECT_STREQ("sztring", in2.c_str());
      EXPECT_STREQ("Lajos12", in3.c_str());
    } ENDM
#endif

/**
 * 12. Azt vizsgáljuk, hogy PString képes-e kiírni magát és visszaolvasni
 */
#if ELKESZULT >= 12
    TEST(Elkeszult12, persist) {
      std::stringstream ss;

      PString a("hello"), b;
      a.write(ss);

      std::cout << "\nElkeszult12: Ezt irta az adatfolyamba:\n";
      memtrace::mem_dump(ss.str().c_str(), ss.str().size(), stdout);
      std::cout << "----------------------------------------\n\n";

      b.read(ss);
      EXPECT_EQ((size_t)5, b.size());
      EXPECT_STREQ("hello", b.c_str());
	  //b.printDbg();
      EXPECT_FALSE(ss.eof())   << "Tobbet olvasott a stream-rol? " << std::endl;
      ss.ignore(1);
      EXPECT_TRUE(ss.eof())    << "Nem olvasta vegig stream-et? " << std::endl;

      ss.clear();
      a.write(ss);
      PString c("???????");     // esetleg memóriahibáz okoz?
      c.read(ss);
      EXPECT_EQ((size_t)5, c.size());
      EXPECT_STREQ("hello", c.c_str());
    } ENDM
#endif

/**
 * 13. Azt vizsgáljuk, hogy soremelés (\n) lehet-e a perzisztens sztringben
 */
#if ELKESZULT >= 13
    TEST(Elkeszult13, persistNL) {
      std::stringstream ss;

      PString a("hello\n word"), b;
      a.write(ss);
      b.read(ss);
      EXPECT_EQ((size_t)11, b.size());
      EXPECT_STREQ("hello\n word", b.c_str());

      f(a+b);   // ez csak egy példa, hogy miért kell konvertálni
    } ENDM
#endif

/**
 * 14. Azt vizsgáljuk, hogy több stringet kiírva is jó-e
 */
#if ELKESZULT >= 14
    TEST(Elkeszult14, persitMulti) {
      std::stringstream ss;

      PString a("Hello "), b("Word\r"), c("Hello PString");
      a.write(ss);
      b.write(ss);
      c.write(ss);

      std::cout << "\nElkeszult14: Ezt irta az adatfolyamba:\n";
      memtrace::mem_dump(ss.str().c_str(), ss.str().size(), stdout);
      std::cout << "----------------------------------------\n\n";

      PString d;
      d.read(ss);
      EXPECT_EQ((size_t)6, d.size());
      EXPECT_STREQ("Hello ", d.c_str());
      EXPECT_FALSE(ss.eof())   << "Tobbet olvasott a stream-rol? " << std::endl;

      d.read(ss);
      EXPECT_EQ((size_t)5, d.size());
      EXPECT_STREQ("Word\r", d.c_str());
      EXPECT_FALSE(ss.eof())   << "Tobbet olvasott a stream-rol? " << std::endl;

      d.read(ss);
      EXPECT_EQ((size_t)13, d.size());
      EXPECT_STREQ("Hello PString", d.c_str());
      EXPECT_FALSE(ss.eof())   << "Tobbet olvasott a stream-rol? " << std::endl;
      ss.ignore(1);
      EXPECT_TRUE(ss.eof())    << "Nem olvasta vegig stream-et? " << std::endl;

    } ENDM
#endif

/// Itt a vége
    std::cout << "ELKESZULT = " << ELKESZULT << std::endl;
    if (ELKESZULT < 14 && !gtest_lite::test.fail())
      FAIL() << "\nMind a 14 feladatot oldja meg!" << std::endl;

    GTEND(std::cerr);       // Csak C(J)PORTA működéséhez kell
    return 0;
}
