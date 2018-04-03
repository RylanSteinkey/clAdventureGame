/*!
  CPSC 2720 YaDimSum Group Project
  \author Aditya Joshi
  \data Nov 21st, 2017

  The Castle class is used to implement Castle activity, which is the location
  for the Boss Monster battle.
*/
#include "Map.cc"
#include "Battle.cc"
#include "Inventory.cc"
#include "../headers/Map.h"
#include "../headers/Castle.h"
#include "../headers/Battle.h"
#include "../headers/Inventory.h"
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

/*! Constructor to create a Castle which is the location for the Boss Monster
battle. */
Castle::Castle(){

};

/// Destructor for the Castle Object.
Castle::~Castle(){

};

/// Read information from a file.
/// \param[in] is used to open and read config files
Castle::read(ifstream &i){
   int listSize;
   string inLocationNames;

   ///Store all the lines in the location file in a vector.

   vector<string> store;

   ifstream locationNameFile;

   locationNameFile.open("../TextFiles/locationNames.txt");
   locationNameFile >> listSize;

   for(int i = 0; i < listSize; i++)
   {
   string castleName;
   ///Read in the location names of Castle
   getline(locationNameFile, castleName);
   if(castleName.empty())
      continue;

   storage.push_back(castleName);
   }

   srand(time(NULL));
   istringstream castleNameChosen(storage[rand() % (storage.size()) + 0] );
   castleNameChosen;
   getline(castleNameChosen,castleName);
   castleName = cName;
};

/// Start series of Monster battles.
Castle::startEvent(){
    ///Clear the screen when the monster battle is engaged.
    system ("CLS");
    ///Begin an attack between the player and the boss monster.
    battle.attack(Player, Monster);

};
