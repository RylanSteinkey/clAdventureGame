///
/// YaDimSum 2720 project
///
/// \author Rylan Steinkey
/// \date Nov 8th, 2017
///
///
/// The Staff class, used for staff which counter undead monsters
/// Staff is a subclass to the weapon class
///

//#include "Item.h"
//#include "Weapon.h"
#include "../headers/Staff.h"
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

///constructor: Takes in the level that the created staff should be and opens the staff file
/// and pulls a random staff out of that file that matches the level.
/// \param[in] level the level to make the staff
Staff::Staff(int lvl)
{
   readFile("../TextFiles/staffs.txt", lvl, 9432);
}

string Staff::getType() const
{
   return "Staff"; 
}

string Staff::getBaseType() const
{
  return "Weapon";
}
