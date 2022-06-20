//
// Created by omarz on 13/06/2022.
//

#include "Barfight.h"
#include "../Players/Fighter.h"

Barfight::Barfight(): Card("Barfight"){}
bool Barfight::applyEncounter(Player& player) const
{
    try
    {
        dynamic_cast<Fighter&>(player);
        printBarfightMessage(true);
        return true;
    }
    catch (const std::bad_cast&)
    {
        player.damage(10);
        printBarfightMessage(false);
        return false;
    }
}

