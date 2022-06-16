//
// Created by omarz on 13/06/2022.
//

#include "Pitfall.h"
#include "Players//Rouge.h"
#include <iostream>
#include <memory>

Pitfall::Pitfall(): Card("Pitfall"){}
bool Pitfall::applyEncounter(std::shared_ptr<Player> player) const
//bool Pitfall::applyEncounter(Player* player) const
{
    std::shared_ptr<Rouge> tmp = std::dynamic_pointer_cast<Rouge>(player);
    if(tmp != nullptr)
    {
        return false;
    }
    else
    {
        player->damage(10);
        return true;
    }
}
