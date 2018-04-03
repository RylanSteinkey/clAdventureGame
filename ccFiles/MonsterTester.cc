#include <iostream>
#include "../headers/FactoryMonster.h"
#include "../headers/FlyingMonster.h"
#include "../headers/Monster.h"
#include <string>

using namespace std;

int main()
{
   FactoryMonster A;

   Monster *a = A.createMonster("Flying", 2);
   Monster *b = A.createMonster("Melee", 10);
   Monster *c = A.createMonster("Undead", 5);
   Monster *d = A.createMonster("Flying", 13);
   
   cout << "MONSTER A LEVEL -> " << a->getLevel() << endl;
   cout << "MONSTER A DEFENSE -> " << a->getDefense() << endl;
   cout << "MONSTER A HEALTH -> " << a->getHealth() << endl;

   cout << endl;

   cout << "MONSTER B LEVEL -> " << b->getLevel() << endl;
   cout << "MONSTER B DEFENSE -> " << b->getDefense() << endl;
   cout << "MONSTER B HEALTH -> " << b->getHealth() << endl;

   cout << endl;

   cout << "MONSTER C LEVEL -> " << c->getLevel() << endl;
   cout << "MONSTER C DEFENSE -> " << c->getDefense() << endl;
   cout << "MONSTER C HEALTH -> " << c->getHealth() << endl;

   cout << endl;
   
   cout << "BOSS LEVEL -> " << d->getLevel() << endl;
   cout << "BOSS DEFENSE -> " << d->getDefense() << endl;
   cout << "BOSS HEALTH -> " << d->getHealth() << endl;

   delete a;
   delete b;
   delete c;
   delete d;
   
   return 0;
}
   
