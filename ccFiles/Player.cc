/// YaDimSum 2720 project
/// \author Joshua Pepple
/// \date October 24th, 2017
///
///
/// The Player class inherits BattleCharacter class. This creates the Player Object for User to control which interacts with other classes.  

#include "../headers/Player.h"
#include "../headers/Inventory.h"
#include "../headers/Character.h"
#include "../headers/BattleCharacter.h"
#include "../headers/Exceptions.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/// constructs a new Player object using User's name
/// \param[in] name, the name of the Player character. 
Player::Player(string name)
{
	charName = name;
	charLevel = 1;
	playerGold = 1;
	charAttack = 10;
	if(name=="SPEEDRUN"||name=="SPEED RUN"||name=="speedrun"||name=="speed run"|| name=="Speed run" || name == "Speedrun" ||name== "speedRun")
	   charAttack = 100;
	charDefense = 5;
	EXP = 4;
	charHealth = 50;
	charMaxHealth = 50;
	charInventory = new Inventory(10);	
}

/// destroys the Player object
Player::~Player()
{
   delete charInventory;
}

/// returns the Player's EXP
/// \return Player's EXP    
int Player::getEXP() const
{
    return EXP;
}

/// returns the Player's gold
/// \return Player's gold        
int Player::getGold() const
{
    return playerGold;
}

/// increases the Player's EXP by the integer passed
/// \param[in] increaseBy is the integer to increase Player EXP by        
void Player::addEXP(int increaseBy)
{
    EXP += increaseBy;
}


/// checks the Player's EXP to see if they satisfy the condition to go up a Level
void Player::levelUp()
{
   if (EXP > (5*(pow(1.5,(charLevel-1)))))
      {
	 charAttack += 1;
	 charDefense += 1;
	 charMaxHealth +=5;
	 charHealth += 5;
	 playerGold += 5;
	 charLevel++;
	 cout << "You have leveled up! You are now level " << charLevel << endl;
      }
}

/// increases the Player's gold by the integer passed
/// \param[in] increaseBy is the integer to increase Player gold by 
void Player::changeGold(int increaseBy)
{
    playerGold += increaseBy;
}

///increases the Player's attack stat by the integer passed
/// \param[in] increaseBy is the integer to increase Player attack stat by   
void Player::changeAttack(int increaseBy)
{
    charAttack += increaseBy;
}

///increases the Player's defense stat by the integer passed
/// \param[in] increaseBy is the integer to increase Player defense stat by  
void Player::changeDefense(int increaseBy)
{
    charDefense += increaseBy;
}

/// changes Player's primary weapon to Weapon referred to by Item pointer. Only allowed for Weapons as only Weapons can be wielded and Player and Weapon have to be on same Level or Player is on higher level
/// \param[in] secondary is the weapon to swap to by making wieding point to it
void Player::changeWeapon(Item* secondary)
{
   if(secondary->getBaseType() == "Weapon")
   {
      if (charLevel >= secondary->getItemLevel())
	 wielding = secondary;
      else
	 cout << "This Item's level is above your level. \n";
   }
   else
      throw invalidExchange("Not a weapon Item");
}

/// changes Player's primary armor to Armor referred to by Item pointer. Only allowed for Armors as only Amours can be worn and Player and Weapon have to be same Level or Player is on a higher level
/// \param[in] ar, the armor to swap to by making wearing point to it 
void Player::changeArmour(Item* ar)
{
  
   if(ar->getBaseType() == "Armour")
   {
      if (charLevel >= ar->getItemLevel())
	 wearing = ar;
      else
	 cout << "This Item's level is above your level. \n";
   }
   else
      throw invalidExchange("Not an armour Item");
}

/// This function returns a pointer to what Item [Weapon] the Player is wielding
/// \return wielding which is a pointer to current weapon  
Item* Player::getWeapon() const
{
   return wielding;
}


/// This function returns a pointer to what Item [Armour]\ the Player is wearing
/// \return wearing which is a pointer to current armour        
Item* Player::getArmour() const
{
   return wearing; 
}
