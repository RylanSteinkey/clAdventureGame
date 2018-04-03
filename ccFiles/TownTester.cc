#include <iostream>
#include "../headers/Town.h"
#include "../headers/Road.h"
#include "../headers/Map.h"

using namespace std;

int main()
{
   Player *a = new Player("Joshua");

   a->changeHealth(-15);

   a->changeGold(10);

   for(int i=0;i<10;i++)
      a->getInventory()->addItem(FactoryItem::createItem("Potion", 1));

   cout << endl;
   
   cout << "Your health is " << a->getHealth() << endl;

   for(int i = 0; i < 15; i++)
   {
      Town* town0 = new Town();
      town0->interface(a);
      delete town0;
      
      Town* town1 = new Town();
      town1->interface(a);
      delete town1;
      
      
   }
   
   
   delete a;
   return 0;
}
