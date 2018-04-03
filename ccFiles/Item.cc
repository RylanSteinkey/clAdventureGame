///
/// YaDimSum 2720 Project
///
/// \author Rylan Steinkey
/// \date Nov 8th, 2017
///
///
/// The Item class in charge of making items for the game
///

#include "../headers/Item.h"
#include <iostream>
#include <fstream>

using namespace std;

///Destructor left blank
Item::~Item()
{
}

string Item::getItemName() const
{
   return itemName;
}

///returns the value of the item in gold
/// \return value
int Item::getItemValue() const
{
   return itemValue;
}

///returns the level of the item
/// \return level
int Item::getItemLevel() const
{
   return itemLevel;
}

///returns the appropriate stat for the item type
///i.e. for armour, will return defense stat
/// \return appropriate stat (health, defense or attack)
int Item::getStat() const
{
   if(healthStat != 0)
      return healthStat;
   else if(defenseStat != 0)
      return defenseStat;
   else if(attackStat != 0)
      return attackStat;
   else
      return -1;
}


Element* Item::getElementPointer() const
{
  return element;
}


string Item::getType() const
{
   return "why are you here"; 
}

