#ifndef STRING_H
#define STRING_H
/**
 * \file string2_kesz.h
 *
 * Ez a fĂĄjl tartalmazza a
 *   - String osztĂĄly deklarĂĄciĂłjĂĄt
 *   - az inline fĂźggvĂŠnyeket. Ha valamit inline-kĂŠnt akar megvalĂłsĂ­tani,
 *     akkor azt ebbe a fĂĄjlba Ă­rja! Tipikusan a rĂśvid kĂłdokat szokĂĄs
 *     inline-kĂŠt megvalĂłsĂ­tani (pl: c_str).
 *     MĂĄs fĂźggvĂŠnyeket ill. definĂ­ciĂłkat ne Ă­rjon a .h fĂĄjlba!
 *
 * A C-ben megĂ­rt (string1.c) fĂźggvĂŠnyek most tagfĂźggvĂŠnyekkĂŠ vĂĄltak, ĂŠs
 *   eltĹąnt az elsĹ paramĂŠterĂźk (s0) (ebbĹl lett a this).
 * A nevĂźk is megvĂĄltozott, mert most mĂĄr az ĂśsszetartozĂĄst, ĂŠs a
 *   paramĂŠterek tĂ­pusĂĄra valĂł utalĂĄst mĂĄr nem a nĂŠv hordozza, hanem az osztĂĄly.
 * A createString... alakĂş fĂźggvĂŠnyekbĹl konstruktorok keletkeztek.
 * A disposeString destruktorrĂĄ alakĂźlt ĂĄt.
 * Egyes mĹąveletvĂŠgzĹ fĂźggvĂŠnyekbĹl pedig operĂĄtor fĂźggvĂŠny lett.
 */

 /**
  * Az Ăn feladata a string2.cpp fĂĄjlban megvalĂłsĂ­tani (definiĂĄlni) az egyes
  * fĂźggvĂŠnyeket.
  *
  * Ahogyan halad a megvalĂłsĂ­tĂĄssal egyre tĂśbb tesztesetet kell lefuttatni,
  * ezĂŠrt az ELKESZULT makrĂł ĂŠrtĂŠket folyamatosan nĂśvelje a feladatsorszĂĄmoknak
  * megfelelĹen!
  *
  * TanulsĂĄgos a megvalĂłsĂ­tĂĄs elĹtt mĂĄr a megnĂśvelt ĂŠrtĂŠkkel is lefordĂ­tani
  * a programot, ĂŠs elemezni a kapott hibajelzĂŠst.
  *
  */

