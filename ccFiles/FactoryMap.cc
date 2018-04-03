///Implement factory pattern for Map.
///\author Aditya Joshi
///\date Nov 22, 2017
#include "../headers/Town.h"
#include "../headers/Map.h"
#include "../headers/Castle.h"
#include "../headers/Road.h"

#include <stdlib.h>
#include <string>
#include <time.h>
using namespace std;

Item *FactoryMap::createMapItem(const string &type)
{
   if(type == "Town")
      return new Town();
   else if(type == "Castle")
      return new Castle();
   else if(type == "Road")
      return new Road();
   else
      return NULL;
}
	   
