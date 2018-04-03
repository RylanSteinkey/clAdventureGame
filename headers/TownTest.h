#ifndef BATTLETEST_H
#define BATTLETEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../headers/Town.h"
#include "../headers/Item.h"
#include "../headers/Player.h"

/**
 * Town-> new -> startEvent -> Interface -> ( given 4 options ) -> loop options
 * 1) visitHospital or 2) visitShopkeeper or 3) roadToNextTown or 4) goToCastle
 * option 1) visitHospital
 *   -  set the players current health to max health so,
 *      Player.charHealth= Player.charMaxHealth 
 *   -  display to user that they were fully healed
 *   -  loop back to Interface
 * option 2) visitShopKeeper
 *   -  new NPC ( NPC.h^Item.h^Inventory.h)
 *   -  Interface for NPC to prompt the player to 1) buyItem 2) sellItem 3) Exit
 *   -  1) buyItem
 *      -First, check if they have room in there inventory to buy an item.
 *        If (invSize==invCapacity) then they must first remove an item from
 *        inventroy. so they must select an item to remove removeItem(Item *aItem).
 *        Else (invSize!=invCapacity) they can try and buy an Item.
 *      -Once they have room in there inventory they can pick an item to buy. So
 *        check the price of the item they selected to buy. If (they can afford it),
 *        then addItem(Item *aItem) to players inventory and romoveItem(Item *rItem)
 *        from the NPC Inventory. Else (they CANT afford it) so promt they cant buy
 *      -loop back to the Interface for shopkeeper
 *   -  2) sellItem
 *      -Make sure that the NPC doesnt have a full inventory so that it can add the
 *       item to its inventory.
 *      -So remove the Item from the players inventory and get the items value, in
 *       gold and add it to the players gold value.
 *      -Add that item to the NPC inventory.
 *      -loop back to the Interface for shopkeeper
 */

class TownTest : public CppUnit::TestFixture
{
   CPPUNIT_TEST_SUITE(TownTest);
   CPPUNIT_TEST(visitHospitalTest);
   CPPUNIT_TEST(buyItemTest);
   CPPUNIT_TEST(sellItemTest);
   CPPUNIT_TEST_SUITE_END();

  public:
   void setUp();
   void visitHospitalTest();
   void buyItemTest();
   void sellItemTest();
   void tearDown();

  private:

   Town *town;
   Player *player;
   Potion * potion = new Potion(1);
   Item * bow = new Bow(1);

   int maxSize;
   int addCount;
   
};

#endif
