// YaDimSum 2720 project
/// \author Joshua Pepple
/// \date October 24th, 2017
///
///
/// The NPC class inherits the Character class. It creates the Non-Playable Characters in the game which the Player object interacts with. 

#include "../headers/NPC.h"
#include <iostream>

using namespace std;

/// constructs an NPC object and randomly generates Inventory by calling an Inventory Object function            
NPC::NPC(int playerLevel)
{
   charName = "Kwin-E-Mart";
   charInventory = new Inventory(30);
   charInventory->generateInventory(playerLevel);
}

/// This is the destructor for the NPC object       
NPC::~NPC()
{
   delete charInventory;
}
