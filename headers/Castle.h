/// \author Aditya Joshi
/// \date October 25th, 2017
///
///The Castle class is a subclass of Map. It will implement a Castle activity.
#ifndef CASTLE_H
#define CASTLE_H

#include "Map.h"
#include <fstream>

class Castle : public Map
{
  public:
   
   ///Behaviours
   ///Constructor to create a Castle which is the location for the Boss Monster battle.
   Castle();
   
   ///Destructor for Castle object.
   virtual ~Castle();

   ///Reads information from a file.
   /// \param[in] i is used to open and read config files
   void read(ifstream &i);
	
   ///Starts series of Monster battles.
   void startEvent();
   
  private:
};

#endif // CASTLE_H
