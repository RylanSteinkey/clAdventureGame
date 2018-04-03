///
/// YaDimSum 2720 project
///
/// \author Rylan Steinkey
/// \date Nov 8th, 2017
///
///
/// The Weapon class is used to create weapon for the player to use to attack
/// Weapon is a subclass of Item


#include "../headers/Item.h"
#include "../headers/Weapon.h"
#include <iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<string>
#include<time.h>
#include<sstream>
#include"../headers/Element.h" 
#include"../headers/Fire.h"
#include"../headers/Water.h"
#include"../headers/Normal.h"
#include"../headers/Earth.h"
#include"../headers/Air.h"
#include"../headers/FactoryElement.h"

using namespace std;
void Weapon::readFile(string inFile, int lvl, int seed)
{

   ///stores the number of items in the file which is the first line in the txt
   int listSize;

   ///stores the element in number form
   ///1=Fire 2=Water 3=Earth 4=Air 5=None
   int elementNumber;
   
   ///vector of strings to store all the lines in the file that match the
   ///specified level
   vector<string> storage;

   ///counter for how many items in the file matched the specified level
   ///opens the appropriate file
   ifstream weaponFile;
   weaponFile.open(inFile);

   
   weaponFile >> listSize;

   ///runs once for every item in the file
   for(int i = 0; i < listSize; i++)
   {
      string weaponItem;
      ///reads in the information of the item
      getline(weaponFile, weaponItem);
      if(weaponItem.empty())
	 continue; 

      ///checks if the first number, the level, matches the target level
      ///and stores it in a vector of strings if it does match
      if ( stoi (weaponItem )  == lvl)
      {
	 storage.push_back(weaponItem);
      }
   }
   //1=Fire 2=Water 3=Earth 4=Air 5=Normal

   ///Seeding the Random function. This is seeded with the time so that
   ///when you create items throughout the game they will be different.
   ///A constant integer has also been added to the seed to distinguish the
   ///bow staff and sword classes so that if you generate different weapon
   ///types at the same time they will have different elements and stats.
   srand(time(NULL)+seed);

   ///loads random item out of the vector and makes it a string stream
   istringstream itemChosen(storage[rand() % (storage.size())]  );

   ///loads members of the string stream into appropriate member variables
   ///in item.
   itemChosen >> itemLevel >> itemValue >> attackStat >> elementNumber;
   
   ///calls to the element factory to create the appropriate pointer and
   ///add it to the weapon
   element = FactoryElement::createElement(elementNumber);

   ///takes whatever is left in the line and loads it into the name
   getline(itemChosen,itemName);

   ///set defense and health stats to 0 so that when you call getStat()
   ///on an item it knows to return the only non zero function, which
   /// in this case is the attackStat
   defenseStat=0;
   healthStat=0;

   weaponFile.close();

}

Element* Weapon::getElementPointer() const
{
  return weaponElement;
}

string Weapon::getBaseType() const
{
  return "Weapon";
}
