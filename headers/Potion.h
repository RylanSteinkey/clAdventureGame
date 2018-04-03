/// \author Rylan Steinkey
/// \date Oct 25th

/// this is the header for the potion class, potions heal the player
/// potion is a subclass of the item class

#ifndef POTION_H
#define POTION_H

#include "Item.h"

class Potion : public Item
{
public:

   //behaviours
   
   ///constructor: takes in the level that the created potions should and then
   /// creates a potion with stats representative of the level passed in.
   /// \param[in] level the level in which to make the potion
   Potion(int lvl);

   ~Potion() {}
   string getBaseType() const; 
};
#endif // POTION_H
