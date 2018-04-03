/// \author Rylan Steinkey
/// \date Oct 25th

/// header for the element class
/// has subclasses fire, air, earth, water and normal

#ifndef ELEMENT_H
#define ELEMENT_H
#include <iostream> 
using namespace std; 

class Element
{
    ///this is intentionally left black, The element base class can be used for
    ///future implementations but as of right now is empty.
 public:

  virtual string getElement() const = 0; 
  virtual ~Element(){};  

  
};
#endif // ELEMENT_H
