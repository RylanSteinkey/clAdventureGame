/// YaDimSum 2720 project
/// \author Joshua Pepple
/// \date October 24th, 2017
///
///
/// The NPC class inherits the Character class. It creates the Non-Playable Characters in the game which the Player object interacts with.

#ifndef NPC_H
#define NPC_H

#include "Character.h"
#include "Screen.h"
#include <iostream>

using namespace std;

///The NPC Object has a read function and a display function and inherits all other input information from its Superclass

class NPC : public Character
{
public:
   ///Behaviours
   
   /// constructs an NPC object and randomly generates Inventory by calling an Inventory Object function
   NPC(int playerLevel);
 
   /// This is the destructor for the NPC object
   ~NPC();
};
#endif
