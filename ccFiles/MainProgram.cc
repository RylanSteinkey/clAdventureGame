///\Author: Rylan Steinkey
///\Date: Nov 27th

#include <iostream>
#include "../headers/Player.h"
#include "../headers/Inventory.h"
#include "../headers/Town.h"
#include "../headers/Armour.h"
#include "../headers/Item.h"
#include "../headers/Map.h"
#include "../headers/Potion.h"
#include "../headers/Road.h"
#include "../headers/Weapon.h"
#include "../headers/Bow.h"
#include "../headers/Sword.h"
#include "../headers/Staff.h"
#include "../headers/Character.h"
#include "../headers/Battle.h"
#include "../headers/FlyingMonster.h"
#include "../headers/FactoryItem.h"
#include <cctype>
#include "../headers/Exceptions.h"

using namespace std;

void clear();

int main(void)
{
   clear();
   cout << "\nWelcome to the YaDimSum 2720 Project: a text based RPG" << endl
	<< "\nEnter your name to start your adventure!" << endl;
   string playerName;
   
   ///gets playername
   getline(cin, playerName);
   
   ///makes a player charecter with said name
   Player *mainPlayer = new Player(playerName);
   clear();
   cout << "\nThe king has placed a bounty of 10,000 gold pieces on the fire dragon that made the north tower of his castle his new home. There is no hope for you to kill it but you know that the large bounty will bring warriors from around the kingdom, warriors that bring with them money that will be spent. You have decided to travel to the capital and have stopped at an inn along the way. When you walk inside the inn keeper instructs you to hang your weapon bag by the front door. You tell the inn keeper that you are unarmed and you are allowed inside. While in the inn you meet a wizard, a swordsman and an archer who are all travelling to try their hand at fighting the infamous dragon, after a few drinks you retire to your room\n" << endl;
   
   cout << "You awake in the night to a loud crash, you leave your room to check what the noise is. You hear a lady scream from outside and then you hear the scream of a monster who likely overturned the wagon of a night traveler. Beside the door you see the weapon bags of the wizard, the swordsman and the archer. Which do you search on your way out of the door?\n" << endl << "1: The Wizards bag" << endl << "2: The Swordsmans bag \n" << "3: The Archers bag" << endl;
   
   string startingWeaponChoice;
   string startingWeaponString;
   do{
      try{
	 cin >> startingWeaponChoice;
	 if(cin.fail() ||(!(startingWeaponChoice == "1" || startingWeaponChoice == "2" || startingWeaponChoice == "3")))
	 {
	    cin.clear();
	    cin.ignore();
	    clear();
	    throw invalidChoice();
	 }
	 else{
	    if(startingWeaponChoice == "1")
	       startingWeaponString = "Staff";
	    else if(startingWeaponChoice == "2")
	       startingWeaponString = "Sword";
	    else if(startingWeaponChoice == "3")
	       startingWeaponString = "Bow";
	    else
	       cout << "You need to enter 1, 2, or 3. Please try again" << endl;
	 }
      }
      catch(invalidChoice &n)
      {
	 cout << n.what() << endl;
	 cout <<  "\nWhich do you search on your way out of the door?\n" << endl << "1: The Wizards bag" << endl << "2: The Swordsmans bag \n" << "3: The Archers bag\n" << endl;
	 
      }
   }
   while(!(startingWeaponChoice == "1" || startingWeaponChoice == "2" || startingWeaponChoice == "3"));
   
   mainPlayer->getInventory()->addItem(FactoryItem::createItem(startingWeaponString, 1));
   mainPlayer->changeWeapon(mainPlayer->getInventory()->getInventoryPointer(0));
   clear();
   cout << "\nYou have found a " <<  mainPlayer->getWeapon()->getType()<< "!" << endl
	<< "\nYou open the door to see a small skeleton holding an axe above the women who you heard scream. You charge straight at the skeleton only to trip a on chest that had fallen off of the womens overturned wagon. You dive head first into the skeleton, dropping it into a pile of bones and knocking yourself unconsious." << endl << "You awake in the inn surrounded by the other guests. The warrior with whom you 'borrowed' their weapon has told you that you can keep it. The shopkeeper has rewarded you with a potion for your heroism, this may be consumed during a battle to restore a section of your health. The women that you saved has given you a piece of armor. After a short recovery you inform everyone that you will continue along your way to the capital." << endl << "The wizard says, 'Remember, Fire does bonus damage against earth monster, water beats fire, earth beats air and air beats water. Also keep in mind what weapon you use as Swords do extra damage against melee monsters just as staffs beat undead and bows beat flying. While a sword can still hit a flying monster when they get near you, you will be at a significant disadvantage.'" << endl << "\nAs you set off on your journey you look into you backpack, this is what is in your inventory:\n" << endl;
   
   mainPlayer->getInventory()->addItem(FactoryItem::createItem("Potion", 1));
   mainPlayer->getInventory()->addItem(FactoryItem::createItem("Armour", 1));
   
   mainPlayer->changeArmour(mainPlayer->getInventory()->getInventoryPointer(2));
   mainPlayer->printInventory();
   
   cout << "\nEnter C to continue down the road\n";
   
   
   do{
      try{
	 cin >> startingWeaponChoice;
	 if(cin.fail() ||(!(startingWeaponChoice == "c" || startingWeaponChoice == "C")))
	 {
	    cin.clear();
	    cin.ignore();
	    clear();
	    throw invalidChoice();
	 }
	 else{
	    if(startingWeaponChoice == "C")
	       cout << "this wont be read";
	    else
	       cout << "You need to enter C\n";
	 }
      }
      catch(invalidChoice &n)
      {
	 cout << n.what() << endl;
	 cout <<  "You need to enter C\n";
	 
      }
   }
   while(!(startingWeaponChoice == "C" || startingWeaponChoice == "c" ));
   
   
   //loop until player is strong enough
   while((mainPlayer->getLevel())<10)
   {
      Road* road0 = new Road();
      road0->startBattle(mainPlayer);
      delete road0;
      
      Town* town0 = new Town();
      town0->interface(mainPlayer);
      delete town0;
   }
   
   
   clear();
   
   ///Final Boss:
   Road* road1 = new Road();
   
   road1->battleSequence(mainPlayer, "Boss");
   
   delete road1;
   
   
   cout << "Wow you actually took the time to make it all of the way to the final boss AND beat it... why did you do this, there is so much more you could be doing in your life but whatever, here is your 10,000 gold, which you cant actually do anything with, cause the game is over." << endl;
   
   delete mainPlayer;
}

void clear()
{
   for (int i=0; i<75; i++)
      cout << endl;
}
