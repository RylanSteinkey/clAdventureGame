///
/// YaDimSum 2720 project
///
/// \author Aditya Joshi
/// \date Nov 8th, 2017
///
///
/// The Screen class displays outputs of different types on a 2 dimensional
/// array of characters,
/// showing: menus, stats, health, battles, and every other display activity

#include "Screen.h"
#include <iostream>
#include <vector> 

using namespace std;

/// Constructors a Screen object of a dynamic 2d array which is later printer out
/// to the user
///\param[in] h sets the height of the array.
///\param[in] w sets the width of the array.
Screen::Screen(int h, int w)
   : screenHeight{h}, screenWidth{w}
{
   // creates our screen vector object
   screenArray.resize(h, vector<char>(w));
   clear();
}
   
///Deallocates the 2D array.
Screen::~Screen()
{
   
}
   
///Returns the number of rows in screenHeight.
///\param[out] getRows returns the number of rows stored in screenHeight.
int Screen::getRows() const
{
   return screenHeight;
}

///Returns the number of rows in screenWidth.
///\param[out] getColumns returns the number of columns stored in screenWidth.
int Screen::getColumns() const
{
   return screenWidth;
}
   
///Prints the 2D Array to the screen.
void Screen::print() const
{
   
}
   
///Sets the position in the 2D array matching the coordinates of the 2 integers to the screen.
/// \param[in] rows is the row coordinate where character ch is to be written on the screen
/// \param[in] cols is the column coordinate where character ch is to be written on the screen
/// \param[in] ch is the character to print at position [rows, cols] on the 2D array
void Screen::set(int rows, int cols, char ch)
{
   // check to make sure the row and cols are in bounds then set
   if (0 <= row && row < screenHeight && 0 <= col && col < screenWidth)
      screenArray[row][col] = ch;
}

///Resets the contents of the 2D array to spaces.
void clear()
{
   for (int row = 0; row < screenHeight; row++)
      fill (screenArray[row].begin(), screenArray[row].end(),' ');
}
