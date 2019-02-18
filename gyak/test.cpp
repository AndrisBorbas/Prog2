#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>

int atoi(const char *p, int base = 10)
{
   int i   = 0;
   int j   = 0;
   int num = 0;

   while (isspace(p[i]) == 0 || p[i] != '\0')
   {
      i++;
   }

   for (i; i >= 0; i--)
   {
      if (isdigit(p[i]) && p[i] < base)
      {
         num += p[i] * pow(10, j);
         j++;
      }
   }
   return num;
}

int main()
{
   char* p="124";
   std::cin>>p;
   //int x=atoi(p, 10);
   std::cout << p <</* x <<*/ '\n';
}
