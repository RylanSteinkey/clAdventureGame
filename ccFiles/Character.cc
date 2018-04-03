/// YaDimSum 2720 project
/// \author Joshua Pepple
/// \date October 24th, 2017
///
///
/// The Character class is an abstract class which forms the basis for other Characters
/// and stores some basic information that these Characters have in common	

#include "../headers/Character.h"
#include "../headers/Inventory.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/// This returns a pointer to the Character's inventory
/// \return charInventory               
Inventory * Character::getInventory()
{
   //cout << getName() << endl;
   //charInventory->displayInventory();
   return this->charInventory;
}


/// This returns the name of the Character Object
/// \return charName         
string Character::getName() const
{
   return charName;
}

/// This function prints the Inventory of the Character Object     
void Character::printInventory()
{
   cout << getName() << "'s Inventory: " << endl;
   cout <<"#  |Name of Item              |Type     |Element  |";
   cout <<"Lvl  |Atk  |Def  |HP   |$    |"<<endl;
   cout <<"--------------------------------------------------";
   cout <<"------------------------------";
   cout <<endl;
   
   charInventory->displayInventory();
}

