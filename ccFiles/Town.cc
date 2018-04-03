/// YaDimSum 2720 project
/// \author Dallan Mccarthy
/// \author Joshua Pepple
/// \author Kip Jay

/** This class inherits the Map class and implements the Town event which gives
    the Player options to do a range of activities like going to the hospital,
    going to the NPC Shop keeper to either buy or sell Items. You can also see
    your Inventory and head to the next Town
*/

#include "../headers/Town.h"
#include "../headers/Map.h"
#include "../headers/Player.h"
#include "../headers/NPC.h"
#include "../headers/Inventory.h"
#include "../headers/Item.h"
#include "../headers/Exceptions.h"
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;

/// This creates the Town object and picks a random name for the Town from
/// a config file
Town::Town()
{
  ifstream extract;
  extract.open("../TextFiles/locationNames.txt");
  
  int total = 0;

  extract >> total;
  
  srand(time(NULL));
  int decide = 0;
  decide = rand() % total;

  int lines = -1;
  
  while(lines <= total)
  {
     if (lines == decide)
     {
	getline(extract, townName);
	lines++;
	break;
     }
     else
     {
	string discard;
	getline(extract, discard);
	lines++;
     }
  }
  
  extract.close();
}

/// This is the destructor of the Town object
Town::~Town()
{

}

/// This returns the name of the Town
/// \return townName 
string Town::getTownName() const
{
   return townName;
}

/// This prints the menu when you go to the Shop keeper
/// \param[in] Player pointer which points to the Player object
/// \param[in] NPC pointer which points to the NPC object for ShopKeeper
void Town::printShopMenu(Player * play, NPC * nc)
{
   clearScreen();
   cout << "Hello, welcome to the " << nc->getName() << ". ";
   cout << "How can I help you "<< play->getName() << "! "<< endl;
   cout << "1: buy an Item" << endl;
   cout << "2: sell an Item" << endl;
   cout << "3: exit shop" << endl;
   cout << "> ";
}

/// This calls the printShopMenu() function and gets User choice and either
/// calls the function to buy or sell or return back to previous menu
/// \param[in] Player pointer which points to the Player object
void Town::shopSequence(Player * player)
{
   NPC * npc = new NPC(player->getLevel());
   bool loop= true;
   while (loop)
   {
      printShopMenu(player, npc);
      try
      {
	 cin >> ch;
	 if(cin.fail()||(ch!=1 && ch!=2 && ch!=3))
	 {
	    cin.clear();
	    cin.ignore();
	    throw invalidInput("Invalid Input! Try again!");
	 }
	 switch(ch)
	 {
	    case 1:
	    {
	       buySomeItems(player, npc);
	       break;
	    }
	    case 2:
	    {
	       sellSomeItems(player, npc);
	       break;
	    }
	    case 3:
	    {
	       loop=false;
	       clearScreen();
	       break;
	    }
	    default:
	       break;
	 }
      }
      catch(invalidInput &ops)
      {
	 cout << endl;
	 cout << ops.what()<< endl;
	 cout << endl;
      }
   }
   delete npc; 
}

/// This function lists the Items in the ShopKeeper's Inventory and allows the
/// Player to buy as long as they had enough gold to and space in their Inventory
/// \param[in] Player pointer which points to the Player object
/// \param[in] NPC pointer which points to the NPC object for ShopKeeper
void Town::buySomeItems(Player * p,NPC * n)
{
   int fSpace = p->getInventory()->getFreeSpace();
   if(fSpace==0)
   {
      cout << endl;
      cout << "You do not have enough room in your inventory ";
      cout << "to buy an Item. Come back when you have room!" << endl;
      return;
   }
   else
   {
      
      cout << endl;
      clearScreen();
      n->printInventory();
      cout << endl;
      cout << p->getName() << " you have " << p->getGold();
      cout << " gold to spend.";
      int backChoice = n->getInventory()->getCurrentSize(); 
      cout << " Enter in the number of the item you want to buy or enter " << backChoice << " to return to previous menu: " <<endl;
      cout << "> ";
      int vItem;
      int pGold;
      bool choice = false;
      while(!choice)
      {
	 try
	 {
	    cin >> ch;

	    if (ch == backChoice)
	    {
	       clearScreen();
	       return;
	    }
	    
	    if (cin.fail()||ch < 0 ||(n->getInventory()->getCurrentSize()) <=ch)
	    {
	       cin.clear();
	       cin.ignore();
	       throw invalidItemError("Please, select an Item in range.");
	    }
	    else
	    {
	       vItem = n->getInventory()->getInventoryPointer(ch)->getItemValue();
	       pGold = p->getGold();
	       if( pGold < vItem )
	       {
		  cin.clear();
		  cin.ignore();
		  throw invalidFunds("You do not have enough gold for the ");
	       }
	       else
	       {
		  choice = true;
	       }
	       
	    }
	 }
	 catch(invalidItemError &a)
	 {
	    cout << endl;
	    cout << a.what()<< endl;
	    cout << endl;
	    n->printInventory();
	    cout << endl;
	    cout << p->getName() << " you have " << p->getGold();
	    cout << " gold to spend.";
	    cout << " Enter in the number of the item you want to buy:" <<endl;
	    cout << "> ";
	 }
	 catch(invalidFunds &m)
	 {
	    cout << endl;
	    cout << m.what();
	    cout << n->getInventory()->getInventoryPointer(ch)->getItemName();
	    cout << "! " << endl;
	    cout << "You are short " << vItem- pGold << " gold!" <<endl;
	    cout << "Try another item in your price range. " << endl;
	    cout << "> ";
	 }
      }
      
      p->changeGold(-vItem);
      cout << endl;
      cout << n->getInventory()->getInventoryPointer(ch)->getItemName();
      cout << " has been added to your inventory and you now have ";
      cout << p->getGold() << " gold. Please come again!"<< endl;
      buyItem(ch, p, n);
      p->printInventory();
   }
}

