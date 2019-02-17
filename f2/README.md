Ebben a feladatban 3 függvényt és egy sablont kell elkészítenie a specifikációknak megfelelően.
Töltse le a feladathoz előkészített teljes könyvtárat a tantárgy Git tárolójából git kliens használatával, vagy akár 
más eszközzel a [https://git.ik.bme.hu/Prog2/ell_feladat/Nem_OO](https://git.ik.bme.hu/Prog2/ell_feladat/Nem_OO) címről!

**Feladatok:**

 1. Valósítsa meg a _nem\_oo.h_ állományban deklarált függvényeket (_atoi()_, _strcat()_, _unique()_), melyek hasonlóan működnek, mint az azonos nevű szabványos függvények, de nem pontosan ugyanúgy. A függvények paramétereit és elvárt működését a _nem\_oo.h_ fájlban adtuk meg.
 2. A _max.hpp_ fájlban valósítson meg a _sajat_ névtéren belül egy olyan sablont, ami alaptípusok esetén a paraméterként kapott érték közül a nagyobbat adja.
 3. Specializálja a sablont a _nem\_oo.h_ állományban deklarált _sajat::Komplex_ típusra úgy, hogy a nagyobb abszolút értékű Komplex számot adja vissza! Az abszolút érték kiszámításához használhatja a _sajat_ névtérben definiált _absKomplex_ inline függvényt.   
 4. Ellenőrizze a megvalósított függvények és sablonok működését a _nem\_oo\_test.cpp_ tesztprogrammal!

Csak az elkészített **nem\_oo.cpp** és **max.hpp** fájlokat kell feltöltenie a portálra. 
A _memtrace.h_ és _memtrace.cpp_ fájlok a memóriakezelés teszteléséhez szükségesek. Nem kell megértenie a működésüket!

**Javaslat:**

- Fontos, hogy a megvalósítandó függvényeket a megfelelő **névtérben** definiálja.
- Az _atoi()_ megvalósításakor ügyeljen arra, hogy csak helyes számot fogadjon el! 
 - Helyes számjegysorozat végét white space, vagy sztring vége ('\0') jelzi. Minden más karakter előfordulása hiba.
 - Szintén hiba, ha a számjegysorozatban olyan számjegy, vagy betű fordul elő, ami nem érvényes az adott számrendszerben. B számrendszerben a B számjegy már nem fordulhat elő!
- **Hiba** esetén dobjon **const char\*** típusú kivételt, melynek értéke az Ön **Neptun azonosítója** legyen!
- Használja a [Horner-elrendezést](https://hu.wikipedia.org/wiki/Polinom) a szám (polinom helyettesítési) 
értékének kiszámításához. Így elkerülheti a pow() használatát és n db szorzással és összeadással kiszámíthatja az értéket!
Például a decimális 346=((0\*10+3)\*10)+4)\*10+6, de a 3467=346\*10+7, azaz csak egy szorzással és egy összeadással több, és nem kellett tudni előre számjegek számát sem.
- Először mindenképpen oldja meg a feladatot a saját környezetében. A Jporta pontosan ugyanazt a tesztprogramot futtatja, amit letöltött a Git tárolóból. Egyedüli különbség, hogy a CPORTA makró definiált.
- ELképzelhető olyan durva memóriahiba, amit az operációs rendszer csíp meg. Ilyenkor a Jportán 11-es megállási státus jelenik meg, ami azt jelenti, hogy a program illegális memóriaműveletet próbált végezni, amit az OS azonnali megállítással jutalmazott.
- Ügyeljen arra, hogy a **using namespace valami;** azt teszi lehetővé, hogy scope operátor használata nélkül is elérhetjük a valami névtér neveit, de ez nem jelenti azt, hogy mostantól minden definíció a valami névtérben keletkezik!   

**Szorgalmi feladat:**

Ha a SZORGALMI makró definiálva van, akkor meghívódik az _ekezetes\_io()_ függvény. 
Ez egy lehetőséget mutat az ékezetes karakterek C++ kódból való kiírására/kezelésére.
Czirkos Zoltán által készített, a karakterkódolás gyötrelmeit bemutató 
[anyag](https://infoc.eet.bme.hu/karakterkodolas) az UTF-8 kódolást preferálja, amivel 
teljes mértékben egyetértek. 

A pár soros programokban, amikor nem a megjelenés a lényeg, akkor inkább ne használjunk
ékezetes karaktereket vagy a Latin-2 kódolás használatát javaslom, mert 1 betűt 
mindig 1 karakteren kódol, így a tároláshoz szükséges bájtok száma megegyezik a betűk számával.

Bonyolultabb, valós használatra készült programokban pedig el kell rejteni a kódolás részleteit
megfelelő osztályok használatával.

*Szövegfájl kódolásának megváltoztatása*:
  1. Megnyitás notepad++ segítségével, mentés a kívánt kódolással.
  2. CodeBlocks editorával: Edit->File encoding.
  3. Visual Studio: File -> Save as -> Save gombon megjelenő lefelé mutató nyíl megnyomásával a megfelelő kódolás kiválasztása. 
  4. [iconv](https://www.gnu.org/software/libiconv) konverter használata.
 