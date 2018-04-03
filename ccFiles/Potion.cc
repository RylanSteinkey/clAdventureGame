///
/// YaDimSum 2720 project
///
/// \author Rylan Steinkey
/// \date Nov 8th, 2017
///
///
/// The Potion class, potion heals the player
/// Potion is a subclass to the item class
///

//#include "Item.h"
#include "../headers/Potion.h"
#include <cmath>
#include <stdlib.h>

using namespace std;

///constructor: takes in the level that the created potions should and then
/// creates a potion with stats representative of the level passed in.
/// \param[in] level the level in which to make the potion
Potion::Potion(int lvl)
{
   ///sets name to potion as all potions will be called "Potion"
   itemName = " Potion";
   
   ///formula to create the value of the item, increases at the same
   ///rate as a piece of armour or weapon but is worth less than a third
   itemValue = 0.3*(6*(pow(1.5, lvl)));

   ///sets level requirement
   itemLevel = lvl;

   ///health stat increases with its level
   srand(time(NULL));
   
   healthStat = 20 + (5*lvl);
   healthStat += rand() % 4;

   ///set defense and attack stats to 0 so that when you call getStat()
   ///on an item it knows to return the only non zero function, which
   /// in this case is the healthStat
   attackStat = 0;
   defenseStat = 0;
}

string Potion::getBaseType() const
{
  return "Potion";
}
