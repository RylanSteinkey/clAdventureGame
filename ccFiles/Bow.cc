///
/// YaDimSum 2720 project
///
/// \author Rylan Steinkey
/// \date Nov 8th, 2017
///
///
/// The Bow class, used for bow which counter flying monsters
/// Bow is a subclass to the weapon class
///

//#include "Item.h"
//#include "Weapon.h"
#include "../headers/Bow.h"
#include <iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<string>
#include<time.h>
#include<sstream>
#include"../headers/Element.h" 
#include"../headers/Fire.h"
#include"../headers/Water.h"
#include"../headers/Normal.h"
#include"../headers/Earth.h"
#include"../headers/Air.h"
#include"../headers/FactoryElement.h"

using namespace std;

///constructor: Takes in the level that the created bow should be and opens the bow file
/// and pulls a random bow out of that file that matches the level.
/// \param[in] level the level to make the sword
Bow::Bow(int lvl)
{
   readFile("../TextFiles/bows.txt", lvl, 46988);
}


string Bow::getBaseType() const
{
   return "Weapon";
}


string Bow::getType() const
{
  return "Bow";
}
