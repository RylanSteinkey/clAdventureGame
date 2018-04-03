#makefile for yadimsum to get the base of it at least compiling .. 
#we might want to make other makefiles for your own testing 
#but maybe this one will become the main one 
#This will be the first makefile .. and then I will hopefully convert to the archive 

CCC = g++  
HDR_DIR = ../headers
CCCFLAGS = -Wall -std=c++11 
CHARACTERS = Character.o BattleCharacter.o Monster.o Player.o UndeadMonster.o MeleeMonster.o FlyingMonster.o NPC.o FactoryMonster.o
INVENTORYITEMS = Inventory.o Bow.o Sword.o Staff.o Potion.o Weapon.o FactoryItem.o Item.o Armour.o
ELEMENTS = Air.o Earth.o Fire.o Water.o Normal.o FactoryElement.o
BATTLE = Battle.o 
MAP = Map.o Road.o Town.o
TEST = RoadTest.o TownTest.o BattleTest.o 

.PHONEY : all 
#************************************************************************

all: FullGame  CPPTEST


FullGame: $(CHARACTERS) $(INVENTORYITEMS) $(BATTLE) $(MAP) $(ELEMENTS) MainProgram.o 
	$(CCC) $(CCCFLAGS) $^ -o $@
#*************************************************************************
# Space for testing your section ? 


#************************************************************************

CPPTEST: BattleTest.o CPPUNITTEST.o $(BATTLE) $(CHARACTERS) $(INVENTORYITEMS) $(ELEMENTS) $(MAP)
	$(CCC) $(CCCFLAGS) -lcppunit -ldl $^ -o $@

#**********************************************************************

ItemTester.o: $(HDR_DIR/Item.h) 

MainProgram.o: $(HDR_DIR/BattleCharacter.h)

BattleTester.o : $(HDR_DIR/Battle.h) 

BattleCharacter.o: $(HDR_DIR/BattleCharacter.h) $(HDR_DIR/Character.h)

Character.o : $(HDR_DIR/Character.h) $(HDR_DIR/Inventory.h)

Monster.o : $(HDR_DIR/Monster.h) $(HDR_DIR/BattleCharacter.h)

Player.o : $(HDR_DIR/Player.h) $(HDR_DIR/BattleCharacter.h) 

NPC.o : $(HDR_DIR/NPC.h)

Inventory.o : $(HDR_DIR/Inventory.h) $(HDR_DIR/Character.h) $(HDR_DIR/Player.h) $(HDR_DIR/Item.h) $(HDR_DIR/FactoryItem.h) $(HDR_DIR/Armour.h)


Item.o : $(HDR_DIR/Item.h)

Armour.o : $(HDR_DIR/Armour.h)

Bow.o : $(HDR_DIR/Bow.h)

Sword.o : $(HDR_DIR/Sword.h)

Staff.o : $(HDR_DIR/Staff.h)

Potion.o : $(HDR_DIR/Potion.h)

FactoryItem.o: $(HDR_DIR/FactoryItems.h) $(HDR_DIR/Weapons.h) $(HDR_DIR/Armour.h) $(HDR_DIR/Potion.h) $(HDR_DIR/Bow.h) $(HDR_DIR/Sword.h)  $(HDR_DIR/Staff.h) $(HDR_DIR/Item.h)

Battle.o : $(HDR_DIR/Battle.h) $(HDR_DIR/BattleCharacter.h) $(HDR_DIR/Character.h) $(HDR_DIR/Weapon.h) $(HDR_DIR/Element.h)

Map.o : $(HDR_DIR/Map.h)

Road.o : $(HDR_DIR/Road.h)

Town.o : $(HDR_DIR/Town.h) $(HDR_DIR/Map.h) $(HDR_DIR/Player.h) $(HDR_DIR/NPC.h) $(HDR_DIR/Inventory.h)

Weapon.o : $(HDR_DIR/Weapon.h)

Air.o : $(HDR_DIR/Air.h)

Water.o : $(HDR_DIR/Water.h)

Fire.o : $(HDR_DIR/Fire.h)

Earth.o : $(HDR_DIR/Earth.h)

Normal.o : $(HDR_DIR/Normal.h) 

FactoryElement.o : $(HDR_DIR/FactoryElement.h)

UndeadMonster.o : $(HDR_DIR/UndeadMonster.h) 

MeleeMonster.o : $(HDR_DIR/MeleeMonster.h)

FlyingMonster.o : $(HDR_DIR/FlyingMonster.h)

FactoryMonster.o : $(HDR_DIR/FactoryMonster.h) 
#*******************************************************************

BattleTest.o : $(HDR_DIR/BattleTest.h)

CPPUNITTEST.o : $(HDR_DIR/BattleTest.h)
#*******************************************************************

%.o: %.cc 
	$(CC) -c $(CCCFLAGS) $<


clean:
	rm -f *~ *.o *.#*

clean-all: clean 
	rm -f FullGame CPPTEST BattleTesting InventoryTesting ItemTesting MonsterTesting PlayerTesting NPCTesting TownTesting
