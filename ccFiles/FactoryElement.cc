#include "../headers/Fire.h"
#include "../headers/Water.h"
#include "../headers/Air.h"
#include "../headers/Earth.h"
#include "../headers/Normal.h"
#include "../headers/Element.h"
#include "../headers/FactoryElement.h"
#include <string>

using namespace std; 

Element* FactoryElement::createElement(int type)
{
   ///using the int type for what element is required where:
   ///1 is fire, 2=water, 3= earth , 4= Air, 5= Normal
   ///and returns a pointer to the appriopriate element subclass
  if(type == 1)
    return new Fire;
  else if(type == 2)     
    return new Water;
  else if(type == 3)     
    return new Earth;
  else if(type == 4)       
    return new Air;
  else if(type == 5)
     return new Normal;
  else
     return new Normal;
}

Element* FactoryElement::createElement(string& type)
{

  if(type == "Fire")
    return new Fire;
  else if(type == "Water")     
    return new Water;
  else if(type == "Earth")     
    return new Earth;
  else if(type == "Air")       
    return new Air;
  else if(type == "Normal")
     return new Normal;
  else
     return new Normal;
}
