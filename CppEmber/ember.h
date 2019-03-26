#pragma once
#include <cstring>

class Ember {
protected:
	int szulEv;
	char* nev;
public:
	Ember() :szulEv(1998) {
		szulEv = 1998;
		nev = new char[7];
		strcpy(nev, "F0PQGO");
	}
	Ember(const char*, int);
	Ember(const Ember&);
	virtual Ember& operator=(const Ember&);
	virtual const char* getNev() const;
	virtual int getKor(int) const;
	virtual const char* foglalkozas() const;
	virtual ~Ember();
};