///
/// YaDimSum 2720 project
///
/// \author Rylan Steinkey
/// \date Nov 8th, 2017
///
///
/// The Armour class, used by the player to get a boost in defense
/// Armour is a subclass to the weapon class
///

#include "../headers/Item.h"
#include "../headers/Armour.h"
#include <iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<string>
#include<time.h>
#include<sstream>

using namespace std;

///constructor: take the level in which the created item should be, opens the armour file
/// and picks a random item out of the file and creates it
/// \param[in] level the level in which to make the armour
Armour::Armour(int lvl)
{  
   ///stores the number of items in the file which is the first line in the txt
   int listSize;
   string inArmour; 
   ///vector of strings to store all the lines in the file that match the
   ///specified level
   vector<string> storage;

   ///counter for how many items in the file matched the specified level
   ///opens the appropriate file
   ifstream armourFile;
   armourFile.open("../TextFiles/armour.txt");

   /// loads in the first line of the file which contains the number of items
   armourFile >> listSize;
   
   ///runs once for every piece of armour in the file
   for(int i = 0; i < listSize; i++)
   {
      string armourItem;
      ///reads in the first item in the file
      getline(armourFile, armourItem);

      ///makes sure that the line is not empty
      if(armourItem.empty())
	 continue; 

      ///checks if the first number, the level, matches the target level
      ///and stores it in a vector of strings if it does match
      if ( stoi (armourItem )  == lvl)
      {
	 storage.push_back(armourItem);
      }
   }

   ///seeding the random function, keep in mind that if you call to create
   /// two pieces of armor in the same second they will be the same item,
   ///instead call to create one item at the player level and one at the
   ///player level + 1
   srand(time(NULL));

   ///loads random item out of the vector and makes it a string stream
   istringstream itemChosen(storage[rand() % (storage.size()) + 0]  );

   ///loads members of the string stream into appropriate member variables
   ///in item.
   itemChosen >> itemLevel>> itemValue >> defenseStat;

   ///takes whatever is left in the line and loads it into the name
   getline(itemChosen,itemName);

   ///set attack and health stats to 0 so that when you call getStat()
   ///on an item it knows to return the only non zero function, which
   /// in this case is the defenseStat
   attackStat=0;
   healthStat=0;

   armourFile.close();
}


string Armour::getType() const
{
   return "Armour"; 
}

string Armour::getBaseType() const
{
  return "Armour";
}
