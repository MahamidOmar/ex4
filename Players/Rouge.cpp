
#include "Rouge.h"
#include "utilities.h"

Rouge::Rouge(const string& name): Player(name)
{}

void Rouge::addCoins(int coins)
{
    if(coins < 0)
    {
        return;
    }
    this->m_coins += (2 * coins);
}


void Rouge::printPlayerInfo(ostream& os) const
{
    printPlayerDetails(os, m_name, "Rouge", m_level, m_force, m_HP.getHP(), m_coins);
}

std::unique_ptr<Player> Rouge::clone() const
{
    return std::unique_ptr<Rouge>(new Rouge(*this));
}
