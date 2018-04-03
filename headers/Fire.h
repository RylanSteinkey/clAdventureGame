/// \author Rylan Steinkey
/// \date Oct 25th

///header for the fire element
/// fire is a subclass of the element class

#ifndef FIRE_H
#define FIRE_H

#include "Element.h"

class Fire : public Element
{

  string getElement() const; 
    ///This class is being used for a typeid comparasion when figuring out damage bonuses
    ///it can be used for furthur implentations but as of right now is being left empty
};
#endif // FIRE_H
