#include"../headers/Item.h"
#include"../headers/FactoryItem.h"
#include"../headers/Armour.h"
#include "../headers/Element.h"
#include"../headers/Fire.h" 
#include<iostream>
#include<string> 

using namespace std;

int main(void)
{  
   int testingLevel = 9;
   Item * armourTest = FactoryItem::createItem("Armour", testingLevel);

   cout <<"Armour:" << endl
	<<"Name: " <<  armourTest->getItemName() << endl
	<<"Value: " << armourTest->getItemValue() << endl
	<<"Level: " << armourTest->getItemLevel() << endl
        <<"Defense Stat: " << armourTest->getStat() << endl << endl;

   //*******************************************************
   
   Item * potionTest = FactoryItem::createItem("Potion", testingLevel);

   cout <<"Potion:" << endl
	<<"Name: " << potionTest->getItemName() << endl
	<<"Value: " << potionTest->getItemValue() << endl
	<<"Level: " << potionTest->getItemLevel() << endl
	<<"Health Stat: " << potionTest->getStat() << endl << endl;

   //*******************************************************

   Item * swordTest = FactoryItem::createItem("Sword", testingLevel);

   cout <<"Sword:" << endl;
   cout <<"Name: " << swordTest->getItemName() << endl;
   cout <<"Value: " << swordTest->getItemValue() << endl;
   cout <<"Level: " << swordTest->getItemLevel() << endl;
   cout <<"Attack Stat: " << swordTest->getStat() << endl;
   cout <<"Type: " << swordTest->getType() << endl;
   cout <<"Element: " << swordTest->getElementPointer()->getElement()<< endl<<endl;

   //*******************************************************

   Item * bowTest = FactoryItem::createItem("Bow", testingLevel);

   cout <<"Bow:" << endl
	<<"Name: " << bowTest->getItemName() << endl
	<<"Value: " << bowTest->getItemValue() << endl
	<<"Level: " << bowTest->getItemLevel() << endl
	<<"Attack Stat: " << bowTest->getStat() << endl
	<<"Type: " << bowTest->getType() << endl
	<<"Element: " << bowTest->getElementPointer()->getElement()<< endl<<endl;

      //*******************************************************

   Item * staffTest = FactoryItem::createItem("Staff", testingLevel);

   cout <<"Staff:" << endl
	<<"Name: " << staffTest->getItemName() << endl
	<<"Value: " << staffTest->getItemValue() << endl
	<<"Level: " << staffTest->getItemLevel() << endl
	<<"Attack Stat: " << staffTest->getStat() << endl
	<<"Type: " << staffTest->getType() << endl
	<<"Element: " << staffTest->getElementPointer()->getElement()<< endl<<endl;
   
}
