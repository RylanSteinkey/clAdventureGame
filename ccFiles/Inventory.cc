///
/// CS 2720 YaDimSum Group Project 
///
/// \author Dallan McCarthy 001175764
/// \date Nov 4th, 2017
///
///
/// The Inventory class is used to create an inventory object to 
/// store Character Items and generate their Inventories
///

#include "../headers/Inventory.h"
#include "../headers/Item.h"
#include "../headers/Screen.h"
#include "../headers/Player.h"
#include "../headers/Character.h"
#include "../headers/Potion.h"
#include "../headers/Bow.h"
#include "../headers/Sword.h"
#include "../headers/Staff.h"
#include "../headers/Item.h"
#include "../headers/FactoryItem.h"
#include "../headers/Exceptions.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

/// Constructs an Inventory
Inventory::Inventory(int length)
   : invCapacity{length}, invSize{0}
{

}

/// Destructor to delete inventory item objects
Inventory::~Inventory()
{
   for(unsigned int i=0; i < charInv.size(); ++i)
   {
      delete charInv[i];
   }
}

/// Function to display Character's inventroy to Screen at x,y coordinates.
void Inventory::displayInventory()
{
   for(unsigned int i=0; i < charInv.size(); ++i)
   {
      cout<<setw(2)<<right<< i <<" |"
	  <<setw(25)<<right<<charInv[i]->getItemName()<<" |";
      string type = charInv[i]->getBaseType();
      if(type == "Weapon")
      {
	 cout<<setw(8)<<right<<charInv[i]->getType()<<" |"
	     <<setw(8)<<right
	     <<charInv[i]->getElementPointer()->getElement()<<" |"
	     <<setw(4)<<right<<charInv[i]->getItemLevel()<<" |";
	 cout<<setw(4)<<right<<charInv[i]->getStat()<<" |"
	     <<setw(6)<<right<<" |"<<setw(6)<<right<<" |";
      }
      else if(type == "Armour")
      {
	 cout<<setw(8)<<right<<type<<" |"<<setw(10)<<right<<" |"
	     <<setw(4)<<right<<charInv[i]->getItemLevel()<<" |";
	 cout<<setw(6)<<right<<" |"
	     <<setw(4)<<right<<charInv[i]->getStat()<<" |"
	     <<setw(6)<<right<<" |";
      }
      else if(type == "Potion")
      {
	 cout<<setw(8)<<right<<type<<" |"<<setw(10)<<right<<" |"
	     <<setw(4)<<right<<charInv[i]->getItemLevel()<<" |";
	 cout<<setw(6)<<right<<" |"<<setw(6)<<right<<" |"
	     <<setw(4)<<right<<charInv[i]->getStat()<<" |";
      }
      cout<<setw(4)<<right<<charInv[i]->getItemValue()<<" |" <<endl;
   }
   
}

/// returns the number of free spaces in the characters inventory
int Inventory::getFreeSpace()
{ 
   return invCapacity- invSize;
}

/// Adds item purchased or looted to the characters inventory
void Inventory::addItem(Item *aItem)
{
   try
   {
      if(getFreeSpace() == 0)
	 throw invalidItemError("Full Inventory"); 
      charInv.push_back(aItem);
      invSize += 1;
   }
   catch(const invalidItemError error)
   {
      cout << error.what() << endl;
   }
}

/// Remove items from inventory
void Inventory::removeItem(int place)
{
      charInv.erase(charInv.begin()+place);
      invSize -= 1;
      
}

/// Function that populates the characters inventory with items
void Inventory::generateInventory(int pLvl)
{
   //Generate inventory for NPC
   int j=0;
   
   
   for(int i = 0; i <= 2;i++)
   {
      
      
      charInv.emplace_back(FactoryItem::createItem("Armour", pLvl + j));
      charInv.emplace_back(FactoryItem::createItem("Potion", pLvl + j));
      charInv.emplace_back(FactoryItem::createItem("Bow", pLvl + j));
      charInv.emplace_back(FactoryItem::createItem("Sword", pLvl + j));
      charInv.emplace_back(FactoryItem::createItem("Staff", pLvl + j));
      invSize += 5;
      
      j++;
      
      ///Prevents generating items above level 10
      ///Written by Rylan James Steinkey, First of his name,
      ///protector of the realm and writer of code.
      if (pLvl >= 9)
      {
	 if (j>1)
	 {
	    j--;
	 }
      }
      
      if (pLvl == 10)
      {
	 j = 0;
      }
   }
  
   
}

/// Function that returns a Item pointer in the inventory 
Item * Inventory::getInventoryPointer(int spot)
{
   return charInv[spot];
}

/// Function that returns the inv Size
int Inventory::getCurrentSize()
{
  return invSize;
}
