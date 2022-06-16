//
// Created by omarz on 13/06/2022.
//

#include "Barfight.h"
#include "Players/Fighter.h"

Barfight::Barfight(): Card("Barfight"){}
bool Barfight::applyEncounter(std::shared_ptr<Player> player) const
{
    std::shared_ptr<Fighter> tmp = std::dynamic_pointer_cast<Fighter>(player);
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

