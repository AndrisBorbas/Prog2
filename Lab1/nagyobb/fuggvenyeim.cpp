// F�jl: fuggvenyeim.cpp
// Ebben val�s�tom meg a gyakran haszn�lt f�ggv�nyeket.

#include "fuggvenyeim.h"

// K�t int adat felcser�l�se
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