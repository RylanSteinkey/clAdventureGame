/*!
  CPSC 2720 YaDimSum Group Project

  The Road class is used to implement a Road activity, which is a subclass of
  the Map class.
*/
#include "../headers/Road.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "../headers/Screen.h"
#include "../headers/Battle.h"
#include "../headers/Map.h"
#include "../headers/Inventory.h"
#include "../headers/NPC.h"
#include "../headers/Player.h"
#include "../headers/Monster.h"

using namespace std;


/// Constructor to create a Road.
Road::Road()
{
   
}


void Road::startBattle(Player* player)
{
   for(int i =0; i<50; i++)
      cout << endl;
   
   cout << "While walking along the road to the next town you notice a shape moving towards you off in the distance, you prepare for battle.\n \n";
  
   battleSequence(player, "notABoss");
   
   cout << "\nYou continue down the road to the next town\n";
}

