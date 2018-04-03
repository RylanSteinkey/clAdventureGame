/// YaDimSum 2720 project
/// \author Joshua Pepple

/// This class inherits the Monster class and specifies an UndeadMonster Object

#include "../headers/UndeadMonster.h"
#include <string>

/// This is the constructor for a UndeadMonster Object and it takes the level of the Object to be created
/// \param[in] int which is the level of the Object to be created 
UndeadMonster::UndeadMonster(int level)
{
   readFile("../TextFiles/undeadMonster.txt", level);
}

/// This is the destructor for the FlyingMonster Object         
UndeadMonster::~UndeadMonster()
{
   delete charInventory;
}


/// This function is inheritted from Monster base class and it returns the type of the UndeadMonster [Undead]
/// \return string which is the Monster type    
string UndeadMonster::getType() const
{
    return "Undead";
}
