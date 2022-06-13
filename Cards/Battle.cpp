//
// Created by omarz on 13/06/2022.
//

#include "Battle.h"

Battle::Battle(string name, int loot, int force, int damage): Card(name), m_loot(loot), m_force(force), m_damage(damage)
{}

////get param shared_ptr
void Battle::applyEncounter(Player& player) const
{

}

void Battle::printInfo(ostream& os) const
{
    printCardDetails(os, m_name);
    printMonsterDetails(os, m_force, m_damage, m_loot, (m_name.compare("Dragon") == 0));
    printEndOfCardDetails(os);
};


