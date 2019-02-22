/**
 * \file resistor_test.cpp
 *   (UTF-8 kodolasu fajl. Allitsa at a megjenetes kodolasat,
 *    ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * Ohmikus ellenállást modellező osztály kipróbálása
 *
 * Néhány ellenállás összekapcsolása, az elvárt eredmények megjegyzésben.
 */

#include <iostream>
#include "resistor.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
    // cporta tesztesetei miatt csak egészeket írunk ki.
    cout.setf(std::ios::fixed);
    cout.precision(0);

    Resistor r;
    cout << r.getR() << endl;                         // default érték

    cout << Resistor(130).getR() << endl;             // 130
    cout.precision(0);
    Resistor r1(1000), r2(3000), r3(6000);

               // o--[r1]--[r2]--o
    cout << (r1 + r2).getR() << endl                  // 4000

               //    +--[r1]--+
               // o--+        +---o
               //    +--[r1]--+
         << (r1 % r1).getR() << endl                  //  500

               // o--[r1]--[r1]--o
         << (2 * r1).getR() << endl                   // 2000

               // o--[r1]--[r1]--[r2]--o
         << (2*r1 + r2).getR() << endl                // 5000

               // o--[r1]--[r2]---[r1]--[r2]--o
         << (2 * (r1+r2)).getR() << endl              // 8000

               //    +--[r2]--+   +--[r2]--+
               // o--+        +---+        +---o
               //    +--[r3]--+   +--[r3]--+
         << (2 * (r2%r3)).getR() << endl;             // 4000

#ifndef NO_STATIC
    Resistor::setDef(2);	  		      // 2 ohm a default
#endif
    Resistor rt[10];			  	      // a tömb minden eleme 2 ohmos lesz
    cout << rt[5].getR() << endl;         // 5. elem is 2

    try {
        int n;
        while (cin >> n) {                // amíg tud számot olvasni
            cout << (n * r1).getR() << endl;
        }
        cout << "Építsünk örökmozgót!" << endl;
    }
    catch (const char *s) {
        cout << s << endl;                // dobott kivétel
    }

    return 0;
}
