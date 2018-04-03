#include <iostream>
#include "../headers/Map.h"
#include "../headers/Battle.h"
#include <iomanip>
#include "../headers/FactoryMonster.h"
#include "../headers/FlyingMonster.h"
#include "../headers/Exceptions.h"
#include <stdexcept> 
#include <string>
#include "../headers/Player.h"
#include <vector>
#include "../headers/Item.h" 
#include <limits>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "../headers/Monster.h"

using namespace std;
/* 
 * This is sequence goes through a fight with monster 
 * this is outside of battle due to the other function calls that need to be made 
 * that is used elsewhere within the map function eg. Inventoryactivity
 * The sequence goes either 1: You attack the monster it attacks you 
 *                          2: You do something in your inventory - forfeit a turn - Monster attacks you 
 *                          3: try to run ... currently I wouldn't recommend it ;) 
 * After the battle ends either 1: You won and you may loot the monster for the item it has stored
 *                              2: You have lost get rekt no re 
 */

void Map::battleSequence(Player* player, string isBoss)
{
   Monster * monster;

   // Creating the monster + giving it an item randomly according to the list 
   monster = generateMonster(isBoss, player->getLevel());
  
   Battle battle;
   cout << "You have entered a battle with " << monster->getName() << endl;
   cout << '\n' << '\n';

   
   while(true)
   {

      try
      {
	 battle.stats(player, monster);
	 int option = attackMenu();

	 clearScreen();
	 switch(option)
	 {
	    case 1:
	       clearScreen(); 
	       battle.playerAttack(player, monster);
	       if(battle.isDead(monster))
	       {
		  playerWon(player, monster);
		  return;
	       }
	       battle.monsterAttack(player, monster);
	       cout << '\n' << '\n'; 
	       if(battle.isDead(player))
	       {
		  monsterWon();
		  return;
	       }
	       break;
	    case 2:
	       inventoryActivity(player);
	       clearScreen();
	       battle.monsterAttack(player, monster); 
	       if(battle.isDead(player))
	       {
		  monsterWon();
		  return;
	       }
	       break;
		
	    case 3:
	    {
	       clearScreen();
	       cout << '\n' << '\n';

	       srand(time(NULL));
	       int escapePossibility = rand() % 10 + 1;
		
	       if (escapePossibility >= 5)
	       {
		  cout << "You have successfully escaped from the monster! \n \n";
		  return;
	       }
	       else
	       {
		  cout << "You can't escape this time!" << endl;
		  battle.monsterAttack(player, monster);
		  if(battle.isDead(player))
		     monsterWon();
		
		  break;
	       }
	    }
	    default:
	       break;
	 }
      }

      catch(const invalidInput error)
      {
	 clearScreen();
	 cout << '\n' << error.what() << endl; 
      }
   }
   delete monster;
}

/* Function to deal with anything the player may want to do 
 * in their inventory 
 * You can either change the weapon/armour you have on 
 * drink a potion 
 * drop an item 
 */
void Map::inventoryActivity(Player* player)
{
   try{
    
      int select = inventoryMenu(player); 
      switch(select)
      {
	 case 1:
	    switchItem( player, "Weapon");
	    break;
	 case 2 :
	    switchItem(player, "Armour");
	    break;
	 case 3:
	    drinkPotion(player);
	    clearScreen();
	    break; 
	 case 4:
	    dropItem(player);
	    break;
	 case 5:
	    clearScreen();
	    return;
	    break;  
      }
   }
   catch(const invalidInput error)
   {
      clearScreen(); 
      cout << error.what() << endl;
      inventoryActivity(player); 
   }
  
   
}

void Map::switchItem(Player* player, string itemType)
{

/*  due to the dynamic nature of the player's inventory
 * hackiest way to display select items we must get the base type 
 * then store a temp to the same pointer as we cannot know the indexes at this time
 * if there is a better way plz tell me 
 */ 

   try
   {
      cout << "Which " << itemType << " would you like to switch with?" << endl;
      vector<Item*> temp; 
      for(int i = 0; i < player->getInventory()->getCurrentSize(); i++)
      {
	 if(player->getInventory()->getInventoryPointer(i)->getBaseType() == itemType)
	    temp.push_back(player->getInventory()->getInventoryPointer(i) );
      }
      for(unsigned int i = 0; i < temp.size(); i++)
	 cout << i << ": " <<  temp[i]->getItemName() << endl;
      cout << "Which item would you like to switch with? " << endl;
      unsigned int exchange;
      cin >> exchange;
      if(cin.fail())
      {
	 cin.clear(); 
	 cin.ignore();
	 throw invalidInput ("Not a valid format");
      }
      if(exchange > temp.size())
	 throw invalidExchange("Not a valid Item to exchange with");
      cout << temp[exchange]->getItemName() << endl; 
      if(itemType == "Weapon") 
	 player->changeWeapon(temp[exchange]);
      if(itemType == "Armour")
	 player->changeArmour(temp[exchange]);
   }



  
   catch(const invalidExchange error)
   {
      clearScreen(); 
      cout << error.what() << endl;
      switchItem(player, itemType); 
   }
   catch(const invalidInput error)
   {
      clearScreen(); 
      cout << error.what() << endl;
   }
  
}
  
