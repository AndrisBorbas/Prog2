#include "vektor.h"

size_t Vektor::defSize = 8;
double Vektor::defValue = 18;

/// M�sol� konstruktor. K�sz�tse el a vektor.cpp f�jlban!
Vektor::Vektor(const Vektor& o) :nElements(o.size()) {
	pVec = new double[nElements];
	for (size_t i = 0; i < nElements; i++){
		pVec[i] = o.pVec[i];
	}
}

/// Destruktor. K�sz�tse el a vektor.cpp f�jlban!
Vektor::~Vektor() {
	delete[] pVec;
}

/// �rt�kad� oper�tor. K�sz�tse el a vektor.cpp f�jlban!
Vektor& Vektor::operator=(const Vektor& rhs) {
	if (this != &rhs) {
		delete[] this->pVec;
		this->nElements = rhs.nElements;
		this->pVec = new double[this->nElements];
		for (size_t i = 0; i < this->nElements; i++) {
			this->pVec[i] = rhs.pVec[i];
		}
	}
	return *this;
}

/// Indexoper�torok. K�sz�tse el a vektor.cpp f�jlban!
/// T�lc�mz�s eset�n az �n Neptun-k�dj�t tartalmaz� const char* t�pus� kiv�telt dob!
/// @param idx - index �rt�ke
/// @return    - referencia az adott elemre
double& Vektor::operator[](size_t idx) {
	if (idx >= this->nElements) {
		throw "F0PQGO";
	}
	else {
		return (this->pVec[idx]);
	}
}
const double& Vektor::operator[](size_t idx) const {
	if (idx >= this->nElements) {
		throw "F0PQGO";
	}
	else {
		return (this->pVec[idx]);
	}
}

/// Szorz�s: Val�s * Vektor. K�sz�tse el a vektor.cpp f�jlban!
/// @param val - val�s �rt�k (bal oldali operandus)
/// @param vec - vektor, aminek minden elem�t megszorozzuk (jobb oldali operandus)
Vektor operator*(double val, const Vektor& vec) {
	Vektor n=vec;
	for (size_t i = 0; i < vec.size(); i++) {
		n[i] = vec[i] * val;
	}
	return n;
}