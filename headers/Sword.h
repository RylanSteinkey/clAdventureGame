/// \author Rylan Steinkey
/// \date Oct 25th

///header for the sword class, used for swords which counter melee enemies
///sword is a subclass to the weapon class

#ifndef SWORD_H
#define SWORD_H

#include "Weapon.h"


class Sword : public Weapon
{
    public:
    //behaviours

    ///constructor: Takes in the level that the created sword should be and opens the sword file
   /// and pulls a random sword out of that file that matches the level.
   /// \param[in] level the level to make the sword
   Sword(int lvl);

   ~Sword() {}
      /// returns the string Sword so that when getType is called on a Sword
   /// item it knows to return the string Sword
   ///\return string "Sword"
   string getType() const; 

} ;

#endif
