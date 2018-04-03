/// YaDimSum 2720 project
/// \author Joshua Pepple

/// This class inherits the Monster class and specifies an UndeadMonster Object  

#ifndef UNDEADMONSTER_H
#define UNDEADMONSTER_H

#include <iostream>
#include "Monster.h"
#include <fstream>

using namespace std;

class UndeadMonster : public Monster
{
  public:
   /// This is the constructor for a UndeadMonster Object and it takes the level of the Object to be created
   /// \param[in] int which is the level of the Object to be created       
   UndeadMonster(int);
   
   /// This is the destructor for the FlyingMonster Object           
   ~UndeadMonster();

   /// This function is inheritted from Monster base class and it returns the type of the UndeadMonster [Undead]
      /// \return string which is the Monster type    
   string getType() const; 
};

#endif //UNDEADMONSTER_H


