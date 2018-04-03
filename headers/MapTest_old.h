#ifndef MAPTEST_H
#define MAPTEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <Map.h>

/**
 *Map Test
 * \author Aditya Joshi
 * last modified \date Nov 8
 * Header file to test various functions in the Map class
 */

class MapTest : public CppUnit::TestFixture
{
   CPPUNIT_TEST_SUITE(MapTest);
   CPPUNIT_TEST(damageRemove);
   CPPUNIT_TEST(hpEmpty);
   CPPUNIT_TEST(hpMax);
   CPPUNIT_TEST(armourAdd);
   CPPUNIT_TEST(armourMax);
   CPPUNIT_TEST(throwException);
   CPPUNIT_TEST(getTownList);

   CPPUNIT_TEST_SUITE_END();

  public:
   /// Set up the initial environment for CPPUNIT 
   void setUp();
   
   /// Remove anything that needs to be deleted from heap etc
   void tearDown(){};
   
   /// Used to test if health potions apply properly
   void damageRemove();
   
   /*We will test to see if the player's health is empty. When this state is
     reached, the player should be presented with a game over screen and
     should not be allowed to proceed with the current gameplay. */
   void hpEmpty();
 
      /*If a player's health is max, then they should not be allowed to purchase
	health potions. */ 
   void hpMax();
   
   /// Used to test if armour is applied properly
   void armourAdd();
   
   /* If the player already has max armour, then they should not be allowed to
      purchase more armour. */
   void armourMax();
   
   /// Throw exception if the player performs an illegal action
   void throwException();

   /* Since we will be giving the user the option to go to another town,
      we need to make sure the existing town list is gotten.*/
   void getTownList();

  private:
   /// More content will be added here at a later date.
   Map *testMap = new ;
   int playerHealth;
   int expectedCurrentHP;
   int expectedCurrentArmour;
   int playerArmour;
};

#endif