void Map::drinkPotion(Player * player)
{
   /*  due to the dynamic nature of the player's inventory
    * hackiest way to display select items we must get the base type 
    * then store a temp to the same pointer as we cannot know the indexes at this time
    * if there is a better way plz tell me 
    */ 
   try {
      
      cout << "Which Potion Would you like to drink?" << endl;
      vector<Item*> temp;
      // keep a temp record of the index so we know which item to remove from inventory 
      vector<int> index; 
      for(int i = 0; i < player->getInventory()->getCurrentSize(); i++) 
      {
	 if(player->getInventory()->getInventoryPointer(i)->getBaseType() == "Potion")
	 {
	    temp.push_back(player->getInventory()->getInventoryPointer(i) ); 
	    index.push_back(i);
	 }
      }
      for(unsigned int i = 0; i < temp.size(); i++)
	 cout << i << ": " <<  temp[i]->getItemName() << " Health Regen: " << temp[i]->getStat() << endl;
      cout << endl << "Or enter " << index.size() << " to go back." << endl;
      unsigned int drink;
      cin >> drink;

      if (drink == index.size())
	 return;
      if(cin.fail())
      {
	 cin.clear(); 
	 cin.ignore();
	 throw invalidInput ("Not a valid format");
      }
      if(drink > temp.size())
	 throw invalidExchange("Not a valid Item to exchange with");

      
      player->changeHealth(temp[drink]->getStat());
      player->getInventory()->removeItem(index[drink]);
   }


  
   catch(const invalidExchange error)
   {
      clearScreen(); 
      cout << error.what() << endl;
      drinkPotion(player); 
   }
   catch(const invalidInput error)
   {
      clearScreen(); 
      cout << error.what() << endl;
   }
  
}

void Map::buyItem(int c, Character * char1, Character * char2)
{
   char1->getInventory()->addItem(char2->getInventory()->getInventoryPointer(c));
   char2->getInventory()->removeItem(c);
}

void Map::clearScreen()
{
   cout << string( 100, '\n' );
}

void Map::dropItem(Player * player)
{
   try{
    
      cout << "Which item would you like to drop?" << '\n' << endl;
      player->getInventory()->displayInventory(); 
      int drop;
      cin >> drop;
      if(cin.fail())
      {
	 cin.clear(); 
	 cin.ignore();
	 throw invalidInput ("Not a valid format");
      }
      if(drop >= player->getInventory()->getCurrentSize())
	 throw invalidExchange("You're trying to drop nothing..");

      if (player->getInventory()->getInventoryPointer(drop) == player->getWeapon())
	 throw invalidRemove("You're trying to drop the weapon you're wielding");
      if (player->getInventory()->getInventoryPointer(drop) == player->getArmour())
	 throw invalidRemove("You're trying to drop the armour you're wearing");
      player->getInventory()->removeItem(drop );
   }
  
   catch(const invalidExchange error)
   {
      clearScreen(); 
      cout << error.what() << endl;
      dropItem(player); 
   }
   catch(const invalidInput error)
   {
      clearScreen(); 
      cout << error.what() << endl;
   }
   catch(const invalidRemove error)
   {
      clearScreen();
      cout << error.what() << endl;
   }
}

void Map::pauseScreen()
{

   char useless; 
   cout << "Hit c to continue " << endl;
   cin >>useless;

   switch(useless)
   {      
      case 'c': case 'C':
	 break;
      default:
	 pauseScreen();
   }
}

