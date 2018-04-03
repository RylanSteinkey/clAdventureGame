/// \author Rylan Steinkey
/// \date Oct 25th

/// this is a header for for the weapon class which is used to create weapon for attacking by player
/// weapon is a subclass of the item class

#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
#include "Element.h" 
#include <string> 
class Weapon : public Item

{
  public:
   /// Behaviours

   ///\param[in] seed a int to be passed in so you dont generate the same element when making multiple items in the same second.
   ///\param[in] lvl the level to make the weapon
   ///\param[in] inFile the name of the file in which to open
   void readFile(string inFile, int lvl, int seed);
    /// accessors

    ///returns the attack stat of the item.
    /// \return attackStat

  string getBaseType() const; 
   
   Element* getElementPointer() const;
   

   
    ///points to the element subclass that the weapon belongs to
    Element* weaponElement;
};

#endif
