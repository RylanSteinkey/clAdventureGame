// YaDimSum 2720 project
/// \author Joshua Pepple

/// This class inherits the Monster class and specifies a FlyingMonster Object  

#include "../headers/FlyingMonster.h"

/// This is the constructor for a FlyingMonster Object and it takes the level of the Object
/// to be created
/// \param[in] int which is the level of the Object to be created 
FlyingMonster::FlyingMonster(int level)
{
   readFile("../TextFiles/flyingMonster.txt", level);
}

/// This is the destructor for the FlyingMonster Object           
/*FlyingMonster::~FlyingMonster()
{
  delete charInventory;
}
*/
/// This function is inheritted from Monster base class and it returns the type of the
/// FlyingMonster [Flying]
/// \return string which is the Monster type 
string FlyingMonster::getType() const
{
   return "Flying";
}
