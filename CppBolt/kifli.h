#pragma once
#ifndef KIFLI_H
#define KIFLI_H

#include "aru.h"

 /// Tej osztály.
 /// spec attribútuma a tej fajtája, és szírtartalma
class Kifli :public Aru {  
	String spec;        ///< kifli fajtája
public:
	Kifli(double ar, const char *spec = "")
		:Aru("Kifli", "darab", ar), spec(spec) {}

	/// Attribútumok kiírása egy stream-re
	/// @param os - output stream referencia
	/// @return output stream referencia
	std::ostream& print(std::ostream& os) const {
		return os << megnevezes << " "
			<< spec << "; "
			<< ar << "Ft/" << egyseg;
	}
};

#endif // TEJ_H

