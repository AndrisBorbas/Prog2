// F�jl: fuggvenyeim.cpp
// Ebben tal�lhat�k a f�ggv�nyek protot�pusai,
// t�pusok, konstansok, egy�b deklar�ci�k

#ifndef FUGGVENYEIM_H
#define FUGGVENYEIM_H
/*
 * csere
 * K�t int adat felcser�l�se
 * @param a - egyik adat
 * @param b - m�sik adat
 */
void csere(int& a, int& b);


double polinom(const double& x, const double * egyutthatok, const int& fokszam);
/*
 * max
 * K�t int adat k�z�l a nagyobb
 * @param a - egyik adat
 * @param b - m�sik adat
 */
// Ez egy inline f�ggv�ny, amit minden ford�t�si
// egys�gben defini�lni kell.
inline int max(int a, int b) { return a > b ? a : b; }

#endif // FUGGVENYEIM_H
