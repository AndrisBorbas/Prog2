#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>

char myid[] = "Borbas Andras <andris.borbas@gmail.com> F0PQGO\n";
char mytask[] = "Feladat=2 ISO 8859-2\n";

using namespace std;

double fn45(const double& x) {
	return (x / 107.40);
}

double fk45(const double& x) {
	return (0.419*pow(x, 4.0) - 0.838*pow(x, 3.0) + 53.62*pow(x, 2.0) + 13.0 * x - 45);
}

int main2() {
	setbuf(stdout, NULL);
	printf(myid);
	printf(mytask);
	double x;
	while ((cin >> x) || !EOF) {
		if (x > 45.0)cout << fixed << setprecision(4) << fn45(x) << endl;
		else cout << fixed << setprecision(4) << fk45(x) << endl;
	}
	return(0);
}