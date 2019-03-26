Egy bolt **pénztárgépét** szeretnénk modellezni. A pénztáros megadja az eladott mennyiséget és az **árut**.
A gép nyilvántartást vezet az **eladásokról**. Nyilván kell tartani az eladás *dátumát*, eladott áru *mennyiségét*,
*értékét*, *egységárát*, és *minden jellemzőjét*. A nyilvántartásból lekérdezhető az összes eladás adata,
ami szűrhető egy adott napra is. Lekérdezhető továbbá egy adott nap árbevétele. OO tervezési mintát 
követve meghatároztuk a 

**szereplőket:**

-  **Kassza** - a pénztárgép (tároló jellegű valami) 
-  **Tetel** - eladáskor keletkező pénztári bejegyzés (ez tárolja az eladás adatait) 
-  **Aru** - bolt által forgalmazott áruk
 
Miután számtalan áru (Aru) lehet, melynek a jellemzői előre nem ismertek, olyan megoldást 
kell választani, ami könnyen bővíthető tetszőleges áruval. Heterogén kollekció alkalmazása mellett 
döntöttünk. Ennek tipikus mintája, hogy a tárolóban valamilyen alaposztályra mutató pointert tárolunk
(ld. előadás eseménynapló). Ez viszont azt jelentené, hogy ebben az alaposztályban kellene tárolni 
az eladás adatait, és ebből kellene származtatni az árukat. Az áruknak azonban semmi köze az eladási 
adatokhoz, ezért zavaró lenne ebből származtatni azokat. A probléma feloldásához bevezettünk egy 
közbenső osztályt (Tetel), amit a pénztárgépben (Kassza) tárolunk, és ez hivatkozik az áruk alaposztályára.

Elkészítettük a vázolt megoldás objektummodelljét:

![Osztálydiagram](https://git.ik.bme.hu/Prog2/ell_feladat/CppBolt/raw/master/cppbolt.png)

Ezt követően elkészítettük a modell C++ megvalósítását és egy egyszerű tesztprogramot (boltMain)
A DoxyGen program segítségével pedig legeneráltuk a megoldás 
[dokumentációját is.](https://git.ik.bme.hu/Prog2/ell_feladat/CppBolt/blob/master/doxygen/rtf/refman_mod.pdf)
Nem minden osztályt és funkciót valósítottunk meg hiánytalanul. Ennek pótlása az Ön feladata.

**Feladatok:**

1. Töltse le az előkészített projektet a Git tárolóból! [https://git.ik.bme.hu/Prog2/ell_feladat/CppBolt](https://git.ik.bme.hu/Prog2/ell_feladat/CppBolt)
2. Adja hozzá a projekthez az 5. hét laborgyakorlatán kötelező feladatként elkészített *String* osztályt (*string5.h*, *string5.cpp*)! 
A projektfájlokat is módosítania kell, mert nem tettük bele a string5.\* fájlokat!
3. Fordítsa le és futtassa a programot! Hibás működést fog tapasztalni, mert nincs minden funkció pontosan megvalósítva.  
4. Módosítsa a **kassza.cpp** fájlt, hogy az *elad()* tagfüggvény dobjon kivételt, amikor a tároló megtelik.
5. Egészítse ki a *list(std::ostream&, const Datum&)*, valamint a *napiOsszeg(const Datum&)* függvényeket, hogy azok az elvárásoknak megfelelően  működjenek!
6. Futtassa, tesztelje a programot.
7. Készítse el **Kifli** osztályt a *kifli.h* fájlban és adja hozzá a projekthez!
8. Definiálja projekt szinten a **KIFLI\_IS\_VAN** makrót, fordítson és futtasson!
9. Amennyiben a tesztek nem mutatnak hibát, töltse fel a *JPorta* feladatbeadó rendszerbe a **kifli.h** és a **kassza.cpp** fájlokat! 

**Megjegzések:**

1. A feladat leírása hosszú, de a megoldás meglehetősen egyszerű. 
2. A fenti osztálydiagramon helytakarékosság végett a *const* minősítőket nem jelöltük.
3. A DoxyGen programmal generált UML ábrák nem mindenben felelnek meg az UML jelölési rendszerének, illetve helyenként hiányosak. 