/// \author Aditya Joshi
/// \date October 25th, 2017
///
///
/*!The Screen class displays outputs of different types on a 2 dimensional array of character, showing
  menus, stats, health, battles, and every other display activity. */

#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <vector>
using namespace std;

/** The Screen Object has a dynamic 2D array to which outputs are printed on which is later displayed to the user.
    It also stores height and width of the array in screenHeight and screenWidth */
class Screen
{
    public:
   ///Behaviours
   /** Inititalizes a dynamic 2D array to spaces for a screen object, and sets the screenHeight and
       screenWidth. */
   ///\param[in] h sets the height of the array.
   ///\param[in] w sets the width of the array.
   Screen(int h, int w);
   

   ///Deallocates the 2D array.
   ~Screen();
   
   
   ///Accessors

   
   ///Returns the number of rows in screenHeight.
   ///\param[out] getRows returns the number of rows stored in screenHeight.
   int getRows() const;
   ///Returns the number of rows in screenWidth.
   ///\param[out] getColumns returns the number of columns stored in screenWidth.
   int getColumns() const;
   
   
   ///Mutators
   

   
   ///Prints the 2D Array to the screen.
   void print() const;
   
   ///Sets the position in the 2D array matching the coordinates of the 2 integers to the screen.
   /// \param[in] rows is the row coordinate where character ch is to be written on the screen
   /// \param[in] cols is the column coordinate where character ch is to be written on the screen
   /// \param[in] ch is the character to print at position [rows, cols] on the 2D array
   void set(int rows, int cols, char ch);
   
   ///Resets the contents of the 2D array to spaces.
   void clear();
   
   
  private:
   
   ///Attributes
   
   
   /// A Dynamic 2 dimensional vector of characters
   vector< vector<char> > screenArray;
   
   /// ScreenHeight stores the number of rows in 2D array.
   int screenHeight;
   /// ScreenWidth stores the number of columns in 2D array.
   int screenWidth;
};

#endif // SCREEN_H
