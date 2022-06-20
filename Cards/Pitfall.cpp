//
// Created by omarz on 13/06/2022.
//

#include "Pitfall.h"
#include "../Players/Rogue.h"
#include <iostream>
#include <memory>

Pitfall::Pitfall(): Card("Pitfall"){}
bool Pitfall::applyEncounter(Player& player) const
{
    try
    {
        dynamic_cast<Rogue&>(player);
        printPitfallMessage(true);
        return true;
    }
    catch (const std::bad_cast&)
    {
        player.damage(10);
        printPitfallMessage(false);
        return false;
    }
}
