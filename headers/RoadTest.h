#ifndef ROADTEST_H
#define ROADTEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Battle.h"
#include "Player.h"
#include "Inventory.h"
#include "FlyingMonster.h"
#include "Monster.h"
#include "Staff.h"
#include "Bow.h"
#include "Potion.h"
#include <sstream>
#include <string>
#include "NPC.h"

class RoadTest : public CppUnit::TestFixture
{
   CPPUNIT_TEST_SUITE(RoadTest);
   CPPUNIT_TEST(addItemTest);
   CPPUNIT_TEST(buyItemTest);
   CPPUNIT_TEST(sellItemTest);
   CPPUNIT_TEST_SUITE_END();
   
  public:
   void setUp();
   void addItemTest();
   void buyItemTest();
   void sellItemTest();
   void tearDown();

  private:
   Road *road;
   Player *player;
   Potion *potion = new Potion(1);
   Item *staff = new Staff(1);
   Item *bow = new Bow(1);
   
   int maxSize;
   int addCount; 
};
#endif
