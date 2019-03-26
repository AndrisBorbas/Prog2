/*
 * \file hallgato.h
 *
 * Hallgato osztály deklarációja
 */
#ifndef HALLGATO_H
#define HALLGATO_H

#include <iostream>     // a NULL miatt
#include <string>
#include "ember.h"

/**
 * Hallgato osztály.
 * neptun kód fix méretű tömbben
 */
class Hallgato :public Ember {
public:
    /// NEPTUN kód hossza
    static const int NEP_L = 6+1;// static const inicializálható így
private:
    char neptun[NEP_L];         // + lezáró nullával
    std::string kepzes;         // képzés típusa most mindenkinél nappali
                                // jelenleg nem használjuk
public:
    /// Konstruktorok
    /// Paraméter nélkül hívható konstr.

    Hallgato();
    /// 3 paraméteres konstr.
    /// @param n   - név
    /// @param nep - neptun
    /// @param ev  - születési év
    Hallgato(const char *n, const char *nep, int ev);

    /// neptun kód lekérdezése
    const char *getNeptun() const { return neptun; }

    /// Adott évben betöltött kor lekérdezése
    /// @param  ev - adott év, amelyikben a betöltött életkort vizsgáljuk
    /// const char * hibát dob, ha az adott év korábbi mint a születési év
    int getKor(int ev) const;

    /// Foglalkozás lekérdezése
    const char* foglalkozas() const;
};

#endif
