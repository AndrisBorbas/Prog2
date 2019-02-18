#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>


/**
 * \file nem_oo_teszt.cpp
 * (UTF-8 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * FELADATOK:
 *  1. Ebben a fájlban valósítsa meg a nem_oo.h állományban deklarált függvényeket!
 *
 * Ügyeljen a helyes névtér használatra!
 *   Tipp: Használja a scope operátort, vagy nyisson névteret!
 */

const char* neptunerror = "F0PQGO";


/**
 * Saját atoi.
 * Számjegyeket tartalmazó karaktersorozat átalakítása int-re.
 * Helyes számjegysorozat végét white space, vagy sztring vége ('\0') jelzi.
 *   Ha a számjegysorozatban olyan számjegy, vagy betű fordul elő,
 *   ami nem érvényes az adott számrendszerben, az hiba.
 *   Pl. hármas számrendszerben nem fordulhat elő a 3-as számjegy, de az A betű sem.
 * Hiba esetén egy const char* típusú kivételt kell dobni, melynek értéke
 * az Ön neptun azonosítója!
 * @param p    - pointer a sztringre
 * @param base - számrendszer alapja (0-10)
 * @return     - base számrendszerben értelmezett szám
 */
int atoi(const char *p, int base = 10)
{
	int i = 0;
	int j = 0;
	int num = 0;
	int n = 0;

	while (isspace(p[i]) == 0 && p[i] != '\0')
	{
		i++;
	}
	i--;
	for (i; i >= 0; i--) {

		if (isdigit(p[i])) {
			n = p[i] - 48;
			if (n < base) {
				num += n * pow(base, j);
				j++;
				continue;
			}
		}
		throw neptunerror;
	}
	return num;
}

char *strcatt(const char *p1, const char *p2) {
	char *pc = new char[strlen(p1) + strlen(p2) + 1];
	unsigned int i = 0;
	for (i; i < strlen(p1); i++) {
		pc[i] = p1[i];
	}
	for (i; i < (strlen(p2) + strlen(p1)); i++) {
		pc[i] = p2[i - strlen(p1)];
	}
	pc[i] = '\0';
	return pc;
}

char *unique(char *first, char *last) {
	int fnd = 0;
	int lnd = 1;
	int j = 0;
	for (int i = 0; i >= 0; i++) {
		if (first[fnd] != first[lnd]) {
			fnd++;
			//j = 0;
			//first++;
		}
		else {
			while (first[fnd] == first[lnd]) {
				lnd++;
			}
			first[fnd + 1] = first[lnd];
			//lnd = fnd + j;
			fnd++;
		}
		if (first + fnd + 1 == last)break;
	}
	return (first + fnd + 1 + 1);
	//return first;
}

int main() {
	char *p = new char[10];
	char *p2 = new char[10];
	std::cin >> p >> p2;
	std::cout << std::endl << p << std::endl << p2 << std::endl;

	/*int s = atoi(p, 8);
	std::cout << s;*/

	char *p3 = strcatt(p, p2);
	std::cout << std::endl << p3 << std::endl;
	p3 = unique(p3, p3 + strlen(p3));
	std::cout << p3 << std::endl;
}