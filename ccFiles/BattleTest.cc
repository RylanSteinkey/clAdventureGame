#include <stdexcept>
#include <sstream>
#include <fstream> 
#include <iostream>
#include <string> 
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestCase.h>
#include <cppunit/TextTestRunner.h>
#include <cppunit/TestCaller.h> 
#include "../headers/BattleTest.h"
#include "../headers/Battle.h"
#include "../headers/Player.h"
#include "../headers/FlyingMonster.h"
#include "../headers/Monster.h"
#include "../headers/Monster.h"
#include "../headers/Potion.h"
#include "../headers/Bow.h"
#include "../headers/Inventory.h"
#include "../headers/Map.h"
#include "../headers/Road.h"
#include "../headers/Exceptions.h"

/**
 * Battle Test
 * \author Kip Jay 
 * Header file to test various functions in the battle class
 * it will test things such as ensuring that the damage is calculated
 * correctly, and the interactions between player and monster
 * act as it should
 */

using namespace std;

void BattleTest::setUp()
{

   elementFile = "../TextFiles/ElementBonus.txt";
   typeFile = "../TextFiles/TypeBonus.txt" ;

   expectedPlayerAttackDamage = 16;
   expectedMonsterAttackDamage = 20; 
   expectedPlayerDamageDealt = 11;
   expectedMonsterDamageDealt = 10;

   /// Player setup adding a weapon and a potion 
   testPlayer->getInventory()->addItem(bow);
   testPlayer->getInventory()->addItem(armour1);
   testPlayer->changeWeapon(bow);
   testPlayer->changeArmour(armour1);

   increaseHealth = 10;
   decreaseHealth = 10; 
   ///Set up the characters that should throw exceptions
   //set attack to 0 something that shouldnt't ever happen in the real game 
   //(*testPlayerBad).changeAttack( -1 * (*testPlayerBad).getAttack());


}

void BattleTest::testHelperFunc()
{
   //Changing weapons and armour 
   CPPUNIT_ASSERT(testPlayer->getWeapon() == bow);
   testPlayer->changeWeapon(sword);
   CPPUNIT_ASSERT(testPlayer->getWeapon() == sword);

   CPPUNIT_ASSERT(testPlayer->getArmour() == armour1);
   testPlayer->changeArmour(armour2); 
   CPPUNIT_ASSERT(testPlayer->getArmour() == armour2);

   
}


void BattleTest::getElementBonus()
{


   CPPUNIT_ASSERT(battle.getBonus(elementFile, "Water", "Air") == 0.9);
   CPPUNIT_ASSERT(battle.getBonus(elementFile, "Air", "Water") == 1.1);
   CPPUNIT_ASSERT(battle.getBonus(elementFile, "Air", "Air") == 1); 

   
}


void BattleTest::getTypeBonus()
{
   CPPUNIT_ASSERT(battle.getBonus(typeFile, "Bow", "Flying") == 1.1);
   CPPUNIT_ASSERT(battle.getBonus(typeFile, "Bow", "Melee") == 0.9);
   CPPUNIT_ASSERT(battle.getBonus(typeFile, "Staff", "Flying") == 1); 
}

//*******************************************************************************************************
///Test to see the damage that is calculated by the function is the expected damage
///that it is suppose to calculate for the player
//*******************************************************************************************************
void BattleTest::playerDamageCalc()
{

   CPPUNIT_ASSERT(battle.findAttackerDamage(testPlayer, testMonster)==
		  expectedPlayerAttackDamage); 

}
//*******************************************************************************************************
///Test to see the damage that is calculated by the function is the expected damage
///that it is suppose to calculate for the monster
//*******************************************************************************************************
void BattleTest::monsterDamageCalc()
{
   CPPUNIT_ASSERT(battle.findAttackerDamage(testMonster) ==
      expectedMonsterAttackDamage); 
 
}
//*******************************************************************************************************
///Compare the actual damaged Monster health to the monster max health minus expected damage to monster
//*******************************************************************************************************
void BattleTest::monsterDamage()
{
   battle.monsterAttack(testPlayer, testMonster);
   newHealth = testPlayer->getMaxHealth()- testPlayer->getHealth();
   CPPUNIT_ASSERT(newHealth == expectedMonsterDamageDealt); 
 
}
//*******************************************************************************************************
///Compare the actual damaged Player health to the player max health minus expected damage to player
//*******************************************************************************************************
void BattleTest::playerDamage()
{
   battle.playerAttack(testPlayer, testMonster);
   newHealth = testMonster->getMaxHealth()-testMonster->getHealth();
   CPPUNIT_ASSERT(newHealth == expectedPlayerDamageDealt); 
}

//*******************************************************************************************************
///compare the actual damaged player health to the player max health minus expected damage to player
//*******************************************************************************************************

//***************************************************************************************************
///Exceptions are expected to be thrown for error handling .. this is currently lacking since
/// code has not been written ..
//*************************************************************************************************
void BattleTest::throwExceptions()
{
   testPlayerBad->changeHealth( -(testPlayerBad->getMaxHealth()) );
   testMonsterBad->changeHealth( -testMonsterBad->getMaxHealth() ); 
   CPPUNIT_ASSERT_THROW(battle.playerAttack(testPlayerBad, testMonsterBad), battleError   );
   CPPUNIT_ASSERT_THROW(battle.getBonus("asds", "Fire", "Water"), invalidFile);
   CPPUNIT_ASSERT_THROW(battle.playerAttack(testPlayerBad, testMonsterBad), battleError );
   CPPUNIT_ASSERT_NO_THROW(battle.playerAttack(testPlayer, testMonster));
   CPPUNIT_ASSERT_NO_THROW(battle.monsterAttack(testPlayer, testMonster)); 
   
}
//*******************************************************************************************************
///Ensures that the health potions are restoring the correct health
//*******************************************************************************************************
void BattleTest::HP()
{
   
   playerOldHealth = testPlayer->getHealth();
   testPlayer->changeHealth(increaseHealth); 
   newHealth = testPlayer->getHealth();
   CPPUNIT_ASSERT(newHealth == (playerOldHealth + increaseHealth));
   testPlayer->changeHealth(increaseHealth); 
   playerOldHealth = testPlayer->getHealth();

   
}
//*******************************************************************************************************
///Check that isDead is returning the correct bool - at first none of them should be dead
///but then once hp is set to 0, it should return true for isDead
//*******************************************************************************************************
void BattleTest::isDead()
{
   CPPUNIT_ASSERT( !battle.isDead(testPlayer));
   CPPUNIT_ASSERT( !battle.isDead(testMonster));

   testPlayer->changeHealth(-testPlayer->getMaxHealth());
   testMonster->changeHealth(-testMonster->getMaxHealth()); 
   
   CPPUNIT_ASSERT( battle.isDead(testPlayer));
   CPPUNIT_ASSERT( battle.isDead(testMonster)); 
   

   
}
//*******************************************************************************************************
///remove anything on the heap
//*******************************************************************************************************
void BattleTest::tearDown()
{
   delete testMonster;
   delete testPlayer;
   delete testMonsterBad;
   delete testPlayerBad;
}
