/*
 * \file teglalap.cpp
 * (Latin-2 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * Egyszerû osztály létrehozása
 */
#include <iostream>
using std::cout;
using std::endl;

/**
 * Az Ön feladata megvalósítani az egyes tagfüggvényeket.
 * Ahogyan halad a megvalósítással egyre több tesztesetet kell
 * lefuttatni, ezért az ELKESZULT makró értéket folyamatosan növelje a
 * feladatsorszámoknak megfelelõen!
 */
#define ELKESZULT    2

/**
 * Feladatok:
 * 1. ELKESZULT=1
 *    Valósítsa meg (definiálja) a hiányzó tagfüggvényeket! (kerulet(), terulet())
 *
 * 2. ELKESZULT=2
 *    Egészítse ki az osztályt úgy, hogy tömb is létrehozható legyen belõle
 *    (Tipp: tömb csak olyan osztályból példányosítható, aminek van paraméter
 *    nélkül hívható konstruktora)
 *
 */

class Teglalap {
double a, b;              // oldalak hossza
public:
Teglalap(double, double); // konstruktor
void kiir() const;        // kiírja az oldalakat
double kerulet() const;   // kerület kiszámítása
double terulet() const;   // terület kiszámítása
};

Teglalap::Teglalap(double a=1, double b=1)
{
   this->a = a;
   this->b = b;
}

void Teglalap::kiir() const
{
   cout << "a:" << a << " b:" << b << endl;
}

// ELKESZULT 1
// 1. feladat
double Teglalap::terulet() const
{
   return a * b;
}

// Itt pedig a kerület számítást kell megvalósítania
double Teglalap::kerulet() const
{
   return a * 2.0 + b * 2.0;
}



int main()
{
   Teglalap ta(1, 4);

   cout << "ta: ";
   ta.kiir();
   Teglalap tb(3, 8);
   cout << "tb: ";
   tb.kiir();
#if ELKESZULT >= 1
   cout << "ta kerülete:" << ta.kerulet() << endl;
   cout << "tb kerülete:" << tb.kerulet() << endl;
   cout << "ta területe:" << ta.terulet() << endl;
   cout << "tb területe:" << tb.terulet() << endl;
#endif

#if ELKESZULT >= 2
   const int N = 5;
   Teglalap  teglak[N];
   for (int i = 0; i < N; i++)
   {
      cout << "teglak[" << i << "]: ";
      teglak[i].kiir();
   }
#endif
   return 0;
}
