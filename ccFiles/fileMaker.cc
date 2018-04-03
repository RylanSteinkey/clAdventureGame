///\Author: Rylan Steinkey
///\Date: Nov 7th, 2017

///This file creates txt files for items and generates their stats.

#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

int main()
{
   string name;
   cout << "Enter the name of the file:   ";
   cin >> name;
   ofstream myFile;
   myFile.open(name.c_str());
   int value = 6;
   int counter =0;

   for(int i = 1 ; i < 11 ; i++)
   {
      	 int tempVal = value;
      for(int j = 1 ; j < 4 ; j++)
      {
	 myFile << i << " " << tempVal  << " " << ((3*i)+j);
	 int element = rand() %5+1;
	 myFile << " " << element << endl;
	 tempVal = tempVal + j;
	 counter++;
      }
      value= value*1.5;
   }

   myFile << endl 
	  << "Each item has information stored in the following order: " << endl
	  << "itemLevel itemValue attackStat weaponElement itemName " << endl
	  << "For element: 1=Fire 2=Water 3=Earth 4=Air 5=None" << endl
	  << "Written by Rylan" << endl
	  << "There are " << counter << " items, move this number to top";


   
   myFile.close();
   return 0;
}
