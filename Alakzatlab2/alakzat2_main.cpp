/**
 *  \file main.cpp
 *  Demó program az alakzat és rajztábla osztályok kipróbálására.
 *  Felrajzol pár alakzatot, majd elmozgatja kicsit.
 */

#include <iostream>
#include "szakasz.h"
#include "kor.h"
#include "teglalap.h"
#include "haromszog.h"
#include "poligon.h"
#include "rajztabla.h"

using std::cout;
using std::endl;

//#define MASOL

int main(int argc, char** argv) {

    Rajztabla tabla;
    tabla.felrak(new Szakasz(Pont(20,40), 100, 0, WHITE));
    tabla.felrak(new Kor(Pont(120,140), 50, BLUE));
    tabla.felrak(new Teglalap(Pont(20,40), Pont(60, 100), GREEN));
    tabla.felrak(new Haromszog(Pont(20,40), Pont(60, 100), Pont(50, 60), GREEN));
    Poligon* poli = new Poligon(Pont(120,140), GREEN);
    poli->add(Pont(120,200));
    poli->add(Pont(250,200));
    tabla.felrak(poli);

    cout << "Rajztabla rajzol:" << endl;
    tabla.rajzol();
    Pont delta(100, -10);
    cout << endl << "Rajztabla mozgat delta=" << delta << ":" << endl;
    tabla.mozgat(delta);
    cout << "\nRajztabla torol:" << endl;
    tabla.torol();
    tabla.felrak(new Kor(Pont(10,20), 50, RED));
    cout << endl << "Rajztabla rajzol:" << endl;
    tabla.rajzol();

#ifdef MASOL
    Rajztabla masik;
    masik = tabla;
    cout << endl << "Masik rajztabla rajzol:" << endl;
    masik.rajzol();
#endif
    return 0;
}
