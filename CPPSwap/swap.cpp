#include "swap.h"

void swap(bool& a, bool& b) {
	bool tmp = b;
	b = a;
	a = tmp;
}

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
	const char* tmp = b;
	b = a;
	a = tmp;
}