#define ELKESZULT 13

  /**
   * \section fel Feladat:
   * A tantermi gyakorlatokon, valamint a 3. laborgyakorlaton is foglalkoztunk egy
   * olyan sztring (String) adatszerkezet ĂŠs a rajta mĹąveleteket vĂŠgzĹ fĂźggvĂŠnyek
   * megtervezĂŠsĂŠvel/impelmentĂĄlĂĄsĂĄval ami dinamikusan tĂĄrol ĂŠs annyi memĂłriĂĄt foglal
   * amennyi a tĂĄrolĂĄshoz szĂźksĂŠges.
   *
   * Ezeket ĂŠs a tanultakat felhasznĂĄlva a string2.h ĂŠs a string2.cpp ĂĄllomĂĄnyokban
   * definiĂĄljon ill. implementĂĄljon egy olyan sztring (String) osztĂĄlyt C++ nyelven, ami
   * dinamikusan tĂĄrol ĂŠs rendelkezik az alĂĄbbi tulajosnĂĄgokkal!
   *
   *  1  A paramĂŠter nĂŠlkĂźl hĂ­vhatĂł konstruktora Ăźres sztringet hozzon ĂŠtre!
   *  2. Van olyan tagfĂźggvĂŠnye ( c_str() ), ami C-sztringgel, azaz nullĂĄval lezĂĄrt
   *     karaktersorozatra mutatĂł pointerel (const char *) tĂŠr vissza.
   *  3. Van olyan konstruktora, ami karakterbĹl hoz lĂŠtre sztringet.
   *  4. Van olyan konstruktora, ami C-sztringbĹl (const char*) hoz lĂŠtre sztringet.
   *  5. Az osztĂĄlybĂłl lĂŠtrehozott objektum legyen ĂĄtadhatĂł ĂŠrtĂŠkkparamĂŠterkĂŠnt!
   *  6. TĂĄmogassa a tĂśbbszĂśrĂśs ĂŠrtĂŠkadĂĄst (b = a = a)!
   *  7  Legyenek olyan operĂĄrorai (operator+), amivel a sztring vĂŠgĂŠhez sztringet,
   *     ĂŠs karaktert lehet fĹązni!
   *  8. Lehessen karakterhez is sztringet fĹązni a + operĂĄtorral!
   *  9. A tĂĄrolt a karakterek legyenek elĂŠrhetĹek a szokĂĄsos mĂłdon indexelĂŠssel!
   *     Az indexelĂŠssel elĂŠr elem legyen hasznĂĄlhatĂł balĂŠrtĂŠkkĂŠnt is!
   *     A konstans objektumok is legyenek indexelhetĹk.
   *     Az indexelĂŠs operĂĄtor hiba esetĂŠn dobjon const char * kivĂŠtelt!
   * 10. KĂŠszĂ­tsen olyan << operĂĄtort, amivel egy sztring kiĂ­rhatĂł egy ostream tĂ­pusĂş
   *     objektumra!
   *
   * Szorgalmi feladatok:
   * 11. KĂŠszĂ­tsen olyan fĹązhetĹ >> operĂĄtort, amivel be tud olvasni egy szĂłt egy sztring-be!
   *     A beolvasĂł mĹąkĂśdjĂśn Ăşgy, mint a scanf %s, azaz a szĂł vĂŠgĂŠt white space hatĂĄrolja!
   *     A szĂł eleji white space karaktereket pedig el kell dobni.
   *    *Megj: az istream wshite space kezelĂŠse a flags() tagfĂźggvĂŠnnyel szabĂĄlyozhatĂł
   * 12. PrĂłbĂĄlja ki az ĂŠkezetes karakterek rendezĂŠsĂŠt is! Ehhez elkĂŠszĂ­tettĂźnk egy
   *     egyszerĹą kĂłdrĂŠszletet ami qsort() fĂźggvĂŠnyt hasznĂĄl.
   *     Ărtse meg a rendez.cpp fĂĄjlban levĹ kĂłd mĹąkĂśdĂŠsĂŠt ĂŠs futtassa a programot!
   * 13. A setlocale fĂźggvĂŠnyhĂ­vĂĄs beĂĄllĂ­tja a karakterek ĂŠs sztringek ĂśsszehasonlĂ­tĂĄsĂĄhoz
   *     szĂźksĂŠges nyelvi kĂśrnyezetet (LC_COLLATE) prĂłbĂĄlja ki! VĂĄltozott a rendezĂŠsi
   *     sorrend?
   */

#include <iostream>
   /**
	* Header fĂĄjlokbĂłl megfontoltan kell include-ot hasznĂĄlni.
	* NĂŠvteret azonban nem cĂŠlszerĹą kinyitni, mert annak hatĂĄsa zavarĂł lehet
	* ott ahol ez a header include-olva lesz.
	*/

#ifndef MEMTRACE
#error "definialja projekt szinten a MEMTARCE makrot!"
#endif // MEMTRACE

	/**
	 * A String osztĂĄly.
	 * A 'pData'-ban vannak a karakterek (a lezĂĄrĂł nullĂĄval egyĂźtt), 'len' a hossza.
	 * A hosszba nem szĂĄmĂ­t bele a lezĂĄrĂł nulla.
	 */
class String {
	char *pData;         /// pointer az adatra
	size_t len;    /// hossz lezĂĄrĂł nulla nĂŠlkĂźl
public:
	/// Az elsĹ kĂŠt feladatot elĹre megoldottuk, de lehet, hogy nem jĂłl.
	/// Az Ăźres string reprezentĂĄciĂłja nem szerencsĂŠs, mert Ă­gy NULL pointerrĂŠ
	/// konvertĂĄl a c_str(), ami kĂźlĂśn kezelĂŠst igĂŠnyel a kĂŠsĹbbiekben, Ă­gy
	/// a teszt program sem fogadja el.
	/// Gondolja vĂŠgig, ĂŠs vĂĄltoztassa meg!
	/// KĂŠt lehetĹsĂŠg van:
	///     a) nem NULL pointert tĂĄrol, hanem tĂŠynlegesen Ăźres sringet.
	///     b) a c_str() Ăźres stringet ad vissza
	/// BĂĄrmelyik jĂł, mert ez az osztĂĄly belĂźgye.

	size_t size() const { return len; }


	/// Default konstruktor:
	String() :pData(0), len(0) {}

	/// C-stringet ad vissza
	const char* c_str() const { if (pData) return pData; else return ""; }

