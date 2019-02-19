#ifndef _MAX_HPP
#define _MAX_HPP
/**
 * file max.hpp
 * (UTF-8 kodolasu fajl. Allitsa at a megjenetes kodolasat,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 *
 * A C++ nem OO b�v�t�seinek gyakorl�s�hoz.
 *
 *
 * FELADATOK:
 *  2. Val�s�tson meg EBBEN a f�jlban, a Sajat n�vt�ren bel�l egy olyan sablont, ami
 *     alapt�pusok eset�n a param�terk�nt kapott �rt�k k�z�l a nagyobbat adja.
 *  3. Specializ�lja a sablont a nem_oo.h �llom�nyban deklar�lt Komplex t�pusra
 *     �gy hogy a nagyobb abszol�t �rt�k� Komplex sz�mot adja vissza!
 *
 * �gyeljen a helyes n�vt�r haszn�latra!
 *   Tipp: Haszn�lja a scope oper�tort, vagy nyisson n�vteret!
 */

#include "nem_oo.h"

namespace sajat {
	template <typename T>
	T max(T x, T y)
	{
		return (x > y) ? x : y;
	}
	Komplex max(const Komplex& x, const Komplex& y)
	{
		return (absKomplex(x) > absKomplex(y)) ? x : y;
	}
}
#endif // _MAX_HPP