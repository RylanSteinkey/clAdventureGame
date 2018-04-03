///header file for item factory pattern class
///\author Kip Jay
///\date oct 26 2017
#include "Weapon.h"
#include "Armour.h"
#include "Potion.h"
#include "Bow.h"
#include "Item.h"
#include <string> 

#ifndef FACTORYITEM_H
#define FACTORYITEM_H

using namespace std;

class FactoryItem
{
  
 public:
  ///Create Item
  /** A function to create an Item object at runtime, this is to condense
      all if/else statements associated with item creation. Creates a random
      item of that type at the specified level.
      \param[in] type the type of item that we wish to create
      \param[in] lvl the level that we want the created item to be
      \return Item* pointer to the item that has been created
  */ 
   static Item * createItem(const string &type, int lvl); 
};

#endif
