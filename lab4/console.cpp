/**
 * \file: console.cpp
 * Console input/output kezelése
 * Linux/UNIX alatt csak ANSI terminálbeállításokkal megy.
 *   (ncurses/pdcurses használatával hordozható lehetne! Help velcome!)
 *
 */
#include "console.h"

#include <iostream>
#include <iomanip>
#if defined(_WINX)
  #include <conio.h>
  #include <windows.h>
#elif defined(_UNIX)
  #include <termios.h>    //termios, TCSANOW, ECHO, ICANON
  #include <unistd.h>     //STDIN_FILENO
#endif
#include <cstdio>


/// Noname névtér.
/// Csak ebből a fájlból érhető el
namespace {
#if defined(_WINX)
void clrscr() {
    HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(hstdout, &csbi)) {
        COORD coordScreen = { 0, 0 };
        DWORD cCharsWritten;
        DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
        FillConsoleOutputCharacter(hstdout, ' ', dwConSize, coordScreen, &cCharsWritten);
        FillConsoleOutputAttribute(hstdout, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
        SetConsoleCursorPosition(hstdout, coordScreen);
    }
}

void gotoxy(int x, int y) {
    HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwCursorPosition;
    dwCursorPosition.X = (SHORT)x;
    dwCursorPosition.Y = (SHORT)y;
    SetConsoleCursorPosition(hstdout, dwCursorPosition);
}

#elif  defined(_UNIX)

/// Kihasználjuk, hogy ANSI terminál
void clrscr() {
    std::cout << "\x1b[2J";
}

/// Kihasználjuk, hogy ANSI terminál
void gotoxy(int x, int y) {
    std::cout << "\x1b[" << y << ';' << x << 'H';
}

/// skipws kikapcsolása fontos!
int _getch() {
    char c;
    std::cin >> std::noskipws >> c;
    return c;
}

/// Ide menti el a konzol beállítását, hogy vissza tudja állítani kilépésnél.
/// Logikusabb helyen lenne az osztályban, de így a console.h tisztább maradhat.
struct termios term_save;

#endif

} // noname namespace

/// Segédtípus a kódváltáshoz
struct Console::keyCodes {
      int code;
      int key;
};


/// Segédfüggvény a kódváltáshoz.
/// @param code - bejövő kód
/// @param kt - kod-újkód párok tömbje
/// @return ujkód, ha sikerült a váltás egyébként 0
inline int Console::trCode(int code, keyCodes* kt) {
    for (int i = 0; kt[i].code != 0; i++)
        if (kt[i].code == code)
            return kt[i].key;
    return 0;
}

/// UNIX/Linux alatt át ki kell kapcsolni az echo-t és a kanonikus módot
Console::Console() {
#if defined(_UNIX)
    struct termios newt;
    tcgetattr(STDIN_FILENO, &::term_save);
    newt = term_save;
    newt.c_lflag &= ~(ICANON|ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
#endif
}

/// Elmentett működési módok visszaállítása
Console::~Console() {
#if defined(_UNIX)
    tcsetattr(STDIN_FILENO, TCSANOW, &::term_save);
#endif
}

/// Egy karakter olvasása echo nélkül
/// Ncurses-szerű inputot ad.
/// @return olvasott karakter kódja a speciális billentyűk 256 fölé kerülnek
int Console::getch() {
    /// segédmakró
    #define C(c, k) {c,k}
#if defined(_WINX)
    static keyCodes arrows[] = { C(72,KEY_UP), C(80,KEY_DOWN), C(77,KEY_RIGHT), C(75,KEY_LEFT), C(0,0) };
    int ch = ::_getch();
    if (ch == 0xE0) {       /// windows ezt a kódot adja a nyílbillentyűk előtt
        ch = ::_getch();    /// utána jön a billentyű kódja
        return trCode(ch, arrows);
    }
#elif defined(_UNIX)
    static keyCodes arrows[] = { C('A',KEY_UP), C('B',KEY_DOWN), C('C',KEY_RIGHT), C('D',KEY_LEFT), C(0,0) };
    int ch = ::_getch();
    if (ch == 0x1b) {       /// ANSI módban ezt adja be a terminál a nyilak előtt
        ch = ::_getch();    /// utána egy [
        if ( ch != '[') return 0; /// nem tudjuk mi van
        ch = ::_getch();    /// utána jön a billentyű kódja
        return trCode(ch, arrows);
    }
#endif
    #undef C
    return ch;
}

/// Képernyő törlés
void Console::clrscr() { ::clrscr(); }

/// Pozicionálás a képernyőn
/// (1,1) a kezdő pozíció a bal felső sarok
/// @param x - vízszintes pozíció (1..80)
/// @param y - függőleges pozíció (1..24?)
void Console::gotoxy(int x, int y) { ::gotoxy(x, y); }


/// Valós érték nagyságának megjelenítése egy vízszintes vonallal
/// @param value - érték
/// @param max - érték maximuma
/// @param width - megjelenítés szélessége
/// @param txt - vonal előtt kiírandó szöveg. Tartalmazhat printf formátumstringet a value-ra
/// @param y - vonal függőleges kezdő pozíciója
/// @param x - vonal vízszintes kezdő pozíciója
void Console::hMeter(double value, double max, int width, const char *txt, int y, int x) {
    if (x > 0 || y > 0) gotoxy(x, y);
    if (txt != NULL) {
       /// milyan hosszú lesz?
       int len = snprintf(NULL, 0, txt, value)+1;

       /// annyit foglalunk és beleírjuk
       char *s = new char[len];
       snprintf(s, len, txt, value);
       std::cout << s;

       /// kiírtuk, nem kell már a buffer
       delete[] s;

       /// ennyivel csökken a szélesség
       width -= len;
    }
    width -= 2; /// két szöglet miatt
    double scale = value / max;

    /// kirajzoljuk a vonalat
    std::cout << "[";
    int pos = int(width * scale);
    for (int i = 0; i < width; ++i) {
        if (i < pos) std::cout << "=";
        else if (i == pos) std::cout << ">";
        else std::cout << " ";
    }
    std::cout << "]\r";
    std::cout.flush();
}
