/*
 * \file hallgato.cpp
 *
 * Hallgato osztály tagfüggvényeinek definíciója
*/

#include <cstring>
#include "ember.h"
#include "hallgato.h"

/// Konstruktorok
/// Paraméter nélkül hívható konstr.
Hallgato::Hallgato() :kepzes("Nappali") {
    strncpy(neptun, "KODKOD", NEP_L); // Mi a  helyzet a névvel és a szül. évvel?
}

/// 3 paraméteres konstr.
/// @param n   - név
/// @param nep - neptun
/// @param ev  - születési év
Hallgato::Hallgato(const char *n, const char *nep, int ev) :Ember(n, ev), kepzes("Nappali") {
    strncpy(neptun, nep, NEP_L);
}

/// Adott évben betöltött kor lekérdezése
/// @param  ev - adott év, amelyikben a betöltött életkort vizsgáljuk
/// const char * hibát dob, ha az adott év korábbi mint a születési év
int Hallgato::getKor(int ev) const {
    if (szulEv > ev)
        throw "meg sem szulettem!";
    return Ember::getKor(ev);
}

/// Foglalkozás lekérdezése
const char* Hallgato::foglalkozas() const {
    return "Hallgato";
}
