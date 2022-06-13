
#include "Fighter.h"

Fighter::Fighter(string name): Player(name){}

int Fighter::getAttackStrength()const
{
    return 2 * m_force + m_level;
}
