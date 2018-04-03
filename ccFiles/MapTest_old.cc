#include <stdexcept>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../headers/MapTest.h"

using namespace std;
/*!
 * Map Test
 * \author Aditya Joshi
 * last modified \date Nov 8
 * Header file to test various functions in the Map class.
 */

/* 
/// Set up the initial environment for CPPUNIT 
void MapTest::setUp()
{
   testMap = new Map();
};

/// Remove anything that needs to be deleted from heap etc
void MapTest::tearDown(){
   delete testMap;
};

/// Used to test if health potions apply properly
void MapTest::damageRemove()
{
   CPPUNIT_ASSERT(map.findCurrentHP(existingPlayer)  == expectedCurrentHP);
};

/*We will test to see if the player's health is empty. When this state is
  reached, the player should be presented with a game over screen and
  should not be allowed to proceed with the current gameplay. 
void MapTest::hpEmpty()
{
   CPPUNIT_ASSERT(map.findCurrentHP(existingPlayer) >= 0);
};

/*If a player's health is max, then they should not be allowed to purchase
  health potions. 
void MapTest::hpMax()
{
   CPPUNIT_ASSERT(map.findCurrentHP(existingPlayer) <= 100);
};

/// Used to test if armour is applied properly
void MapTest::armourAdd()
{
   CPPUNIT_ASSERT(map.findCurrentArmour(existingPlayer) >= 0);
};

/* If the player already has max armour, then they should not be allowed to
purchase more armour. 
void MapTest::armourMax()
{
   CPPUNIT_ASSERT(map.findCurrentArmour(existingPlayer) <= 100);
};

/// Throw exception if the player performs an illegal action
void MapTest::throwException()
{
};

/// Since we will be giving the user the option to go to another town,
///we need to make sure the existing town list is gotten.
void MapTest::getTownList()
{
   CPPUNIT_ASSERT(map.findTownList(existingPlayer) == false);
};

*/ 
