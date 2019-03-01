#ifndef POTMETER_H
#define POTMETER_H

#include "resistor.h"

/**
 * \file potmeter.h
 *
 * Vegyünk egy potmétert melynek az ellenállása legyen R (a két végkivezetés között).
 * A kezelőszerv forgatásával az egyik végpont és a középső pont között az
 * ellenállás R 1%-a és 99%-a között változtatható.
 *
 * Modellezzük a potméter két végpontjának összekötésével létrejövő áramköri
 * elemet: (SimPoti)!
 *
 * Az elemet úgy használjuk, hogy a középkivezetést és az összekötött végpontokat
 * kötjük be az áramkörbe.
 *
 * A végpontok összekötésével létrejövő elem (SimPoti) működése két párhuzamosan
 * kötött változtatható ellenállással (r1, r2) modellezhető, ahol r1 + r2 = R
 * Jelentse POS a kezelőszerv állását (1-99), ekkor:
 * r1 = R*POS/100, r2 = R*(100-POS)/100
 *
 */

/**
 * FELADAT:
 * Valósítsa meg a potmeter.cpp állományban a SimPoti tagfüggvényeit!
 * A megvalósításhoz használja fel a Resistor osztályt!
 */
class SimPoti {
    double R;   /// potméter ellenállása a két végpont között.
    int pos;    /// kezelőszerv állása (1..99);
public:
    /// Konstruktor.
    /// @param r - ellenállás értéke [ohm]
    /// A konstruktor állítsa középállásba (50) a kezelőszervet!
    SimPoti(double r);

    /// Kezelőszerv poziciójának lekérdezése
    /// @return - pozíció (1..50)
    int getPos() const;

    /// Két végpont és a középpont közötti eredő ellenállás
    /// @return - Eredő ellenállás (Resistor)
    Resistor getRes() const;

    /// Kezelőszerv fogatása (növel)
    /// A pozíció értéke nő, 99-nél fennakad
    /// @return pillanatnyi pozció
    int operator++();

    /// Kezelőszerv fogatása (csökkent)
    /// A pozíció értéke csökken, 1-nél fennakad
    /// @return pillanatnyi pozció
    int operator--();
};

#endif // POTMETER_H
