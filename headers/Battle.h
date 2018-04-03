///Battle header file 

#ifndef BATTLE_H
#define BATTLE_H 

#include "Monster.h"
#include "FlyingMonster.h"
#include "UndeadMonster.h"
#include "MeleeMonster.h"
#include "Player.h"
#include "Screen.h"
#include "BattleCharacter.h"
#include "Character.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Water.h"
#include "Fire.h"
#include "Air.h"
#include "Earth.h"

using namespace std;

/// Battle header file 
/// \author Kip Jay
/// \date October 25 2017 
///
/// Handles the interaction between monster and character in battles 
/// deals with how the player attacks the monster, and damage dealt
/// allows player to do a non-damage battle turn such as equipping the proper
/// items. 

class Battle
{
   ///
   //public members of the battle class
   ///
public:

   ///constructor for battle class 
  Battle();
  
   ///destructor for the battle class
   ~Battle(){};

   ///displays the battle (information of the character and monster)
   /**\param[in] player - pointer to the player that we want the stats for
      \parmin[in] monster - pointer to the monster that we want the stats for
      \parmin[out] prints the screen of the stats for both player & monster */ 
   void stats(Player* player, Monster* monster);

   
   ///Only player attacks 
   /**Allow the player to deal damage to the monster, this occurs only when player
      attacks.
      \parmin[in] player - pointer to the player that is attacking
      \parmin[in] monster - pointer to the monster that is being attacked
      \parmin[out] monster health is mutated - decreased or nothing happens */ 
      void playerAttack(Player* player, Monster* monster);

   ///Only Monster attacks
  /** Allow the monster to deal damage to user, this occurs if
      user commits to a non-attack turn eg. viewing inventory
      this is the full calculation including
      defense stats are taken into account
      \parmin[in] player - pointer to the player that is being attacked
      \parmin[in] monster - pointer to the monster that is attacking
      \parmin[out] player health is manipluated */
   void monsterAttack(Player* player, Monster* monster);

   ///damage calculator
   /**To calculate the appriopriate damage that is dealt by either the
      the player, dependent on several factors
      factors: stats, weapons + element, armour, and monster type
      \return the damage that is dealt by player only */
   int findAttackerDamage(Player* player, Monster* monster);

   ///damage calculator
   /***To calculate the appriopriate damage that is dealt by the monster
       currently there would not be much in the code but for further
       extension, we can just edit the monster damage here and not have
       to go hunt it down in the code
       \parmin[in] monster - the pointer to the monster that is being battled
       \return damage - it is the total damage that is dealt by monster only */
   int findAttackerDamage(Monster* monster);

   
   /// Return true or false for character if HP is below 0
   /** \parmin[in] 
       \return bool - false if character is alive
       - true if character is dead */
   bool isDead(BattleCharacter* character) const;

   ///*
   double getBonus(string bonusFileName, string attackerTypeIn, string defendingTypeIn) const;

   bool checkType(string fileString, string stringInType) const; 
   
}; 





#endif 
