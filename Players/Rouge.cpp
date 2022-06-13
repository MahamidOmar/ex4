
#include "Rouge.h"

Rouge::Rouge(string name): Player(name)
{}

void Rouge::addCoins(int coins)
{
    if(coins < 0)
    {
        return;
    }
    this->m_coins += (2 * coins);
}
