#include "../headers/FactoryMonster.h"
#include "../headers/UndeadMonster.h"
#include "../headers/MeleeMonster.h"
#include "../headers/FlyingMonster.h" 
#include <string>

using namespace std;

Monster* FactoryMonster::createMonster(const string& monster, int level)
{
   try
   {
      if(monster == "Flying")
	 return new FlyingMonster(level);
      else if(monster == "Melee")
	 return new MeleeMonster(level);
      else if(monster =="Undead")
	 return new UndeadMonster(level);
      else
	 throw "Invalid Monster";
   }
   catch(string error)
   {
      cout << "invalid monster attempted";
   }

   return NULL; 
}
      
      
