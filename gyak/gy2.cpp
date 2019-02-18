#include <iostream>

struct Verem
{
   double *adat;
   int    db, kapacitas;
};

void verem_init(Verem& v)
{
   v.kapacitas = 1;
   v.adat      = new double[v.kapacitas];
   v.db        = 0;
}


void verem_free(Verem& v)
{
   delete[] v.adat;
}


void verem_berak(Verem& v, double mit)
{
   if (v.db == v.kapacitas)
   {
      v.kapacitas *= 2;
      double *uj = new double[v.kapacitas];
      for (int i = 0; i < v.db; i++)
      {
         uj[i] = v.adat[i];
      }
      delete[] v.adat;
      v.adat = uj;
   }
   v.adat[v.db] = mit;
   v.db++;
}


double verem_kivesz(Verem& v)
{
   return v.adat[((v.db)--)];
   //v.db--;
}


void verem_masol(Verem& v, Verem& masik)
{
   v.db        = masik.db;
   v.kapacitas = masik.kapacitas;
   double *uj = new double[masik.kapacitas];
   for (int i = 0; i < v.db; i++)
   {
      v.adat[i] = masik.adat[i];
   }
   v.adat = uj;
}


void verem_ertekad(Verem& v, Verem& masik)
{
   verem_free(v);
   verem_masol(v, masik);
}


void verem_kiir(Verem& v)
{
   for (int i = 0; i < v.db; i++)
   {
      std::cout << v.adat[i] << " ";
   }
   std::cout << '\n';
}


int main()
{
   Verem v1, v2, v3;

   verem_init(v1);
   verem_init(v2);
   verem_berak(v1, 5.2);
   verem_berak(v1, 5.3);
   verem_kiir(v1);
   verem_kivesz(v1);
   verem_kiir(v1);
}
