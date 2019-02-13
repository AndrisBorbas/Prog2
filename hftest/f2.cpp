#include <iostream>
#include <iomanip>

char myid[] = "Borbas Andras <andris.borbas@gmail.com> F0PQGO\n";
char mytask[] = "Feladat=2 ISO 8859-2\n";

using namespace std;

double fn45(const double& x) {
	return (x / 107.40);
}

double fk45(const double& x) {
	return (0.419*pow(x, 4) - 0.838*pow(x, 3) + 53.62*pow(x, 2) + 13 * x - 45);
}

int main() {
	double x;
	cin >> x;
	if (x > 45)cout << setprecision(4) << fn45(x);
	else cout << setprecision(4) << fk45(x);
	return(0);
}