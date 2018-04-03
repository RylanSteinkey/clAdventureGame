///The Road class is a subclass of Map. It will implement Road activity.
#ifndef ROAD_H
#define ROAD_H

#include "Map.h"
#include <fstream>
#include "Player.h"
#include "Monster.h"

using namespace std;

class Road : public Map
{

 public:

  ///Behaviours


  ///Constructor to create a road.
  
  public:
  
  Road();  
  ~Road(){};

  void startBattle(Player* player);
  
  protected:

};

#endif // ROAD_H
