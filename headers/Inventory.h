///
/// CS 2720 YaDimSum Group Project 
///
/// \author Dallan McCarthy 001175764
/// \date Oct 24, 2017
///
///
/// The Inventory class is used to create an inventory object to 
/// store Character Items and generate their Inventories
///

#ifndef INVENTORY_H
#define INVENTORY_H

#include "Screen.h"
#include "Item.h"
#include <iostream>
#include <fstream>
#include <vector>



using namespace std;

/// The Inventory class will interact with all of the Character objects
/// due to it generating their Inventories. It will interact
/// with the Item objects each Character object has due to it holding
/// their Item pointers 
/// It will also display to screen the Inventroy

class Inventory
{
  private:
   /// ATTRIBUTES:
   ///
   /// Stores the full capacity of Character Inventory 
   int invCapacity;
   
   /// Stores the number of slots being used in Character Inventory
   int invSize;
   
   /// A vector of Item pointers to store all character items
   vector<Item*> charInv;

   
  public:
   /// BEHAVIOURS:
   ///
   /// Constructor, that takes a parameter (length) and initializes
   /// the vector of item pointers given the capacity of Character Inventory
   /// \param[in] length, which is the capacity of the Inventory object
   Inventory(int length=10);
   
   /// Function to display Character's inventroy to Screen at x,y coordinates.
   /// \param[in] x, which is the height of the screen
   /// \param[in] y, which is the width of the screen
   /// \param[in] screen, which is the Screen
   void displayInventory();
   
   /// Destructor to delete inventory objects
   ~Inventory();
   
   /// ACCESSORS:
   /// returns the number of free spaces in the characters inventory
   /// \return invCapacity - invSize
   int getFreeSpace();
   
   /// MUTATORS:
   /// 
   /// Adds item purchased or looted to the characters inventory
   /// \param[in] item is the Item object to be added to the Inventory
   void addItem(Item *aItem);
   
   /// Remove items from inventory
   /// \parm[in] item is the Item object to be removed from the inventory
   void removeItem(int place);
   
   /// Function that populates the characters inventory with random
   /// items (used for NPC character and Monster character)
   /// \parm[in] int character level
   void generateInventory(int pLvl);

   Item * getInventoryPointer(int spot);

   int getCurrentSize(); 
   
};

#endif
