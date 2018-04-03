#include "../headers/Battle.h"
#include "../headers/Fire.h"
#include "../headers/Water.h" 
#include "../headers/Element.h"
#include "../headers/FlyingMonster.h" 
#include <string>
#include <iomanip>
#include "../headers/FactoryItem.h" 
#include "../headers/Road.h"
#include "../headers/Map.h"
using namespace std;

int main(void)
{

   
  Player * player = new Player("2720 The GateKeeper");
  //Monster* monster1 = new FlyingMonster(1);

  
  Item* testItem = FactoryItem::createItem("Sword", 1);
  Item* testItem2 = FactoryItem::createItem("Armour",1);
  Item* testItem3 = FactoryItem::createItem("Bow", 1);
  Item* testItem4 = FactoryItem::createItem("Potion", 1);
  Item* monsterItem = FactoryItem::createItem("Staff", 1); 


  player->getInventory()->addItem(testItem4); 
  player->getInventory()->addItem(testItem3);
  player->getInventory()->addItem(testItem2); 
  player->getInventory()->addItem(testItem); 
   //player->getInventory()->addItem(testItem);
  player->changeWeapon(testItem);
  player->changeArmour(testItem2); 
  // battle.attack();
  Battle battle;
  /*battle.stats(player, monster1);
  cout 
       << "1: Attack the Monster!" << '\n'
       << "2: View inventory" << endl;
  player->getInventory()->displayInventory();
  */
   int k = battle.getBonus("../TextFiles/ElementBonus.txt", "Fire", "Water");
  cout << k << endl; 
  Road road;
  road.battleSequence(player, "regularMonster");
  cout << "done" << endl;
  char c; 
  cin >> c;

  cout << "paused" << endl; 
  // battle.playerAttack(player, monster1); 

  //    if(Fire * ptr = dynamic_cast<Fire*>(two))
  //  cout << "hello" << endl; 


}
