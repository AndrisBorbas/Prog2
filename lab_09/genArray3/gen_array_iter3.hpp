/**
 * \file gen_array_iter3.hpp
 *
 * Generikus tömb iterátorral v3.
 *  Előadáson bemutatott kód módosított változata.
 *  Interfész jobban hasonlít az std::vector-ra.
 *  Van konstans iterarora is.
 */
#ifndef GEN_ARRAY_ITER3
#define GEN_ARRAY_ITER3

#include <stdexcept>

 /**
  * Fix méretű generikus tömb.
  * @param T - tárolt adattípus
  * @param maxsiz - maximális méret
  */
template<class T, size_t maxsiz = 6>
class Array {
	size_t siz;				// adatok tényleges mennyisége
	T t[maxsiz];            // elemek (adatok) tömbje
public:
	/// minden implicit tagfüggvény jó, nem kell átdefiniálni
	class iterator;	        // elődeklaráció
	class const_iterator;	// elődeklaráció

	/// default és konstans értékkel feltöltő konstruktor
	/// @param n - méret
	/// @param value - érték, amivel feltölt
	explicit Array(size_t n = 0, const T& value = T()) : siz(0) {
		while (siz < n && siz < maxsiz)
			t[siz++] = value;
	}

	/// konstruktor sorozatból
	/// @param first - sorozat elejére mutat
	/// @param last - utolsó elem után
	template <class InputIterator>
	Array(InputIterator first, InputIterator last) : siz(0) {
		while (first != last && siz < maxsiz)	// átmásolunk, amíg lehet
			t[siz++] = *first++;
	}

	/// létrehoz egy iterátort és az elejére állítja
	/// @return - iterátor az adatsorozat elejére
	iterator begin() {
		return iterator(*this);		// ld. iterátor konstruktor
	}

	/// létrehoz egy iterátort és az utolsó elem után állítja
	/// @return - iterátor az adatsorozat végére
	iterator end() {
		return iterator(*this, siz);// ld. iterátor konstruktor
	}

	/// létrehoz egy konstans objektumra alkalmazható iterátort és az elejére állítja
	/// @return - iterátor az adatsorozat elejére
	const_iterator begin() const {
		return const_iterator(*this);// ld. iterátor konstruktor
	}

	/// létrehoz egy iterátort és az utolsó elem után állítja
	/// @return - iterátor az adatsorozat végére
	const_iterator end() const {
		return const_iterator(*this, siz);// ld. iterátor konstruktor
	}

	/// Elemek tényleges száma
	/// @return - ténylegesen tárolt elemek száma
	size_t size() const { return siz; }

	/// Tömb allokált (maximális) kapacitása
	/// @return - tömb allokált (maximális) kapacitása
	size_t capacity() const { return maxsiz; }

	/// Tömb allokált maximális kapacitása
	/// Mivel a tömb fix méretű így a max_size és a capacity megegyezik.
	/// @return - tömb maximális kapacitása
	size_t max_size() const { return maxsiz; }

	/// at
	/// @param i - index
	/// @return - i. elem referenciája, vagy out_of_range hiba
	T& at(size_t i) {
		if (i >= maxsiz) throw std::out_of_range("Array.at(): hibas index");
		if (i >= siz) siz = i + 1;    // növeljük a tényleges méretet
		return t[i];
	}
	/// at konstans változata.
	/// konstans esetén nem változhat a méret
	/// @param i - index
	/// @return i. elem referenciája, vagy out_of_range hiba
	const T& at(size_t i) const {
		if (i >= siz) throw std::out_of_range("Array.at(): hibas index");
		return t[i];
	}

	/// iterator osztály
	/// input/output (STL::ForwardIterator) iterátorként használható
	class iterator {
		Array *p;	// tároljuk, hogy melyik az objektumhoz tartozik az iterátor
		size_t idx;	// tároljuk az aktuális index értéket
	public:

		/// default konstruktor
		iterator() :p(0), idx(0) {}

		/// konstruktor, egy konkrét objektum ix-edik elemére mutat
		/// @param a - a konkrét objektum
		/// @param ix - ide állítja az indexet
		iterator(Array& a, size_t ix = 0)
			: p(&a),                // az objektumra mutat
			idx(ix) {}              // erre az elemre áll

		/// pre-inkremens
		/// csak hatékonyság miatt ref. visszatérésű,
		/// értelmetlen lenne balértékként használni
		iterator& operator++() {
			if (idx != p->siz) ++idx;   // nem engedjük túllépni
			return *this;
		}

		/// post-inkremens
		iterator operator++(int) {		// ezt kell elkészítenie
			iterator tmp = *this;  /// eltesszük a jelenlegi értéket
			operator++();
			return tmp;
		}

		/// egyenlőtlenség vizsgálat
		/// @param i - jobboldali operandus
		bool operator!=(const iterator &i) const {
			return(idx != i.idx);
		}

		/// egyenlőség vizsgálat
		/// @param i - jobboldali operandus
		bool operator==(const iterator &i) const {
			return !operator!=(i);
		}

		/// indirekció
		T& operator*() const {
			if (idx != p->siz) return p->t[idx];
			else throw std::runtime_error("Hibas indirekcio");
		}

		/// Szelekció pointerrel (nyíl). Címet kell, hogy adjon.
		T* operator->() const {
			return &operator*();
		}

	};  // iterator osztály vége

	/// const_iterator osztály.
	/// Visszavezetjük az iterator osztályra.
	/// A kompatibilitas miatt azonban a conts_itarator betehető egy itaratorba, így
	/// a kontans objektum adata is elérhetővé válik balértékként is.
	/// Privat öröklés jobb megoldás lenne, úgy azonban minden tagfüggvényt az ősből delegálni kell.
	class const_iterator : public iterator {
	public:
		/// default konstruktor
		const_iterator() {}

		/// konstruktor, egy konkrét objektum ix-edik elemére mutat
		/// @param a - a konkrét objektum
		/// @param ix - ide állítja az indexet
		const_iterator(const Array& a, size_t ix = 0)
			: iterator(const_cast<Array&>(a), ix) {}    /// Kis trükközés a kasztolással: Levesszük a
														/// konstans attribútumot, de nem fogjuk írni.

	   /// indirekció
		const T& operator*() const {                    /// Ezen keresztül biztosan nem fogjuk írni, de sajnos a kompatibilitás
			return iterator::operator*();               /// miatt egy const_itarator -> itarator konverzió nem kerül semmibe...
		}

		/// Szelekció pointerrel (nyil). Címet kell, hogy adjon.
		const T* operator->() const {
			return &operator*();
		}

	};

	/// Virtuális destruktor.
	/// Most nem használjuk, de egy generikus osztály későbbi
	/// felhasználási módja kevésbé látszik.
	virtual ~Array() {}
}; // generikus tömb vége

#endif
