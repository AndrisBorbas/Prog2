A Git tárolóból letölthető [https://git.ik.bme.hu/Prog2/ell_feladat/CppEllenallas](https://git.ik.bme.hu/Prog2/ell_feladat/CppEllenallas)
fájlok felhasználásával hozzon létre a lokális fejlesztőkörnyezetében egy C++ projektet! 
Tanulmányozza a letöltött állományokat!

A **Resistor** osztály egy elektromos ellenállás leegyszerűsített működését szimulálja. 
Az osztályt a **resistor.h** állományban deklaráltuk. Néhány tagfüggvényt inline tagfüggvényként (\*1) meg is valósítottunk.  
Az Ön feladata a többi függvény megvalósítása a **resistor.cpp** állományban.
 
Modellünkben az ellenállások soros/párhuzamos összekapcsolásakor egy új ellenállás jön létre a  kapcsolásnak megfelelő eredő ellenállással. 
Az ellenállások összekapcsolását túlterhelt operátorokkal valósítjuk meg. 
A soros kapcsolást **a + operatorral**, míg párhuzamos kapcsolást **a % operátorral**. Soros kapcsoláskor az eredő ellenállás a két ellenállás összege, míg a párhuzamosan kapcsolt ellenállások eredője a két ellenállás replusza, vagyis

![R\_{{A\%B}}=\frac{{1}}{{\frac{{1}}{{R\_A}} +\frac{{1}}{{R\_B}}}}](https://jporta.iit.bme.hu/exercise/18/view/12/file)

A konstruktorokon és a destruktoron kívül a következő tagfüggvényeket deklaráltuk:

    void setDef(double) - alapérték beállítása. A paraméter nélkül hívott konstruktor ezzel az ellenállásértékkel hozza létre az objektumot (ld. *2 megj.).
    double getR() const – (eredő) ellenállás lekérdezése [Ω].
    Resistor operator+(const Resistor&) const – soros kapcsolás operátora.
    Resistor operator%(const Resistor&) const – párhuzamos kapcsolás operátora.

Van még egy többszörös-operátor is, amely n darab egyforma sorosan kapcsolt r ellenállás eredőjét képzi:

    Resistor operator*(int n, const Resistor& r)

Valósítsa meg a hiányzó függvényeket a specifikációnak megfelelően! A megvalósítást a **resistor\_test.cpp** tesztprogrammal ellenőrizze!
 
A **\* operátort** úgy valósítsa meg, hogy nulla vagy negatív n esetén az Ön Neptun-kódját tartalmazó const char\* típusú kivételt dobjon!

A **defR** statikus adattagot úgy definiálja, hogy értéke a Jporta által megadott legyen! 
A definíciónál a **static** kulcsszót nem kell/szabad újra kiírni! (\*2)

**Megj:**            
\*1 Az osztályban deklarált tagfüggvények automatikusan inline függvények.            
\*2 A statikus adattag, és a statikus tagfüggvény fogalma a 4. előadáson válik ismertté. A lokális teszt nem kéri ennek ismeretét, ha 
definiálja a **NO_STATIC** makrót! Ekkor a lokális teszt nem teszteli ezt a feladatrészt.
A portálra azonban **csak teljes megoldást töltsön fel**!


