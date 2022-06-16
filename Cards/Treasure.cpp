//
// Created by omarz on 13/06/2022.
//

#include "Treasure.h"

Treasure::Treasure(): Card("Treasure"){}
bool Treasure::applyEncounter(std::shared_ptr<Player> player) const
{
    player->addCoins(10);
    return true;
}

