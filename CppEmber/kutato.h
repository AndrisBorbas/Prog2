/*
 * \file kutato.h
 *
 * Kutato osztály deklarációja
 * Az egyszerűség kedvéért minimális funkcionalitás, inline függvényekkel.
 */
#ifndef KUTATO_H
#define KUTATO_H

#include "ember.h"

class Kutato :public Ember {
public:
    /// Konstruktor
    /// @param n  - név
    /// @param ev - születési év
    Kutato(const char *n, int ev) :Ember(n, ev) {}

    /// Foglalkozás lekérdezése
    const char* foglalkozas() const { return "Kutato"; }
};

#endif