	/// Konstruktor: egy char karakterbĹl (createStrFromChar)
	String(char ch);

	/// Konstruktor: egy nullĂĄval lezĂĄrt char sorozatbĂłl (createStringFromCharStr)
	String(const char *p);

	/// MĂSOLĂ konstruktor, ami a createStringFromString-bĹl keletkezett
	/// @param s1 - String, amibĹl lĂŠtrehozzuk az Ăşj String-et
	String(const String& s1);

	/// Destruktor (disposeString)
	~String() { delete[] pData; }

	/// EgyĂŠb tagfĂźggvĂŠnyek:
	  /// KiĂ­runk egy Stringet (debug cĂŠlokra) (ez kĂŠsz)
	  /// ElĂśtte kiĂ­runk egy tetszĹleges szĂśveget.
	  /// @param txt - nullĂĄval lezĂĄrt szĂśvegre mutatĂł pointer
	void printDbg(const char *txt = "") const {
		std::cout << txt << "[" << len << "], "
			<< (pData ? pData : "(NULL)") << std::endl;
	}

	/// OperĂĄtorok:
	  /// ĂrtĂŠkadĂł operĂĄtor is kell !
	  /// @param rhs_s - jobboldali String
	  /// @return baoldali (mĂłdosĂ­tott) string (referenciĂĄja)
	String& operator=(const String& rhs_s);

	String& operator+=(const String& rhs_s) {
		*this = *this + rhs_s;
		return *this;
	}

	/// KĂŠt Stringet ĂśsszefĹąz (concatString)
	/// @param rhs_s - jobboldali String
	/// @return Ăşj String, ami tartalmazza a kĂŠt stringet egmĂĄs utĂĄn
	String operator+(const String& rhs_s) const;

	/// Sztrinhez karaktert ĂśsszefĹąz (concatString)
	/// @param rhs_c - jobboldali karakter
	/// @return Ăşj String, ami tartalmazza a kĂŠt sztringet egymĂĄs utĂĄn
	String operator+(char rhs_c) const { return *this + String(rhs_c); }

	/// A string egy megadott indexĹą elemĂŠnek REFERENCIĂJĂVAL tĂŠr vissza.
	/// charAtString-bĹl keletkezett, de ezt bal oldalon is lehet hasznĂĄlni
	/// @param idx - charakter indexe
	/// @return karakter (referencia)
	///         IndexelĂŠsi hiba esetĂŠn const char* kivĂŠtelt dob (assert helyett).
	char& operator[](unsigned int idx);

	/// A string egy megadott indexĹą elemĂŠnek REFERENCIĂJĂVAL tĂŠr vissza.
	/// charAtString-bĹl keletkezett. Konstans stringre alkalmazhatĂł.
	/// IndexelĂŠsi hiba esetĂŠn const char* kivĂŠtelt dob (assert helyett).
	/// @param idx - karakter indexe
	/// @return karakter (referencia)
	///         IndexelĂŠsi hiba esetĂŠn const char* kivĂŠtelt dob (assert helyett).
	const char& operator[](unsigned int idx) const;

	void erase() { *this = ""; }
};

/// GlobĂĄlis fĂźggvĂŠnyek:
/// kiĂ­r az ostream-re (printString)
/// Nem cĂŠlszerĹą using-ot hasznĂĄlni, mert ez egy include file. Ăgy ki kell Ă­rni az std::-t
/// @param os - ostream tĂ­pusĂş objektum
/// @param s0 - String, amit kiĂ­runk
/// @return os
/// VigyĂĄzat nem tagfĂźggvĂŠny! Nem is tĹąnik el az s0 !
/// Nem kell, hogy barĂĄt legyen, mert a c_str() segĂ­t
std::ostream& operator<<(std::ostream& os, const String& s0);

/// Beolvas az istream-rĹl egy szĂłt egy string-be.
/// @param is - istream tĂ­pusĂş objektum
/// @param s0 - String, amibe beolvas
/// @return is
/// VigyĂĄzat nem tagfĂźggvĂŠny! Nem is tĹąnik el az s0 !
/// Nem kell, hogy barĂĄt legyen mert van Str + ch
std::istream& operator>>(std::istream& is, String& s0);

/// String operator+(char ch, const String& str);
/// Vagy inline, vagy nem itt a helye!
/// Nem kell, hogy barĂĄt legyen mert tudunk chr-bĹl str-be konvertĂĄlni
/// kĂŠt str pedig ĂśsszeadhatĂł
inline String operator+(char ch, const String& str) { return String(ch) + str; }

#endif
