/// YaDimSum 2720
/// \author Dallan Mccarthy
/// \author Kip Jay
/// \author Joshua Pepple [Minor edits]
///
///The Map class is an abstract base class which has the building blocks for locations the Player will visit during the course of the game
///It contains most of the functions required by Road and cont

#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <iostream>
#include "Item.h"
#include "Player.h"
#include "Character.h"
#include "Monster.h"
#include <string>
#include "Battle.h" 

using namespace std;

class Map
{
    public:
   ///Behaviours
   virtual ~Map() {}
   
   /// This is the function to buy an item or loot and item from a character
   /// we will use this to add an item to a characters inventory
   /// \param[in] int of where the Item object type, Player.Inventory[x]
   /// \param[in] character that will be adding item
   /// \param[in] character that will be removing item
   virtual void buyItem(int c, Character * char1, Character * char2);
      
   ///Initates battle sequence for road / castle classes
   /*** This is a map battle sequence
	where the player gets to fight a monster or boss
	\parmin[in] player - pointer to player for mutation
	\parmin[in] isBoss - tells the battle sequence whether
	it is fighting a monster that is a boss or not
	\parmin[out] - player hp/level/gold is mutated and opportunity
	to get items and expand their inventory as well */ 
   void battleSequence(Player *player, string isBoss);
   
   /// lets player look at their inventory
   /*** The player may change weapons/armour in their inventory
	they can also drink health potions or drop items that they
	do not want
	\parmin[in] player - pointer to the player whose inventory
	needs to be accessed*/ 
   void inventoryActivity(Player * player);

   /// switch armour or weapon for player
   /*** lets the player switch either their armour
	or weapon. It takes the basetype of the item
	as a string
	\parmin[in] player - the user's character
	\parmin[in] itemType - the base type of the item */ 
   void switchItem(Player* player, string itemType);

   /// let player drink potion
   /*** displays all potions that the player has in
	their inventory - and lets them select which one
	to drink
	\parmin[in] player - user's character */ 
   void drinkPotion(Player* player);
   
   ///just a function to clear the screen
   void clearScreen();

   /// lets the player drop items
   ///\parmin[in] player - user's character 
   void dropItem(Player * player);

   ///pauses the screen before next scene
   void pauseScreen();

   ///allows player to loot monster after a win
   /*** at the end screen the function will display the
	monster's inventory and lets the player choose
	whether they would like to take the item or
	if they would like to skip to the next
	\parmin[in] player - user's character
	\parmin[in] monster - the monster that was defeated */ 
   void lootMonster(Player* player, Monster* monster);

   ///Creates the monster for the battle sequence
   /*** The monster that is generated is depedent on the player's level
	with the exception of the boss that is currently hard coded due to
	time constraints
	\parmin[in] isBoss - whether the monster is the level 13 boss or not
	\parmin[in] initiallevel - the level of the player unless overidden by boss
	\return a pointer to the newly created monster */ 
   Monster* generateMonster(string isBoss, int initialLevel);

   ///menu for the attack
   ///\return the int for the selection by player in attackmenu 
   int attackMenu();

   ///menu for inventory
   ///\parmin[in] player - user's character - required for displaying inventory
   ///\return the int for the selection of the player
   int inventoryMenu(Player * player);

   ///player won sequence
   /// this function handles the sequence when the player defeats the monster
   /// \parmin[in] player - the user's character
   ///\parmin[in] monster - the monster that they successfully defeated! yeaahhh 
   void playerWon(Player* player, Monster* monster);

   /// monster won and defeated the player
   /// this handles the sequence for when the player loses the game
   /// currently we just exit them

   void monsterWon(); 
   
};

#endif // MAP_H
