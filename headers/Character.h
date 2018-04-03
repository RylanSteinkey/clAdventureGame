/// YaDimSum 2720 project
/// \author Joshua Pepple
/// \date October 24th, 2017
///
///
/// The Character class is an abstract class which forms the basis for other Characters and stores some basic information that these Characters have in common.

#ifndef CHARACTER_H
#define CHARACTER_H

#include "Inventory.h"
#include <string>

using namespace std;

///The Character Object has a name and a pointer to the Inventory of the different Characters which are subclasses.
///It friends the BattleTest and RoadTest classes.

class Character
{
  public:
   friend class BattleTest;
   friend class RoadTest;

   ///Behaviors
   
   /// This destroys the Character Object
   virtual ~Character() {}

   /// Accessors
   
   /// This returns a pointer to the Character's inventory
   /// \return charInventory
   Inventory * getInventory();

   /// This returns the name of the Character Object
   /// \return charName 
   string getName() const;

   /// This function prints the Inventory of the Character Object
   void printInventory();
   
  protected:
   ///Attributes
   
   ///The Inventory pointer to the Inventory of Character
   Inventory * charInventory;
   
   ///The name of Character
   string charName;
};
#endif
