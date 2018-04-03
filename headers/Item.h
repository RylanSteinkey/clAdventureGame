/// \author Rylan Steinkey
/// \date Oct 25th

/// this is header for the item base class

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include "Element.h"

using namespace std; 

class Item
{
  public:

   //Accessors

   /// destructor
   virtual ~Item();
   
   ///returns the name of the item
   /// \return itemName
   string getItemName() const;

   ///returns the value of the item in gold
   /// \return value
   int getItemValue() const;

   ///returns the level of the item
   /// \return level
   int getItemLevel() const;

   ///returns the appropriate stat for the item type
   ///i.e. for armour, will return defense stat
   /// \return appropriate stat (health, defense or attack)
   int getStat() const;

   
   
   ///Attributs

   ///level requirement to use the item
   int itemLevel;
   
   ///name of the item
   string itemName;
   
   ///value of the item in gold
   int itemValue;

   ///damage the weapon will do (set to 0 for potions and armour)
   int attackStat;

   ///amount of damage that the armor can absorb (set to 0 for potions and weapons)
   int defenseStat;

   ///amount of health that a potion can heal (set to 0 for weapons and armor)
   int healthStat;

   /// returns the string Bow so that when getType is called on a Bow
   /// item it knows to return the string Bow
   ///\return string "Bow"
   virtual string getType() const;

   virtual string getBaseType() const =0; 


   /// returns an element pointer to the element subclass that the item
   /// belongs to
   Element* getElementPointer() const;
   

  protected:
   ///points to the element subclass that the weapon belongs to
   Element* element;

};

#endif
