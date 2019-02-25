/*Írjon C programot, amely a standard inputon érkezõ szöveg sorait 
megszámolja, és megszámolja azokat a sorokat is amelyekre az alábbi 
(ld. 4. feladat) reguláris kifejezes illeszkedik: 

  ^[^#]_*(0x)?[0-9]*W6.+[A-Z]+.*qqriq(A|a) 

A program az eredményt két oktális számként írja ki a standard outputra!
A két számot / jellel válassza el, és a sort sorvégjellel zárja le pl:
123/71 

A fenti reguláris kifejést Önnek kell értelmeznie és nem kell értelmezõ 
programot készítenie hozzá! Pl. a [A-Z]+ kifejezéshez olyan állapotgépet 
kell készítenie, ami felismeri a nagybetûkbõl álló sorozatot.*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <iomanip>

char myid[] = "Borbas Andras <andris.borbas@gmail.com> F0PQGO\n";
char mytask[] = "Feladat=6 ISO 8859-2\n";

using namespace std;

int main() {
	setbuf(stdout, NULL);
	printf(myid);
	printf(mytask);



	return 0;
}