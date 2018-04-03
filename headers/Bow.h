/// \author Rylan Steinkey
/// \date Oct 25th

/// this is the header for the bow class, bows counter flying monsters
/// bow is a subclass of the weapons class

#ifndef BOW_H
#define BOW_H

#include "Weapon.h"



class Bow : public Weapon
{
  public:
   //behaviours
   
   ///constructor: takes in the level that the created item should be and then opens the
   /// bow file and pulls a random item out of it that matches the level
   /// \param[in] level the level to make the bow
   Bow(int lvl);

   ~Bow() {}
   /// returns the string Bow so that when getType is called on a Bow
   /// item it knows to return the string Bow
   ///\return string "Bow"
   string getType() const;

   string getBaseType() const; 
};
#endif