void Map::lootMonster(Player* player, Monster* monster)
{
    
   monster->printInventory();
   int backChoice = monster->getInventory()->getCurrentSize();
   cout << "Pick the item that you want to add or enter " << backChoice << " to continue to Town."<< endl << "> ";
   int select;
   bool choice = false;
   
   while (!choice)
   {
      try
      {
	 cin >> select;
	 
	 if (cin.fail())
	 {
	    cin.clear();
	    cin.ignore();
	    clearScreen();
	    throw invalidChoice();
	 }
	 else if (select == backChoice && !cin.fail())
	 {
	    choice = true;
	    clearScreen();
	    return;
	 }
	 
	 else if(select >= monster->getInventory()->getCurrentSize())
	 {
	    throw invalidChoice();
	    //throw invalidInput("Not a valid item to select");
	 }
	 
	 else
	 {
	    choice = true;
	 }
      }

      catch(invalidChoice &n)
      {
	 clearScreen();
	 cout << n.what() << endl;
	 monster->printInventory();
	 
	 int backChoice = monster->getInventory()->getCurrentSize();
	 cout << "Pick the item that you want to add or enter " << backChoice
	      << " to continue to Town."<< endl << "> ";
      }
   }
   
   buyItem(select, player, monster);
   clearScreen(); 
   cout << "You've looted!" << endl;
   cout << "This is your inventory now!" << endl;
   player->printInventory();
   pauseScreen();
   clearScreen();
    
}

int Map::attackMenu()
{
   cout << '\n' << '\n' << '\n' << "What would you like to do?" << endl;
   cout << setw(75) << '\n'
	<< "1: Attack the Monster!" << '\n'
	<< "2: View inventory - Monster will attack you during this" << '\n'
	<< "3: try to run away" << endl;
   int option;
   cin >> option;

   if(cin.fail() ||( option != 1 && option !=2 && option!=3))
   {
      cin.clear(); 
      cin.ignore();
      throw invalidInput("Not one of the inputs!");
   }
	 
   return option; 
}

int Map::inventoryMenu(Player * player)
{
   clearScreen();
   cout << "Here is your backpack!" << endl;
   player->printInventory();
   cout << setw(20) << left << "Your current Weapon is:" << setw(20) << right
	<< player->getWeapon()->getItemName() << '\n'
	<< setw(20) << left << "Your current Armour is: " << setw(20) << right
	<< player->getArmour()->getItemName()  << '\n';
    
   cout << "What would you like to do ?" << endl;
  
   cout << setw(20) << left << "1: Change Weapon" << '\n'
	<< setw(20) << left << "2: Change Armour" << '\n'
	<< setw(20) << left << "3: Drink Potion" << '\n'
	<< setw(20) << left << "4: Drop Item" << '\n'
	<< setw(20) << left << "5: Go back to previous menu" << '\n';
   int select;
   cin >> select;
   if(cin.fail() || (select!=1 && select!=2 && select!=3 &&select!= 4&&select!= 5))
   {
      cin.clear();
      cin.ignore();
      throw invalidInput("Invalid input");
   }
   return select; 
}

Monster* Map::generateMonster(string isBoss, int initialLevel)
{
   /* aware of the hackiness nature of this statement right now 
    */ 
   int level; 
   Monster * monster;
     
   srand(time(NULL));
   int randInt = rand () % 3;
   if (isBoss == "Boss")
   {
      monster = FactoryMonster::createMonster("Flying", 13);
      level = 13;
   } 
   else
   {
      level = initialLevel;

      if( level == 1 || level == 2 || level == 3)
	 randInt = rand() % 2 + 1;
      if(randInt == 0)
	 monster = FactoryMonster::createMonster("Flying", level);
      else if(randInt == 1)
	 monster = FactoryMonster::createMonster("Undead", level);
      else if(randInt == 2)
	 monster = FactoryMonster::createMonster("Melee", level);
   }
   Item * monsterItem;
  
   if(randInt == 0)
      monsterItem = FactoryItem::createItem("Staff", level);
   if(randInt ==1)
      monsterItem = FactoryItem::createItem("Bow", level);
   if(randInt==2)
      monsterItem = FactoryItem::createItem("Sword", level);
   
   
   monster->getInventory()->addItem(monsterItem);

   return monster; 
}

void Map::playerWon(Player* player, Monster* monster)
{
   cout << " You have defeated the monster! congratulations!" << endl;
   cout << " You may loot the monster now!" << endl;
   player->addEXP(player->getLevel() * 2);
   player->levelUp();
   player->changeGold(player->getLevel() *3);
   
   try
   {
      lootMonster(player, monster);
   }
   catch(const invalidInput error)
   {
      cout << error.what() << endl;
      lootMonster(player, monster); 
   }
}

void Map::monsterWon()
{
   //call end game sequence 
   cout <<" You lost! GAME OVER" << endl;
   exit(0); 


}
