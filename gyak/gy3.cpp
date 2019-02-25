#include <iostream>

class Idopont {
   int percek;
public:
   Idopont() { percek = 0; }
   Idopont(int ora = 0, int perc = 0)
   {
      percek = ora * 60 + perc;
      if (percek < 0)
      {
         this->percek += 24 * 60;
      }
   }

   int get_ora() const { return percek / 60; }
   int get_perc() const { return percek % 60; }

   bool operator==(const Idopont& i) { return this->percek == i.percek; }
   bool operator!=(const Idopont& i) { return !(*this == i); }

   Idopont operator+(const Idopont& i) const
   {
      return Idopont(0, this->percek + i.percek);
   }

   Idopont operator+(int percek) const
   {
      return Idopont(0, this->percek + percek);
   }

   Idopont operator-(const Idopont& i) const
   {
      return Idopont(0, this->percek - i.percek);
   }

   Idopont operator-(int percek) const
   {
      return Idopont(0, this->percek - percek);
   }

   void operator+=(int perc)
   {
      *this = *this + perc;
   }

   void operator-=(int perc)
   {
      *this = *this - perc;
   }
};

std::ostream& operator<<(std::ostream& os, const Idopont& ido)
{
   os << ido.get_ora() << ":" << ido.get_perc();
   return os;
}


std::istream& operator>>(std::istream& is, Idopont& ido)
{
   int  ora, perc;
   char c;

   is >> ora >> c >> perc;
   Idopont i(ora, perc);
   ido = i;
   return is;
}


int main()
{
   Idopont idopont(13, 37);
   std::cout << idopont << '\n';
   std::cout << idopont.get_ora() << ":" << idopont.get_perc() << std::endl;
}
