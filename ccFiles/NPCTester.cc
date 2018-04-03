#include <iostream>
#include "../headers/NPC.h"
#include "../headers/Inventory.h"
#include "../headers/Player.h"

using namespace std;

int main()
{
   Player *a = new Player("Joshua");
   int i = 1;
   NPC *b = new NPC(i);
   cout << "NPC name --> " << b->getName() << endl;

   b->printInventory();
   delete a;
   delete b;
   return 0;
}
