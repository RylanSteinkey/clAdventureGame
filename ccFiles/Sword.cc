///
/// YaDimSum 2720 project
///
/// \author Rylan Steinkey
/// \date Nov 8th, 2017
///
///
/// The Sword class, used for swords which counter melee monsters
/// Sword is a subclass to the weapon class
///

//#include "../headers/Item.h"
//#include "../headers/Weapon.h"
#include "../headers/Sword.h"
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

///constructor: Takes in the level that the created sword should be and opens the sword file
/// and pulls a random sword out of that file that matches the level.
/// \param[in] level the level to make the sword
Sword::Sword(int lvl)
{
   readFile("../TextFiles/swords.txt", lvl, 32468);
}


string Sword::getType() const
{
   return "Sword";
}

