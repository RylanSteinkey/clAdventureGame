/// YaDimSum 2720 project
/// \author Joshua Pepple
/// \date October 24th, 2017
///
///
/// The Player class inherits BattleCharacter class. This creates the Player Object for User to control which interacts with other classes.

#ifndef PLAYER_H
#define PLAYER_H

#include "BattleCharacter.h"
#include "Item.h"
#include "Weapon.h"
#include "Screen.h"
#include "Armour.h" 
using namespace std;

/** The Player object has 2 Item pointers which point to the weapon the Player is wielding and the armor the Player has equipped.
    It also holds the amount of gold the Player has at an instance and also their EXP (Experience) from which Player levels up. */

class Player : public BattleCharacter
{
  public:
   ///Behaviours
   
   /// constructs a new Player object using User's name
   /// \param[in] name, the name of the Player character.
   Player(string name);
   
   /// destroys the Player object
   ~Player();
   
   ///Accessors
   
   /// returns the Player's EXP
   /// \return Player's EXP
   int getEXP() const;
   
   /// returns the Player's gold
   /// \return Player's gold
   int getGold() const;
   
   ///Mutators
   
   /// increases the Player's EXP by the integer passed
   /// \param[in] increaseBy is the integer to increase Player EXP by
   void addEXP(int increaseBy);
   
   /// checks the Player's EXP to see if they satisfy the condition to go up a Level
   void levelUp();
   
   /// increases the Player's gold by the integer passed
   /// \param[in] increaseBy is the integer to increase Player gold by
   void changeGold(int increaseBy);
   
   ///increases the Player's attack stat by the integer passed
   /// \param[in] increaseBy is the integer to increase Player attack stat by
   void changeAttack(int increaseBy);
   
   ///increases the Player's defense stat by the integer passed
   /// \param[in] increaseBy is the integer to increase Player defense stat by
   void changeDefense(int increaseBy);
   
   /// changes Player's primary weapon to Weapon referred to by Item pointer. Only allowed for Weapons as only Weapons can be wielded and given that Player is on the same level or higher than the Weapon
   /// \param[in] secondary is the weapon to swap to by making wieding point to it
   void changeWeapon(Item* secondary);
   
   /// changes Player's primary armor to Armor referred to by Item pointer. Only allowed for Armors as only Amours can be worn and only if Player is on same level or higher level than Armour
   /// \param[in] ar, the armor to swap to by making wearing point to it
   void changeArmour(Item* ar);
   
   // Kip added - we need a way for battle/others to know which item is being
   // wielded

   /// This function returns a pointer to what Item [Weapon] the Player is wielding
   /// \return wielding which is a pointer to current weapon
   Item* getWeapon() const;

   /// This function returns a pointer to what Item [Armour]\ the Player is wearing
   /// \return wearing which is a pointer to current armour
   Item* getArmour() const; 

  protected:
   ///Attributes
   
   /// The Item pointer to weapon equipped by Player
   Item* wielding;
   
   /// The Item pointer to armor equipped by Player
   Item* wearing;
   
   /// The amount of gold Player has
   int playerGold;
   
   /// The amount of EXP the Player has
   int EXP;
};
#endif
