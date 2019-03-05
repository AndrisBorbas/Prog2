#include <iostream>
#include <string>
#include <vector>

class Person {
   std::string vezeteknev;
   std::string keresztnev;

public:
   Person()
   {
      vezeteknev = std::string("a");
      keresztnev = std::string("bv8");
   }

   void kiir()
   {
      std::cout << vezeteknev << ' ' << keresztnev << std::endl;
   }

   std::string teljesNev()
   {
      //return vezeteknev.operator+(keresztnev);
      return vezeteknev + keresztnev
   }
};



int main()
{
   Person p;

   p.kiir();
}
