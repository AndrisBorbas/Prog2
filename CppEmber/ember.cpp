/*
 * \file ember.cpp
 *
 * Ember osztály tagfüggvényeinek definíciója
 * Nevet, születési évet tárol.
 * A nevet dinamikusan, \0-lal lezárt karaktersorozatként tárolja.
 */

#include <cstring>
#include "memtrace.h"
#include "ember.h"

/// Ez az alapértelmezett konstruktor is
/// @param n  - név (alapértelmezése a saját Neptun kódja)
/// @param ev - születési év (alapértelmezésben a saját születései éve)
Ember::Ember(const char* n, int ev) :szulEv(ev) {
    nev = new char[strlen(n)+1];
    strcpy(nev, n);
}

/// Másoló konstruktor
Ember::Ember(const Ember& e) :nev(NULL) {
    *this = e;
}

/// Értékadó operátor
Ember& Ember::operator=(const Ember& e) {
    if (this != &e) {
        delete[] nev;
        nev = new char[strlen(e.nev)+1];
        strcpy(nev, e.nev);
        szulEv = e.szulEv;
    }
    return *this;
}

/// Név lekérdezése
const char* Ember::getNev() const {
    return nev;
}

/// Adott évben betöltött kor lekérdezése
/// @param  ev - adott év, amelyikben a betöltött életkort vizsgáljuk
/// Nem vizsgálja, hogy megszületett-e
int Ember::getKor(int ev) const {
    return ev - szulEv;
}

/// Foglalkozás lekérdezése
const char* Ember::foglalkozas() const {
    return "Meg nincs";
}

/// Destruktor
Ember::~Ember() {
    delete[] nev;
}
