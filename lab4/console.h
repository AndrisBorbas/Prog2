/**
 * \file: console.h
 * Console input/output kezelése
 *
 */
#ifndef CONSOLE_H
#define CONSOLE_H

#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
# define _WINX 
#elif defined(__linux__) || defined(__sun)
# define _UNIX
#else
# error "OS?"
#endif

/**
 *  Console ablak kezelését támogató osztály.
 *  Singleton minta szerint valósítjuk meg: csak egyetlen példányban létezik.
 *  Egy statikus objektummal a singleton minta nem teljesíthető, mert
 *  nem lehet kontrollálni az objektum élettartamát. (Később tanulnak róla)
 *  A bemutatott megoldásban is csak a keletkezést lehet  befolyásolni,
 *  a megszűnést nem (de ez már megfelel a mintának).
 *
 */
class Console {
public:
    static const int KEY_DOWN = 0x102;  /* Down arrow key */
    static const int KEY_UP = 0x103;    /* Up arrow key */
    static const int KEY_LEFT = 0x104;  /* Left arrow key */
    static const int KEY_RIGHT = 0x105; /* Right arrow key */
    static const int KEY_HOME = 0x106;  /* home key */
private:
    struct keyCodes;
    int trCode(int code, keyCodes* kt);
    Console();                  ///< csak belülről érhető el
    Console(const Console&);    ///< nem engedélyezzük
    Console& operator=(const Console&); ///< ezt sem
public:
    /// példányosítás
    static Console& con() {
        static Console theConsole;  /// a függvény első futásakor fut el a konstruktora
        return theConsole;
    }
    /// Destruktor
    ~Console();

    /// Egy karakter olvasása echo nélkül
    /// Ncurses-szerű inputot ad.
    /// @return olvasott karakter kódja a speciális billentyűk 256 fölé kerülnek
    int getch();

    /// Képernyő törlés
    void clrscr();

    /// Pozicionálás a képernyőn
    /// (1,1) a kezdő pozíció a bal felső sarok
    /// @param x - vízszintes pozíció (1..80)
    /// @param y - függőleges pozíció (1..24?)
    void gotoxy(int x, int y);

    /// Valós érték nagyságának megjelenítése egy vízszintes vonallal
    /// @param value - érték
    /// @param max - érték maximuma
    /// @param width - megjelenítés szélessége
    /// @param txt - vonal előtt kiírandó szöveg. Tartalmazhat printf formátumstringet a value-ra
    /// @param y - vonal függőleges kezdő pozíciója
    /// @param x - vonal vízszintes kezdő pozíciója
    void hMeter(double value, double max, int width = 70,
                            const char* txt = 0, int y = 0, int x = 0);
};

#endif // CONSOLE_H

