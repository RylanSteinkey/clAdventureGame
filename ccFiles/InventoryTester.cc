 #include "../headers/Inventory.h"
#include "../headers/Character.h"
#include "../headers/Player.h"
#include "../headers/NPC.h"
#include "../headers/Item.h"
#include "../headers/FactoryItem.h"
#include "../headers/Armour.h"

using namespace std;

int main(void)
{
   Player Dallan("Dallan");
   Item * Arm=FactoryItem::createItem("Armour",3);
   Item * Arm2=FactoryItem::createItem("Armour",2);
   Item * Arm3=FactoryItem::createItem("Armour",1);
   Item * Arm4=FactoryItem::createItem("Armour",4);
   //Dallan.printInventory();
   cout << "\n";
   cout << "old free space: " << Dallan.getInventory()->getFreeSpace() <<endl;
   cout << "hello" << endl; 
   Dallan.getInventory()->addItem(Arm);
   Dallan.getInventory()->addItem(Arm2);
   Dallan.getInventory()->addItem(Arm3);
   Dallan.getInventory()->addItem(Arm4);
   Dallan.printInventory();
   cout << "\n";
   cout << "new freespace: " << Dallan.getInventory()->getFreeSpace() << endl;
   Dallan.getInventory()->removeItem(Arm);
   Dallan.printInventory();
   NPC Fuck(Dallan.getLevel());
   //Fuck.getInventory()->generateInventory(5);
   Fuck.printInventory();
   
}
