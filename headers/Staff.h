/// \author Rylan Steinkey
/// \date Oct 25th

/// this is the header for the staff class, staffs counter undead enemies
/// staff is a subclass of the weapon class

#ifndef STAFF_H
#define STAFF_H

#include "Weapon.h"

class Staff : public Weapon
{
    public:
   //behaviours
   
   ///constructor: Takes in the level that the created sword should be and opens the
   /// staff file and pulls a random item out of it that matches the level
   /// \param[in] level the level to make the staff
   Staff(int level);

   ~Staff(){};
   /// returns the string Staff so that when getType is called on a Staff
   /// item it knows to return the string Staff
   ///\return string "Staff"
   string getType() const;
   string getBaseType() const; 
};
#endif // STAFF_H
