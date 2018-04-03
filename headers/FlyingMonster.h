/// YaDimSum 2720 project
/// \author Joshua Pepple

/// This class inherits the Monster class and specifies a FlyingMonster Object

#ifndef FLYINGMONSTER_H
#define FLYINGMONSTER_H

#include <iostream>
#include "Monster.h"
#include <fstream>

using namespace std;

class FlyingMonster : public Monster
{
  public:
   /// This is the constructor for a FlyingMonster Object and it takes the level of the Object to be created
   /// \param[in] int which is the level of the Object to be created
   FlyingMonster(int);

   /// This is the destructor for the FlyingMonster Object
   // ~FlyingMonster();

   /// This function is inheritted from Monster base class and it returns the type of the FlyingMonster [Flying]
   /// \return string which is the Monster type 
   string getType() const;
};

#endif // FLYINGMONSTER_H
