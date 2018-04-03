/// \author Rylan Steinkey
/// \date Oct 25th

/// this is the header for the armour class which contributes to the players defense
/// armour is a subclass of the item class

#ifndef ARMOUR_H
#define ARMOUR_H

#include "Item.h"
#include "FactoryItem.h"
#include <iostream>

class Armour : public Item, public FactoryItem
{
    public:
   
   //behaviours
   
   ///constructor: take the level in which the created item should be, opens the armour file
   /// and picks a random item out of the file and creates it
   /// \param[in] level the level in which to make the armour
   Armour(int level);

   ~Armour(){};
   /// returns the string Armour so that when getType is called on an Armour
   /// item it knows to return the string Armour
   ///\return string "Armour"
   string getType() const;

   string getBaseType() const; 

};
#endif // ARMOUR_H
