/*�rjon C programot, amely a standard inputon �rkez� sz�veg sorait 
megsz�molja, �s megsz�molja azokat a sorokat is amelyekre az al�bbi 
(ld. 4. feladat) regul�ris kifejezes illeszkedik: 

  ^[^#]_*(0x)?[0-9]*W6.+[A-Z]+.*qqriq(A|a) 

A program az eredm�nyt k�t okt�lis sz�mk�nt �rja ki a standard outputra!
A k�t sz�mot / jellel v�lassza el, �s a sort sorv�gjellel z�rja le pl:
123/71 

A fenti regul�ris kifej�st �nnek kell �rtelmeznie �s nem kell �rtelmez� 
programot k�sz�tenie hozz�! Pl. a [A-Z]+ kifejez�shez olyan �llapotg�pet 
kell k�sz�tenie, ami felismeri a nagybet�kb�l �ll� sorozatot.*/

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