/// YaDimSum 2720 project
/// \author Dallan Mccarthy
/// \author Joshua Pepple
/// \author Kip Jay

/** This class inherits the Map class and implements the Town event which gives
    the Player options to do a range of activities like going to the hospital,
    going to the NPC Shop keeper to either buy or sell Items. You can also see
    your Inventory and head to the next Town
*/

#ifndef TOWN_H
#define TOWN_H

#include "NPC.h"
#include "Player.h"
#include "Map.h"
#include <iostream>

using namespace std;

class Town : public Map
{
  public:

   /// This creates the Town object and picks a random name for the Town from
   /// a config file
   Town();

   /// This calls the printShopMenu() function and gets User choice and either
   /// calls the function to buy or sell or return back to previous menu
   /// \param[in] Player pointer which points to the Player object
   void shopSequence(Player *);

   /// This prints the menu when you go to the Shop keeper
   /// \param[in] Player pointer which points to the Player object
   /// \param[in] NPC pointer which points to the NPC object for ShopKeeper
   void printShopMenu(Player *,NPC *);

   /// This function lists the Items in the ShopKeeper's Inventory and allows the
   /// Player to buy as long as they had enough gold to and space in their Inventory
   /// \param[in] Player pointer which points to the Player object
   /// \param[in] NPC pointer which points to the NPC object for ShopKeeper
   void buySomeItems(Player *,NPC *);
   
   /// This function lists the Items in the Player's Inventory and allows them to
   /// sell it to the ShopKeeper as long as the Item isn't equipped
   /// \param[in] Player pointer which points to the Player object
   /// \param[in] NPC pointer which points to the NPC object for ShopKeeper
   void sellSomeItems(Player *,NPC *);

   /// This is the destructor of the Town object
   ~Town();

   /// This returns the name of the Town
   /// \return townName 
   string getTownName() const;

   /// This is called after interface() function and uses Player's choice to
   /// call the adequate functions
   /// \param[in] Player pointer which points to the Player object
   void startEvent(Player *);

   /// This displays the entrance options when Player arrives in a Town
   /// which allows user go to Hospital, or go to ShopKeeper or go to next Town
   /// or open their Inventory
   /// \param[in] Player pointer which points to the Player object
   void interface(Player *);


  private:
   /// This is the name of the Town
   string townName;

   /// This is a private member used in functions to store user input from
   /// a list of options
   int ch;
};

#endif
