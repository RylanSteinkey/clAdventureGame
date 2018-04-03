#include "Fire.h"
#include "Water.h"
#include "Air.h"
#include "Earth.h"
#include "Element.h"

#include <string>

#ifndef FACTORYELEMENT_H
#define FACTORYELEMENT_H

class FactoryElement
{
  public:

   /// factory to create an element pointer
   ///\param[in] int the corresponding value of the required element
   ///where 1 is fire, 2=water, 3= earth , 4= Air, 5= Normal
   ///\return Element* a pointer to the appropriate element class
  static Element * createElement(int);

  static Element * createElement(string&); 

};

#endif 
