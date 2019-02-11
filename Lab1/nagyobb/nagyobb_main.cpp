// Fájl: nagyobb_main.cpp
// Egyszerû demo program.
// Bekér két egész számot és kiírja a nagyobbat.

#include <iostream>
#include "fuggvenyeim.h"
using namespace std;

int main() {
	double an[] = { 3, 2, 1 }; // együtthatók: a0=3, a1=2, a3=1      
	double res[] = { 3, 6, 11, 18, 27, 38, 51 };
	int hibak = 0;
	for (int i = 0; i < 7; i++) {
		double fx = polinom(i, an, 2);
		if (res[i] != fx) {
			cout << "Hibas: " << res[i] << "!=" << fx << endl;
			hibak++;
		}
	}
	if (hibak == 0)
		cout << "Nem volt elteres" << endl;
}
