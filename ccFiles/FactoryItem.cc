///Implementation for the item factory pattern class
///\author Rylan Steinkey
///\date Nov 21, 2017
#include "../headers/Weapon.h"
#include "../headers/Armour.h"
#include "../headers/Potion.h"
#include "../headers/Bow.h"
#include "../headers/Sword.h"
#include "../headers/Staff.h"
#include "../headers/Item.h"
#include "../headers/FactoryItem.h"

#include<stdlib.h>
#include<string>
#include<time.h>

using namespace std;

Item *FactoryItem::createItem(const string &type, int lvl)
{

   ///This allows other classes to create items by passing in the type
   ///of item they want and the level that they want it at. Level is passed
   ///onto the appropriate constructor.
   
   if(type=="Armour")
      return new Armour(lvl);
   else if(type=="Potion")
      return new Potion(lvl);
   else if(type=="Bow")
      return new Bow(lvl);
   else if(type=="Sword")
      return new Sword(lvl);
   else if(type=="Staff")
      return new Staff(lvl);
   else
      return NULL;
}
