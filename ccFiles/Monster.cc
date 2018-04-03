/// YaDimSum 2720 project
/// author: Joshua Pepple

/// This class inherits the BattleCharacter class directly and indirectly inherits the Character class.
/// It is an Abstract class that adds more functions adding functionalities after
/// inheriting from its base classes, some of which are pure virtual and have to be overwritten by subclasses.                                                 

#include "../headers/Monster.h"
#include "../headers/FactoryElement.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <sstream>

using namespace std;

/// This is the destructor for the Monster Object        
Monster::~Monster()
{
   delete charInventory;
   delete element;
}

/// This function takes a string which is the name of the Monster config file to read and the level of Monster required
/// \param[in] string which is the name of file to open
/// \param[in] int which is the level of the Monster to be created
void Monster::readFile(string inFile, int level)
{
   vector <string> lines;

   if(level ==1 || level ==2)
   {
      srand (time(NULL));
      int odds = rand() % 2;
      if( odds == 0)
	 inFile = "../TextFiles/meleeMonster.txt";
      else
	 inFile = "../TextFiles/undeadMonster.txt";
   }
   ifstream extract;
   extract.open(inFile);

   int count = 0;

   extract >> count;

   int line = 0;
   
   while(line <= count)
   {
      int lvl;
      extract >> lvl;
      
      if (lvl == level)
      {
	 string store;
	 getline(extract, store);
	 lines.push_back(store);
	 charLevel = lvl;
      }
      else
      {
	 string discard;
	 getline(extract, discard);
	 line++;
      }
   }

   
   int decide = (rand() % lines.size());

   stringstream ss(lines[decide]);
   string ele;
   ss >> charHealth >> charAttack >> charDefense >> ele;

   charMaxHealth = charHealth;
   
   element = FactoryElement::createElement(ele); 
   
   charInventory = new Inventory(1);
   
   charName = getType() + " ";
   
   if (ele != "Normal")
      charName += ele+ " ";
   charName +="Monster";
   
   extract.close();
}

/// This function returns a pointer to the Element type of a Monster Object
/// \return element                   
Element* Monster::getElementPointer() const
{
   return element;
}
