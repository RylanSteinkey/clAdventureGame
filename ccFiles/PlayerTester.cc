#include <iostream>
#include "../headers/Player.h"
#include "../headers/Inventory.h"
#include "../headers/Bow.h"
#include "../headers/Staff.h"
#include "../headers/Potion.h"
#include "../headers/Armour.h"

using namespace std;

int main()
{
   Player *a = new Player("Joshua");
   Player b();
   cout << "Player " << a->getName() << "'s gold -> " << a->getGold() << endl;
   cout << "Player " << a->getName() << "'s attack -> " << a->getAttack() << endl;
    cout << "Player " << a->getName() << "'s defense -> " << a->getDefense() << endl;
   
   a->changeGold(50);
   a->changeAttack(20);
   a->changeDefense(25);

   cout << endl;

   
   cout << "Player " << a->getName() << "'s gold -> " << a->getGold() << endl;
   cout << "Player " << a->getName() << "'s attack -> " << a->getAttack() << endl;
   cout << "Player " << a->getName() << "'s defense -> " << a->getDefense() << endl;

   a->getInventory()->addItem(new Bow(a->getLevel()));
   a->getInventory()->addItem(new Staff(a->getLevel()));
   a->getInventory()->addItem(new Potion(a->getLevel()));

   a->printInventory();

   a->changeArmour(new Armour(a->getLevel()));
   a->changeWeapon(new Bow(a->getLevel()));

   cout << "Player " << a->getName() << "'s weapon is --> " << a->getWeapon()->getType() << endl;
   cout << "Player " << a->getName() << "'s armour is --> " << a->getArmour()->getType() << endl;

   delete a;
   return 0;
}
