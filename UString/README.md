A korábban elkészített **String** osztály **felhasználásával** készítsen egy **UString** osztályt, ami **kompatibilis** a String osztállyal és pontosan ugyanúgy használható, mint a **String** osztály azzal a különbséggel, hogy példányai képesek "varázsütésre" nagybetűsítve kiírni! Azaz legyen az osztálynak egy olyan metódusa (*UCase()*) amivel szabályozható, hogy az **inserter** operator (operator<<) az objektumokban tárolt formátumban, vagy nagybetűsítve írjon a stream-re!

A **String** osztály teszteléséhez a korábbi tesztesetekhez hasonló teszteseteket készítettünk *(ustring_test.cpp)*. Ebben feltételezzük, hogy létezik a következő két metódus:

*  void UString::UCase(bool) - be- illetve kikapcsolja a nagybetűs kiírást 
*  bool UString::UCase() - visszaadja a kiírást vezérlő kapcsoló állapotát

**Feladatok:**

1. Töltse le az előkészített projektet:
[https://git.ik.bme.hu/Prog2/ell_feladat/UString](https://git.ik.bme.hu/Prog2/ell_feladat/UString)
2. Készítse el az **UString** osztályt az *ustring.h* és az *ustring.cpp* állományokban! 
Ügyeljen arra, hogy az **UString** osztály példányai minden testesetben használhatóak legyenek, ahol a **String** osztály példányai használhatók! Öröklés esetén ezt a kompatibilitás garantálja, de ez nem biztos, hogy elegendő. Egyes műveletekben keletkező eredmény típusa ugyanis String, amit viszont át kell alakítani **UString** példánnyá. (Működnie kell a típuskonverziónak a *String* és *Ustring* között mindkét irányban.)
3. Tesztelje a megadott tesztprogrammal az új osztályt! Az egyes tesztek futása a korábban megismert **ELKESZULT** makró segítségével szabályozható. (Az új funkciók tesztjei a 12 és 13 értéknél futnak. **Érdemes 0 értékkel kezdeni**, majd egyesével növelve tesztelni!  
4. Amennyiben a tesztek jól futnak, töltse fel a *JPorta* feladatbeadó rendszerbe az **ustring.h** és a **ustring.cpp** fájlokat!
