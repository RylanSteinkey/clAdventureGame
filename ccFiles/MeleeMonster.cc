/// YaDimSum 2720 project
/// \author Joshua Pepple

/// This class inherits the Monster class and specifies a MeleeMonster Object   

#include "../headers/MeleeMonster.h"
#include <fstream>

using namespace std;

/// This is the constructor for a MeleeMonster Object and it takes the level of the Object
/// to be created
/// \param[in] int which is the level of the Object to be created 
MeleeMonster::MeleeMonster(int level)
{
   readFile("../TextFiles/meleeMonster.txt", level);
}

/// This is the destructor for the MeleeMonsteer Object    
MeleeMonster::~MeleeMonster()
{
   delete charInventory;
}

/// This function is inheritted from Monster base class and it returns the type of
/// the MeleeMonster [Melee]
/// \return string which is the Monster type     
string MeleeMonster::getType() const
{
   return "Melee";
}
