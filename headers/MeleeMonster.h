/// YaDimSum 2720 project
/// \author Joshua Pepple

/// This class inherits the Monster class and specifies a MeleeMonster Object 

#ifndef MELEEMONSTER_H
#define MELEEMONSTER_H

#include <iostream>
#include "Monster.h"
#include <fstream>

using namespace std;

class MeleeMonster : public Monster
{
  public:
   /// This is the constructor for a MeleeMonster Object and it takes the level of the Object to be created
      /// \param[in] int which is the level of the Object to be created
   MeleeMonster(int);

   /// This is the destructor for the MeleeMonsteer Object
   ~MeleeMonster();

   /// This function is inheritted from Monster base class and it returns the type of the MeleeMonster [Melee]
      /// \return string which is the Monster type              
   string getType() const; 
};

#endif // MELEEMONSTER_H

