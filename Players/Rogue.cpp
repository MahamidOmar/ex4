
#include "Rogue.h"
#include "../utilities.h"

Rogue::Rogue(const string& name): Player(name)
{}

void Rogue::addCoins(int coins)
{
    if(coins < 0)
    {
        return;
    }
    this->m_coins += (2 * coins);
}


void Rogue::printPlayerInfo(ostream& os) const
{
    printPlayerDetails(os, m_name, "Rogue", m_level, m_force, m_HP.getHP(), m_coins);
}

std::unique_ptr<Player> Rogue::clone() const
{
    return std::unique_ptr<Rogue>(new Rogue(*this));
}
