//
// Created by omarz on 13/06/2022.
//

#include "Fairy.h"
#include "Players/Wizard.h"

Fairy::Fairy(): Card("Fairy"){}
bool Fairy::applyEncounter(std::shared_ptr<Player> player) const
{
    std::shared_ptr<Wizard> tmp = std::dynamic_pointer_cast<Wizard>(player);
    if(tmp != nullptr)
    {
        player->heal(10);
        return true;
    }
    else
    {
        return false;
    }
}

