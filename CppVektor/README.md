Töltse le a [https://git.ik.bme.hu/Prog2/ell\_feladat/CppVektor](https://git.ik.bme.hu/Prog2/ell_feladat/CppVektor)
projektet! 
Tanulmányozza a **vektor.h** állományban deklarált osztályt!
A **Vektor** osztály valós elemek tárolására szolgáló tömböt valósít meg. A tömb méretét a konstruktornak lehet megadni, ami a tároló terület a dinamikus memóriában hozza létre.   
Az osztálynak a konstruktorokon és destruktoron kívül a következő tagfüggvényei vannak:

    unsigned int size() const; – méret lekérdezése
    static void setDefSize(unsigned int size); – alapértelmezett méret megadása
    static void setDefValue(double value); – alapértelmezett érték megadása
    Vektor& operator=(const Vektor&); – értékadó operátor
    double& operator[](unsigned int); – indexoperátor (hiba esetén kivételt dob)
    const double& operator[](unsigned int) const; – indexoperátor (hiba esetén kivételt dob)

Van egy olyan globális operátor is, ami a vektor minden elemét megszorozza a paraméterként adott valós értékkel:

    Vektor operator*(double, const Vektor&)

A függvények rövid leírását (paraméterek, elvárt működés) a *vektor.h* fájl tartalmazza. 

**Valósítsa meg** a **vektor.cpp** állományban a hiányzó függvényeket (operátorok, a másoló konstruktor,
destruktor) úgy, hogy azok az elvárt módon működjenek, és a mellékelt tesztprogram (*vektorMain.cpp*) hiba nélkül fusson!
Az indexoperátor hiba esetén dobjon egy *const char\** típusú kivételt, ami Ön **Neptun**-kódját tartalmazza!

A paraméter nélküli, valamint az 1 és 2 paraméteres konstruktort a *vektor.h* fájlban inline tagfüggvényként elkészítettük. Ez nemcsak létrehozza a vektort, hanem feltölti a megadott kezdőértékkel is. A konstruktor az alapértelmezett méretet és kezdőértéket két statikus adattagból veszi, melyek definícióit ne felejtse el elkészíteni! Az értékek a **Jporta által megadottak** legyenek!


**Mielőtt** megoldását beadja, **tesztelje** azt a saját fejlesztői környezetében
a *wektorMain.cpp*  tesztprogrammal! Elemezze a tesztprogramot, hogy megértse,
mit fog elvárni a Jporta, ami **ugyanezt** a programot futtatja.

**Fontos:** Legyen definiált a **MEMTRACE** makró minden fordítási egységben. Ezt a beállítást a Git tárolóból letölthető projektfájlok illetve a *Makefile* eleve tartalmazza. Amennyiben nem a letölthető projektfájlok valamelyikét használja, úgy ügyeljen a MEMTRACE projektszintű definiálására!

**Megj:** A Jporta a feltöltött megoldást lefordítja, majd úgy futtatja, hogy a standard inputon egy előre megadott adatsort ad a programnak. Ez adatsor tartalmazza, a teszteset sorszámát és a teszteset további input adatát is. Érdemes a módszert megfigyelni, mert a nagy házi feladat teszteléséhez is hasonló tesztelési metódust ajánlunk, ahol Ön töltheti fel a standard inputra kerülő adatsort is.  
Igy a standard inputról olvasott adattal vezérelheti, hogy melyik teszteset fusson le.
Természetesen a feladattól függhet, hogy ez a módszer használható vagy nem, mint ahogy az is, 
hogy a gtest_lite makrói használhatóak-e.
