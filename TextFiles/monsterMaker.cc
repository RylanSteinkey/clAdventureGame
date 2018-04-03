#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

int main()
{
   string fN;
   cout << "Enter filename --> ";
   cin >> fN;
   // element types
   string e[5] = { "Fire", "Water", "Earth", "Air", "None" };
   ofstream o;
   o.open(fN.c_str());

   //count 
   int num = 0;
   //starting health
   int dHealth = 20;
   // starting attack
   int dAttack = 4;
   // starting defense
   int dDefense = 5;
   //stores j eventually
   int temp = 0;
   // this handles the total number of levels of monster
   for (int i = 1; i < 11; ++i)
   {
      // this handles the number of monsters per level taking the same stats per level
      for (int j = 0; j < 5; j++)
      {
	 o << i << " " << dHealth << " " << dAttack << " " << dDefense  << " "
	   << e[j] << endl;
	 num++;
	 temp = j;
      }
      dHealth += 2;
      dAttack += i * 0.35;
      dDefense += i * 0.35;
   }
   o << endl;
   o << "This file contains Monsters' data stored in the order: Level, health, attack, defense, element" << endl;
   o << "Written by Joshua Pepple" << endl;
   o << num << " monsters" << endl;
   o.close();
   return 0;
}
