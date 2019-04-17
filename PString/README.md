A korábban elkészített **String** és az előadáson bemutatott **Serializable** osztályok **felhasználásával** készítsen egy **PString** osztályt, ami **kompatibilis** a String osztállyal és pontosan ugyanúgy használható, mint a **String** osztály azzal a különbséggel, hogy példányai 
perzisztens viselkedésre is képesek. Azaz képesek egy adatfolyamra kiírni belső állapotukat és arról visszaolvasva visszaállítani azt. 
A **PString** osztály legyen kompatibilis a **Serializable** osztállyal is!

A **String** osztály teszteléséhez hasonló teszteseteket készítettünk *(pstring_test.cpp)*,
amiben feltételezzük, hogy létezik a következő két metódus:

*  void PString::write(std::ostream&) - a paraméterként kapott adatfolyamra kimenti a belső állapotát
*  void PString::read(std::istream&) - a paraméterként kapott adatfolyamról visszaállítja a belső állapotát

**Feladatok:**

- Töltse le az előkészített projektet:
[https://git.ik.bme.hu/Prog2/ell_feladat/PString](https://git.ik.bme.hu/Prog2/ell_feladat/PString)
- Készítse el a **PString** osztályt a *pstring.h* és az *pstring.cpp* állományokban! 
Ügyeljen arra, hogy a **PString** osztály példányai minden tesztesetben használhatóak legyenek, ahol a **String** osztály példányai használhatók! Öröklés esetén ezt a kompatibilitás garantálja, de ez nem biztos, hogy elegendő. Egyes műveletekben keletkező eredmény típusa ugyanis String, amit viszont át kell alakítani **PString** példánnyá. (Működnie kell a típuskonverziónak a *String* és a *Pstring* között mindkét irányban.)
- Tesztelje a megadott tesztprogrammal az új osztályt! Az egyes tesztek futása a korábban megismert **ELKESZULT** makró segítségével szabályozható. (Az új funkciók tesztjei a 12 -14 értéknél futnak.) **Érdemes 0 értékkel kezdeni**. Ezt követően már lehet bátran 14-re állítani!  
- Figyelje meg a 12. és 14. teszteset által kiírt memóriatartalmat (dump). Ez segíthet a hibakeresésben. 
5. Amennyiben a tesztek jól futnak, töltse fel a *JPorta* feladatbeadó rendszerbe az **pstring.h** és a **pstring.cpp** fájlokat!
