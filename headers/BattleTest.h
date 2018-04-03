#ifndef BATTLETEST_H
#define BATTLETEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Battle.h"
#include "Player.h"
#include "FlyingMonster.h"
#include "Monster.h"
#include "Bow.h"
#include "Armour.h"
#include "Sword.h"
#include "Staff.h"
#include "Potion.h"
#include <sstream>
#include <string>
#include "Air.h"
#include "Water.h"
#include "Earth.h"
#include "Fire.h"
#include "Road.h"
#include "Map.h"


/**
 * Battle Test
 * \author Kip Jay 
 * Header file to test various functions in the battle class
 * it will test things such as ensuring that the damage is calculated
 * correctly, and the interactions between player and monster
 * act as it should
 */


class BattleTest : public CppUnit::TestFixture
{
   CPPUNIT_TEST_SUITE(BattleTest);

   CPPUNIT_TEST(getTypeBonus);
   CPPUNIT_TEST(getElementBonus); 
   CPPUNIT_TEST(testHelperFunc); 
   CPPUNIT_TEST(playerDamageCalc);
   CPPUNIT_TEST(monsterDamageCalc);
   CPPUNIT_TEST(testHelperFunc); 
   CPPUNIT_TEST(HP);
   CPPUNIT_TEST(throwExceptions);
   CPPUNIT_TEST(monsterDamage);
   CPPUNIT_TEST(playerDamage); 
   CPPUNIT_TEST(isDead);
   CPPUNIT_TEST_SUITE_END();

  public:
   /// Set up the initial environment for CPPUNIT 
   void setUp();
   /// Remove anything that needs to be deleted from heap etc
   void tearDown();
   /// Check that the helper functions associated are correct 
   void testHelperFunc();
   /// Make sure that when obtaining the bonuses that it is correct
   void getTypeBonus();
   void getElementBonus();
   /// Battle needs to ensure that it will calculate
   /// damage correctly for both player, monster 
   void playerDamageCalc();
   /// battle needs to ensure that it will calculate
   /// damage correctly for just monster damage, when player
   /// is not attacking 
   void monsterDamageCalc();
   /// When drinking potions, we need to ensure that
   /// hp is incremented correctly
   void HP();
   /// When damaged, we need to make sure that the damage is
   /// taking away the correct amount of health -
   /// different from just calculating the damage that
   /// SHOULD be dealt - for monster
   void monsterDamage();
   void playerDamage();
   /// make sure any exceptions being thrown are thrown for
   /// the excepted reason
   /// ex. When player is choosing options such as
   /// 1 - attack 2 - drink potion
   /// an exception is thrown when they choose 
   void throwExceptions();
   /// Correctly returns the expected outcome when either
   /// the monster or player is dead - bool 
   void isDead();


   
  private:


   /// get the monster and player dummies 
   Player * testPlayer = new Player("dummy");
   Monster * testMonster = new FlyingMonster(1);
   Player * testPlayerBad = new Player("throwingExceptions");
   Monster * testMonsterBad = new FlyingMonster(1);

   //Type
   Element * water = new Water;
   Element * fire = new Fire;
   Element * earth = new Earth;
   Element * air = new Air;
  
   /// Screen, and item initialization 
   Item * bow = new Bow(1);
   Item * sword = new Sword(1); 
   Item * armour1 = new Armour(1);
   Item * armour2 = new Armour(1); 
   /// Get the battle constructed 
   Battle battle;
   Road road; 
   
   string elementFile;
   string typeFile; 


   /// some parameter initialization
   double newHealth;
   int expectedPlayerAttackDamage;
   int expectedMonsterAttackDamage; 
   int expectedPlayerDamageDealt;
   int expectedMonsterDamageDealt;
   int increaseHealth;
   int decreaseHealth; 
   int oldHealth;
   int monsterOldHealth;
   int playerOldHealth;
};


#endif 
