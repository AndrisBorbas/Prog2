/*
 * \file integer.h
 */

#ifndef INTEGER_H
#define INTEGER_H


/// Integer osztály.
/// A konverziós operátorok és a C automatikus konverziós szabályai
/// miatt az osztály példányai úgy használhatók mint egy int változó.
class Integer {
    int adat;
public:
    Integer(int i = 0) :adat(i) {}  /// konstruktor és egyben konverziós operátor
    operator int&() { return adat; }/// cast
    operator int() const { return adat; } /// const cast
    int* operator&() {   return &adat; }
    const int* operator&() const {   return &adat; }
    virtual ~Integer() {}
};

#endif // INTEGER_H
