#include <iostream>
#include <stdlib.h>

//'O' 'X' ' '
typedef char tabla[3][3];

struct Pont
{
   int x;
   int y;
   Pont
}

class Player {
protected:
   char which;
public:
   Player(char c)
   {
      which = c;
   }

   virtual Pont lep(const tabla& table) = 0;
}

bool lepes_valid(const tabla& t, Pont& p)
{
   return t[p.x][p.y] == ' ' && p.x < 3 && p.y < 3 && p.x >= 0 && p.y >= 0;
}


class RandomPlayer : public Player {
public:
   RandomPlayer(char c) : Player(c)
   {
   }

   Pont lep(const tabla& table)
   {
      int x = rand() % 3;
      int y = rand() % 3;

      while (!lepes_valid(table, Pont(x, y)))
      {
         x = rand() % 3;
         y = rand() % 3;
      }
   }
}

class HumanPlayer : public Player {
public:
   HumanPlayer(char c) : Player(c)
   {
   }

   Pont lep(const tabla& table)
   {
      for (int i = 0; i < 3; i++)
      {
         for (int j = 0; j < 3; j++)
         {
            std::cout << table[i][j] << " ";
         }
         std::cout << std::endl;
      }
      int x, y;
      std::cin >> x >> " " >> y;
      while (!lepes_valid(table, Pont(x, y)))
      {
         std::cout<<"nemjo";
         std::cin >> x >> " " >> y;
      }
   }
}

int main(int argc, char const *argv[])
{
   /* code */
   return 0;
}
