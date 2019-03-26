/**
 * \file boltMain.cpp
 * Tesztprogram a Kassza, Aru, Tej, Kifli osztályok teszteléséhez.
 *
 * \par Demonstrációs cél:
 * 1. Heterogén kollekció demonstrálása.
 *    A Kassza osztályban tárolt tétel Aru POINTER-t tárol. Így minden
 *    áruból származó új áru tárolására alkalmas.
 *
 * 2. Az öröklés adta egyik lehetőség a bővíthetőség demonstrálása
 *
 *** FONTOS ***
 * A MEMTRACE makrónak minden fordítási egységben definiált kell, hogy legyen!
 * Ezt legkényelmesebben projekt szintű beállítással tudja elérni.
 *   (Projekt->Build options->#defines)
 *
 */

#include <iostream>
#include <sstream>

#include "memtrace.h"
#include "gtest_lite.h"
#include "kassza.h"
#include "tej.h"

#ifdef KIFLI_IS_VAN
# include "kifli.h"
#endif

using std::cout;
using std::endl;
using std::cin;

int main() {

#ifdef KILI_IS_VAN
/// Az első két teszteset a Kifli objektum kiírási formátumát teszteli.
    TEST(kifli, print1) {
        Kifli tejeskifli(29, "tejes");
        std::stringstream ss;
        tejeskifli.print(ss);       // stringstream az output, amit
        EXPECT_STREQ("Kifli tejes; 29Ft/db", ss.str().c_str()); // C sztringgé konvertálunk és összehasonlítjuk
    } ENDM

    TEST(kifli, print2) {
        Kifli sajtoskifli(72, "sajtos");
        std::stringstream ss;
        ss << sajtoskifli;          // inserternek is mennie kell
        EXPECT_STREQ("Kifli sajtos; 72Ft/db", ss.str().c_str());
    } ENDM
#endif

/// Most felveszünk néhány árufajtát a boltba
    const Tej tej15(1.5, 230);
    const Tej tej15lm(1.5, 310, "laktozmentes");
    const Tej tej28(2.8, 270);

#ifdef KIFLI_IS_VAN
    const Kifli sajtoskifli(70, "sajtos");
    const Kifli tejeskifli(29, "tejes");
#endif

#if 0
/// Kivétel dobásának ellenőrzése: Tudjuk, hogy a kasszába 20 tétel fér
    TEST(Kassza, kivetel) {
        Kassza p2;
        for (int i = 0; i < 20; i++)
            EXPECT_NO_THROW(p2.elad(3, tej28));
        EXPECT_ANY_THROW(p2.elad(3, tej28));
    } ENDM
#endif

/// Eladunk ezekből a p1 kasszánál
/// Az első két eladási mennyiséget a standard bemenetről olvassuk be
    Kassza p1;
    int ennyi_tejet;
    cout << "Mennyi tej kell? ";
    cin >> ennyi_tejet;
    p1.elad(ennyi_tejet, tej15);

#ifdef KIFLI_IS_VAN
    int ennyi_kiflit;
    cout << "Mennyi kifli kell? ";
    cin >> ennyi_kiflit;

    p1.elad(ennyi_kiflit, sajtoskifli);
#endif

/// Itt pedig csalunk: előredátumozzuk az eladásokat
    p1.elad(2, tej15, Datum(3000, 4, 1));
    p1.elad(2, tej15lm, Datum(3000, 4, 1));
#ifdef KIFLI_IS_VAN
    p1.elad(10, sajtoskifli, Datum(3000, 4, 1));

/// Kell még két kifli?
    if (ennyi_kiflit % 2 == 1)
        p1.elad(2, tejeskifli, Datum(3000, 4, 1));
#endif

    p1.elad(3, tej28);      /// még három liter tejet is eladunk ma

/// teljes litsta
    cout << "\nOsszes eladas:" << endl;
    p1.list(cout);

/// Eladások 3000. 4. 1-jén
    cout << "\nEladasok (" << Datum(3000, 4,1 ) << "): " << endl;
    p1.list(cout, Datum(3000, 4, 1));

/// Gyenge ellenőrzés: csak a sorok számát ellenőrizzük
    TEST(Kassza, sorok_szama_3000_ben) {
        std::stringstream ss;
        p1.list(ss, Datum(3000, 4, 1));     // stringstrem-be listázunk
        std::string s = ss.str();           // átalakítjuk std::string-gé
        int cnt = std::count(s.begin(), s.end(), '\n'); // megszámoljuk benne a '\n' karaktereket
        int elvart = 2;                     // tudjuk, hogy 2 tej
#ifdef KIFLI_IS_VAN
        elvart += 1;                        // és 1 kifli
        if (ennyi_kiflit % 2 == 1)
            elvart +=1;                     // + 1, ha kellett még kifli
#endif
        EXPECT_EQ(elvart, cnt) << "! ** Ketparameteres list: nem megfelelo szamu sort irt ki!" << endl;
    } ENDM

/// Napi összeg
    double sum = p1.napiOsszeg();
    cout << "\nMai szumma: " << sum << "Ft" << endl;

/// megnézzük, hogy jól számolt-e
    TEST(Kassza, mai_szumma) {
        double s = 3 * tej28.getAr();
        s += ennyi_tejet * tej15.getAr();
#ifdef KIFLI_IS_VAN
        s += ennyi_kiflit * sajtoskifli.getAr();    // szerintunk ennyi
#endif
        EXPECT_DOUBLE_EQ(s, sum) << "! ** napiOsszeg() nem jol mukodik!" << endl;
    } ENDM

    return 0;
}
