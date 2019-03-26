Hallgatókból és kutatókból álló rendszert szeretnénk modellezni objektumokkal. 
Ehhez elkészítettük az alábbi objektummodellt:

![Osztálydiagram](https://jporta.iit.bme.hu/exercise/21/view/17/)

Közös alaposztályként az **Ember** osztályt választottuk, melynek a C++ nyelvű
deklarációját az *ember.h* fejlécállományba, a tagfüggvények definícióját pedig az *ember.cpp*
állományba tettük.

Ezután elkészítettük a **Hallgato** osztályt, majd a **Kutato** osztályt és egy
egyszerű tesztprogramot *emberMain.cpp*, amivel az osztályok alapvető működését ellenőriztük. 
Sajnos az *ember.h* fejlécállomány a munka során elveszett.

**Töltse le** a hiányos projektet a Git tárolóból:
[https://git.ik.bme.hu/Prog2/ell\_feladat/CppEmber](https://git.ik.bme.hu/Prog2/ell\_feladat/CppEmber)!
Elemezze *Hallgato* és *Kutato* osztályok deklarációit, majd ezek alapján **reprodukálja** az *ember.h* fejlécállományt! 
Ügyeljen arra, hogy az adattagok kívülről közvetlenül ne legyenek elérhetők, de a leszármazottak mégis elérhessék (protected).
A tagfüggvények némelyike lehet, hogy virtuális kell legyen! 

Az **Ember** osztály alapértelmezett konstruktora az **Ön Neptun-azonosítóját** állítsa be névként, születési évként 
pedig az **Ön születési évét**! 
Ha jól reprodukálja az *ember.h* állományt, akkor a főprogram a standard inputról kapott 
sorszámnak (1-4) megfelelő tesztesetet futtatja. Az első teszteset az Ön adatait írja ki:

>Nevem: KODKOD
>
>Korom: XX
>
>Foglalkozasom: Hallgato
>
>2020-ban YY eves leszek

Ahol KODKOD az Ön Neptun-azonosítója, XX pedig az Ön életkora ebben az évben. A második teszteset
Buta Toni nevű hallgató adatait írja ki, aki 1975-ben született. A harmadik teszteset Okos Toni
nevű hallgató adatait írja ki, aki 1970-ben született. Ez a teszteset azt is vizsgálja, hogy Okos
Toni hány éves volt 1900-ban. A 4. teszteset többek között Bjarne Stroustrup kutató adatait írja ki.

Megjegyzések:

1. Amennyiben nem az előkészített projektfájlt használja, úgy ügyeljen a **MEMTRACE** projektszintű definiálására!
2. Első lépésként értse meg a főprogram és az osztályok működését!
3. Készítse el az **ember.h** fejlécállományt és töltse fel a feladatbeadó rendszerbe! Csak ezt az állományt kell feltöltenie!
4. Ügyeljen arra, hogy ne legyen memóriaszivárgás!
