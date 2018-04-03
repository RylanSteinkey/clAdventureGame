/// \author Rylan Steinkey
/// \date Oct 25th

/// header for the earth element
/// earth is a subclass of the element class

#ifndef EARTH_H
#define EARTH_H

#include "Element.h"

class Earth : public Element
{

  string getElement() const; 
    ///This class is being used for a typeid comparasion when figuring out damage bonuses
    ///it can be used for furthur implentations but as of right now is being left empty
};
#endif
