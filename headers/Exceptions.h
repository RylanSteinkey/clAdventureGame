//
/// YaDimSum 2720 Project 
//
/// \author Kip Jay
/// \author Rylan Steinkey
/// \author Dallan Mccarthy
/// \author Joshua Pepple
/// \date October 17, 2017
///
///
/// This file contains a number of exception classes for the classes of this project
///

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string> 
using namespace std;
///
///This is an exception to be thrown when the item number selected is out of
/// bounds.
///
class invalidItemError : public runtime_error
{
  public:
  invalidItemError(const string &arg)
     : runtime_error(arg) {}; 

};

/// This exception is thrown when player tries to buy an Item from an NPC but has insufficient funds for the purchase
class invalidFunds : public runtime_error
{
  public:
  invalidFunds(const string &arg)
     : runtime_error(arg) {};
};

class invalidRemove : public runtime_error
{
  public:
   invalidRemove(const string &arg)
      : runtime_error(arg) {};
};

class invalidInput  : public runtime_error
{
  public:
   invalidInput(const string &arg)
      : runtime_error(arg) {}; 
};

class invalidFormat : public runtime_error
{
  public:
   invalidFormat(const string&arg)
      : runtime_error(arg) {};
};

/// This error is thrown when user picks a choice not specified from a range of choices or enters an invalid character
class invalidChoice : public runtime_error
{
  public:
  invalidChoice() : runtime_error("You have entered a wrong choice.") {}

};

class invalidExchange : public runtime_error
{
 public:
  invalidExchange(const string&arg)
    : runtime_error(arg) {};
};

class invalidFile : public runtime_error
{
  public:
   invalidFile(const string&arg)
      : runtime_error(arg) {};
};

class battleError : public runtime_error
{
  public:
   battleError(const string&arg)
      : runtime_error(arg) {};
}; 


#endif
