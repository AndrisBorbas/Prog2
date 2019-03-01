/**
 * \file potmeter_teszt.cpp
 *
 * Két végén összekötött potmétert modellező osztály tesztelése.
 *
 * Először gtest tesztekkel ellenőrizzük a működést pár esetre.
 * Utána buta konzolos kijelzéssel "csavargatjuk" a kezelőszervet.
 * Ez a rész Linux/UNIX alatt csak ANSI terminálbeállításokkal megy.
 *   (ncurses/pdcurses használatával hordozható lehetne! help velcome!)
 */

#include <iostream>
#include <cctype>
#include "gtest_lite.h"
#include "potmeter.h"
#include "console.h"

int main() {

  TEST(SimPoti, Kozepallas) {
    SimPoti p(100);
    EXPECT_EQ(25., p.getRes().getR());
  } END

  TEST(SimPoti, Novel) {
    SimPoti p(10);
    ++p;
    EXPECT_DOUBLE_EQ(2.499, p.getRes().getR());
  } END

    TEST(SimPoti, Csokkent) {
    SimPoti p(10);
    --p;
    EXPECT_DOUBLE_EQ(2.499, p.getRes().getR());
  } END

  TEST(SimPoti, Alsoveg) {
    SimPoti p(200);
    for (int i = 0; i < 1000; i++) --p;
    EXPECT_DOUBLE_EQ(1.98, p.getRes().getR());
  } END

  TEST(SimPoti, Felsoveg) {
    SimPoti p(1);
    for (int i = 0; i < 1000; i++) ++p;
    EXPECT_DOUBLE_EQ(0.0099, p.getRes().getR());
  } END

    std::cout << "Indulhat a teszt? ";
    Console& con = Console::con();      // itt jön létre az egyetlen Console példány;
    int ch = con.getch();               // karakter olvasás
    con.clrscr();                       // képernyő törlés
    SimPoti p(100);
    do {
       switch (ch) {
            case ' ':
            case Console::KEY_UP:
                ++p;
                break;
            case Console::KEY_DOWN:
                --p;
                break;
        }
        /// Kezelőszerv kijelzés a 3. sorba
        con.hMeter(p.getPos(), 99, 80, "Pos%4.0f:", 3);

        /// Áramkijelzés (50V-al vizsgáljuk, 80 széles kijelzés az 5. sorba)
        con.hMeter(p.getRes().getI(50), 50, 80, "I%5.1f: ", 5);

        /// Feszültség kijelzés (2A-val vizsgáljuk)
        con.hMeter(p.getRes().getU(2), 50, 80, "U%5.1f: ", 7);

        /// Eredő ellenállás kijelzés
        con.hMeter(p.getRes().getR(), 25, 80, "R%5.1f: ", 9);

        /// kiírjuk a parancsokat
        con.gotoxy(1, 11);
        std::cout << "SP, FEL: novel, LE: csokkent, X: kilep";
    } while ((ch = toupper(con.getch())) != 'X');

    return 0;
}
