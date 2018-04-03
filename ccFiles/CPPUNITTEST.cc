#include <cppunit/TextTestRunner.h>
using namespace CppUnit;
#include "../headers/BattleTest.h"

int main()
{
   TextTestRunner runner;
   runner.addTest(BattleTest::suite());
   runner.run();

   return 0;
}
