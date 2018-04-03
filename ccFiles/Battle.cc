#include "../headers/Battle.h"
#include "../headers/Screen.h"
#include "../headers/Monster.h"
#include "../headers/Player.h" 
#include "../headers/BattleCharacter.h" 
#include "../headers/Character.h"
#include "../headers/Weapon.h"
#include "../headers/Element.h"
#include "../headers/Fire.h"
#include "../headers/Water.h"
#include "../headers/Earth.h"
#include "../headers/Air.h"
#include "../headers/Normal.h" 
#include "../headers/Armour.h"
#include "../headers/Exceptions.h"
#include <typeinfo>
#include <fstream>
#include <sstream>
#include <iostream> 
#include <string> 
#include <map>
#include <iomanip> 
#include <cstdint>
#include <limits>
#include <stdexcept> 
#include <assert.h>
using namespace std;

Battle::Battle()
{
}


void Battle::stats(Player* player, Monster * monster)
{

   //columns are 32 by 30 right now" 
   cout<<setw(22)<<left<<player->getName()<<setw(10) << " "<< setw(10) << "   vs"<<setw(30)<<left<<monster->getName()<<'\n'
       <<setw(15)<<left<<"Current Health:"<<setw(17)<<right<<player->getHealth()<<setw(10)<<" "
       <<setw(15)<<left<<"Current Health:"<<setw(17)<<right<<monster->getHealth()<<'\n'

       <<setw(15)<<left<<"Max Health:"<<setw(17)<<right<<player->getMaxHealth()<<setw(10)<<" "
       <<setw(15)<<left<<"Max Health:"<<setw(17)<<right<<monster->getMaxHealth()<<setw(10)<<'\n'

       <<setw(15)<<left<<"Attack: "<<setw(17)<<right<<player->getAttack()<<setw(10)<<" "
       <<setw(15)<<left<<"Attack: "<<setw(17)<<right<<monster->getAttack()<<setw(10)<<'\n'

       <<setw(15)<<left<<"Defense: "<<setw(17)<<right<<player->getAttack()<<setw(10)<<" "
       <<setw(15)<<left<<"Defense: "<<setw(17)<<right<<monster->getAttack()<<setw(10)<<'\n'

       <<setw(7)<<left<<"Weapon:"<<setw(25)<<right <<player->getWeapon()->getItemName()<<setw(10)<<" "
       <<setw(15)<<left<<"Type: " <<setw(17)<<right<<monster->getType()<< setw(10)<<'\n'

       <<setw(15)<<left<<"Weapon Element:"<<setw(17)<<right<<player->getWeapon()->getElementPointer()->getElement() <<setw(10)<<" "
       <<setw(15)<<left<<"Element:"<<setw(17)<<right<<monster->getElementPointer()->getElement()<<setw(10)<<'\n'

       <<setw(10)<<left<<"Armour:"<<setw(22)<<right<<player->getArmour()->getItemName()<<setw(10)<<" "<<endl;
}

void Battle::playerAttack(Player* player, Monster* monster)
{
   
   if(isDead(player) )
      throw battleError("Trying to fight as a dead man - DEVELOPER ERROR " ) ;
   if(isDead(monster))
      throw battleError("trying to fight a dead monster - DEVELOPER ERROR" ); 
   //Get Monster defense
   int monsterDefense = 0;
   monsterDefense = monster->getDefense();
   //Total damage 
   int playerTotalDamage = 0;
   
   playerTotalDamage = monsterDefense - findAttackerDamage(player, monster);
   if(playerTotalDamage >0)
      playerTotalDamage = 0;

   // don't want that player healing 
   assert( !(playerTotalDamage > 0)   ) ;
      
   cout << "You dealt " << playerTotalDamage << " damage" << endl;
   
   monster->changeHealth(playerTotalDamage);
      
   //no negative healths please ..
   if(monster->getHealth() < 0)
   {
      int setZero = monster->getHealth(); 
      monster->changeHealth(setZero);
   }
   

   //*****************************************************************************************************************
}

void Battle::monsterAttack(Player* player, Monster* monster)
{
  
   if(player->getHealth() == 0 )
      throw battleError("You're a dead man  - DEVELOPER ERROR " ) ;
      
   if(isDead(monster))
      throw battleError("Dead monster attacking - DEVELOPER ERROR" );
      
   //Get Player defense
   int playerDefense = 0;
   playerDefense = player->getDefense() + player->getArmour()->getStat();
   
   //Total damage
   int monsterTotalDamage = 0;
   
   monsterTotalDamage = playerDefense - findAttackerDamage(monster);

   if(monsterTotalDamage > 0)
      monsterTotalDamage = 0;

   //We do not want the monster to be healing ..
   assert(!(monsterTotalDamage > 0) );

   
   cout << monster->getName() << " dealt " << monsterTotalDamage << " damage" << endl; 
   player->changeHealth(monsterTotalDamage);

}

int Battle::findAttackerDamage(Monster* monster)
{
   return monster->getAttack();
}

int Battle::findAttackerDamage(Player* player, Monster* monster)
{
   //File Names 
   string elementBonusFileName = "../TextFiles/ElementBonus.txt";
   string typeBonusFileName = "../TextFiles/TypeBonus.txt";
   
   // Get multipliers for player damage

   //element multiplier 
   double playerElementMultiplier = 1;

   playerElementMultiplier = getBonus(elementBonusFileName, player->getWeapon()->getElementPointer()->getElement(), monster->getElementPointer()->getElement());

   //type multiplier 
   double playerTypeMultiplier = 1; 
   playerTypeMultiplier = getBonus(typeBonusFileName, player->getWeapon()->getType(), monster->getType());   

   //Get the weapon damage 
   int playerWeaponDamage = 0;
   playerWeaponDamage = player->getWeapon()->getStat();

   //Player damage 
   int playerDamage = 0;
   playerDamage = (player->getAttack() + playerWeaponDamage) * playerElementMultiplier * playerTypeMultiplier;

   return playerDamage; 
   
   
}


bool Battle::isDead(BattleCharacter* character) const
{
   if( character->getHealth() <= 0 )
      return true;
   else
      return false; 
} 

bool Battle::checkType(string fileString, string stringInType) const
{
 
   if( fileString == stringInType )
   {
      return true;
   }
   return false; 
}

double Battle::getBonus(string bonusFileName, string attackerTypeIn, string defendingTypeIn) const
{

   // initial bonus is only a multiplier of 1
   double bonus = 1;
      
   ifstream bonusFile;
   bonusFile.open(bonusFileName);
      
   if(!bonusFile.good())
      throw invalidFile("DEVELOPER ERROR: FILE DOES NOT EXIST");
      
   string line;
   //  getline(bonusFile, line);
   //cout << line  << endl; 
 
   while(getline(bonusFile, line))
   {
      //ignore comments / empty lines
      // cout << line << endl; 
      if(line[0] != '#' && !line.empty())
      {
	 istringstream bonusLine(line);
	 string attackingType, defendingType; 
	 double modifier;
	 bonusLine >> attackingType >> defendingType >> modifier;
	 if(checkType(attackingType, attackerTypeIn))
	 {
	    if(checkType(defendingType, defendingTypeIn))
	       return modifier * bonus;
	    else
	       continue; 
	 }
	 else
	    continue;
      }
   }
   bonusFile.close(); 
   return bonus;

}

