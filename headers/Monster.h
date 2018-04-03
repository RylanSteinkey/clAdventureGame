/// YaDimSum 2720 project
/// author: Joshua Pepple

/// This class inherits the BattleCharacter class directly and indirectly inherits the Character class. It is an Abstract class that adds more functions adding functionalities after
/// inheriting from its base classes, some of which are pure virtual and have to be overwritten by subclasses.

#ifndef MONSTER_H
#define MONSTER_H
#include "BattleCharacter.h"
#include "Element.h"

class Monster : public BattleCharacter
{
  public:

   /// This is the destructor for the Monster Object
   virtual ~Monster();

   /// This is a pre virtual function that gets the type of a Monster Object [to be overwritten and used by the Subclasses of Monster to return their type]
   /// \return string which is the Monster Object's type
   virtual string getType() const = 0;

   /// This function takes a string which is the name of the Monster config file to read and the level of Monster required
   /// \param[in] string which is the name of file to open
   /// \param[in] int which is the level of the Monster to be created
   void readFile(string, int);

   /// This function returns a pointer to the Element type of a Monster Object
   /// \return element
   Element * getElementPointer() const;

  protected:
   /// This is a pointer to the Element type of a Monster Object
   Element * element;
};
#endif // MONSTER_H
