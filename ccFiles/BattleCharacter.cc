/// YaDimSum 2720 project
/// \author Joshua Pepple   

#include "../headers/BattleCharacter.h"
#include <iostream>

using namespace std;


/// returns the health of BattleCharacter
/// \return charHealth
int BattleCharacter::getHealth() const
{
    return charHealth;
}

/// returns the attack stat of BattleCharacter
/// \return charAttack                                                       
int BattleCharacter::getAttack() const
{
    return charAttack;
}


/// returns the defense stat of BattleCharacter
/// \return charDefense                        
int BattleCharacter::getDefense() const
{
    return charDefense;
}

/// returns the level of BattleCharacter
/// \return charLevel               
int BattleCharacter::getLevel() const
{
    return charLevel;
}

/// returns the max health of BattleCharacter
/// \return charMaxHealth                                           
int BattleCharacter::getMaxHealth() const
{
    return charMaxHealth;
}

/// changes the health of BattleCharacter by integer passed.
/// A positive integer increases it while negative integer decreases it
/// \param[in] changeBy is used to modify charHealth            
void BattleCharacter::changeHealth(int changeBy)
{
    charHealth += changeBy;
}
