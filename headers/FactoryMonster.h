/// YaDimSum 2720 project
/// \author Kip Jay

/// This class uses the Factory pattern to create Monsters of different types by randomization
#ifndef FACTORYMONSTER
#define FACTORYMONSTER

#include "Monster.h" 
#include <string>

using namespace std;

class FactoryMonster
{
  public:

   /// This function is a static method takes a string which is used to check whether it is the Boss Monster [which is the strongest] or just a regular Monster
   /// where the int passed is used to pick a regular  monster level based on the Player Object's level and returns the new Monster
   /// \param[in] string which is used to differentiate between a Boss and a regular Monster
   /// \param[in] int which is used to select the Monster level for creation
   /// \return Pointer to a new Monster Object
   static Monster* createMonster(const string&, int);

};

#endif 