/// This function lists the Items in the Player's Inventory and allows them to
/// sell it to the ShopKeeper as long as the Item isn't equipped
/// \param[in] Player pointer which points to the Player object
/// \param[in] NPC pointer which points to the NPC object for ShopKeeper
void Town::sellSomeItems(Player * P, NPC * N)
{
   int pInvLength = P->getInventory()->getCurrentSize();
   if(pInvLength==0)
   {
      cout << endl;
      cout << "You have no items in your inventory to sell.";
      cout << " Come back when you have some Items to sell." <<endl;
      return;
   }
   else
   {
      clearScreen();
      P->printInventory();
      cout << endl;
      cout << "Wow " << P->getName() << " you have " ;
      cout << P->getInventory()->getCurrentSize();
      int backChoice = P->getInventory()->getCurrentSize();
      cout << " items in your Inventory. Which Items do you want to sell to me? or enter " << backChoice << " to return to previous menu. ";
      cout << endl;
      cout << "> ";
      bool choice = false;
      while(!choice)
      {
	 try
	 {
	    cin >> ch;

	    if (ch == backChoice)
	    {
	       clearScreen();
	       return;
	    }
	    
	    if(cin.fail()||ch < 0 ||(P->getInventory()->getCurrentSize()) <=ch)
	    {
	       cin.clear();
	       cin.ignore();
	       throw invalidRemove("Please, select an Item in range.");
	    }
	    else
	    {
	       if (cin.fail() || (P->getWeapon()==P->getInventory()->getInventoryPointer(ch))||(P->getArmour()==P->getInventory()->getInventoryPointer(ch)))
	       {
		  cin.clear();
		  cin.ignore();
		  throw invalidItemError("You are trying to remove one of your equipped Items!");
	       }
	       else
	       {
		  choice = true;
	       }
	    }
	 }
	 catch(invalidRemove &a)
	 {
	    cout << endl;
	    cout << a.what()<< endl;
	    cout << endl;
	    P->printInventory();
	    cout << endl;
	    cout << "Wow " << P->getName() << " you have " ;
	    cout << P->getInventory()->getCurrentSize();
	    cout << " items in your Inventory. Which Items do" ;
	    cout << " you want to sell to me? or enter " << backChoice << " to return to previous menu.";
	    cout << endl;
	    cout << "> ";
	 }
	 catch(invalidItemError &r)
	 {
	    cout << endl;

	    P->printInventory();
	    
	    cout << r.what()<<endl;
	    cout << "Please select an item to sell that is not equipped! or enter " << backChoice << " to return to previous menu." << endl;
	    cout << "> ";
	 }
      }
      cout << endl;
      int pItemVal= P->getInventory()->getInventoryPointer(ch)->getItemValue();
      P->changeGold(pItemVal);
      cout << "Thanks for selling me your";
      cout << P->getInventory()->getInventoryPointer(ch)-> getItemName();
      cout << " for " << pItemVal << " gold. You now have " ;
      cout << P->getGold() << " gold. ";
      cout << "Please come again! " << endl;
      buyItem(ch,N,P);
      P->printInventory();
   }
   
}

/// This is called after interface() function and uses Player's choice to
/// call the adequate functions
/// \param[in] Player pointer which points to the Player object
void Town::startEvent(Player *player)
{
   
   switch (ch)
   {
      case 1:
	 clearScreen();
	 cout << "Welcome to the hospital, " << player->getName() << endl << endl;

	 if (player->getHealth() == player->getMaxHealth())
	 {
	    cout << "You're all good to go!";
	    cout << endl << endl;
	 }
	 
	 else
	 {
	    player->changeHealth(player->getMaxHealth() - player->getHealth());
	    cout << "Your health is now restored to the Maximum. \n ";
	    cout << endl << endl;
	 }
	 interface(player);
	 break;
      case 2:
	 shopSequence(player);
	 interface(player);
	 break;
      case 3:
	 //return;
	 break;
      case 4:
	 inventoryActivity(player);
	 interface(player); 
	 break;
      default:
	 break;
   }
}

/// This displays the entrance options when Player arrives in a Town
/// which allows user go to Hospital, or go to ShopKeeper or go to next Town
/// or open their Inventory
/// \param[in] Player pointer which points to the Player object
void Town::interface(Player *player)
{
   cout << endl;
   cout << "Welcome to " << townName << endl;
   cout << "What would you like to do? : \n";
   cout << "1. Go to Hospital. \n";
   cout << "2. Go to Shopkeeper. \n";
   cout << "3. Go to next Town. \n";
   cout << "4. Open your Inventory.";
   cout << endl;
   cout << "> ";
   bool choice = false;
   
   while (!choice)
   {
      try
      {
	 cin >> ch;
	 if (cin.fail() || (ch != 1 && ch != 2 && ch != 3 && ch != 4))
	 {
	    cin.clear();
	    cin.ignore();
	    //ch = 0;
	    clearScreen();
	    throw invalidChoice();
	 }
	 else
	    choice = true;
      }
      catch(invalidChoice &n)
      {
	 cout << n.what() << endl;
	 cout << endl;
	 cout << "Welcome to " << townName << endl;
	 cout << "What would you like to do? : \n";
	 cout << "1. Go to Hospital. \n";
	 cout << "2. Go to Shopkeeper. \n";
	 cout << "3. Go to next Town. \n";
	 cout << "4. Open your Inventory.";
	 cout << endl;
	 cout << "> ";
      }
   }     
   startEvent(player);
}


