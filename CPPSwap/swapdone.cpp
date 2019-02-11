/**
 * \file swap.cpp
 * (Latin-2 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 */
#include "swap.h"

template<typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}


void *p = (void*)swap<bool>;

void swap(int& a, int& b) {
	int tmp = b;
	b = a;
	a = tmp;
}

void swap(char& a, char& b) {
	char tmp = b;
	b = a;
	a = tmp;
}

void swap(double& a, double& b) {
	double tmp = b;
	b = a;
	a = tmp;

}

void swap(const char*& a, const char*& b) {
	const char *& tmp = b;
	b = a;
	a = tmp;
}
