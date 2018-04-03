/// YaDimSum 2720 project
/// \author Joshua Pepple

/// This class inherits the Character class and adds some more features to the already existing ones inheritd from the Character class.

#ifndef BATTLECHARACTER_H
#define BATTLECHARACTER_H

#include "Character.h"
#include <iostream>
#include <fstream>

using namespace std;

/// The BattleCharacter Object has health, max health, attack stats, defense stats and the level of BattleCharacters and helper functions to access them

class BattleCharacter : public Character
{
  public:
   /// Behaviours

   /// destroys the object
   virtual ~BattleCharacter() {}   
   ///Accessors

   /// returns the health of BattleCharacter
   /// \return charHealth

   int getHealth() const;

   /// returns the attack stat of BattleCharacter
   /// \return charAttack

   int getAttack() const;

   /// returns the defense stat of BattleCharacter
   /// \return charDefense

   int getDefense() const;

   /// returns the level of BattleCharacter
   /// \return charLevel
   int getLevel() const;

   /// returns the max health of BattleCharacter
   /// \return charMaxHealth
   int getMaxHealth() const;

   ///Mutators

   /// changes the health of BattleCharacter by integer passed.
   /// A positive integer increases it while negative integer decreases it
   /// \param[in] changeBy is used to modify charHealth
   void changeHealth(int changeBy);

  protected:
   ///Attributes

   /// The amount of health BattleCharacter has left at any instance
   int charHealth;
   /// The maximum amount of health a BattleCharacter can have
   int charMaxHealth;
   /// The Attack stat of a BattleCharacter
   int charAttack;
   /// The Defense stat of a BattleCharacter
   int charDefense;
   /// The Level of BattleCharacter
   int charLevel;
};

#endif
