// Fájl: fuggvenyeim.cpp
// Ebben valósítom meg a gyakran használt függvényeket.

#include "fuggvenyeim.h"

// Két int adat felcserélése
void csere(int& a, int& b) {
   int tmp =  a;
   a =  b;
   b = tmp;
}
// ....
double polinom(const double& x, const double * egyutthatok, const int& fokszam) {
	double ertek = 0;
	for (int i = fokszam; i > 0; i--) {
		ertek += egyutthatok[i];
		ertek *= x;
	}
	ertek += egyutthatok[0];
	return ertek;
}