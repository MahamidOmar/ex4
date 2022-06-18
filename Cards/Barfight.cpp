//
// Created by omarz on 13/06/2022.
//

#include "Barfight.h"
#include "Players/Fighter.h"

Barfight::Barfight(): Card("Barfight"){}
bool Barfight::applyEncounter(Player& player) const
{
    try
    {
        Fighter& tmp = dynamic_cast<Fighter&>(player);
        tmp.damage(10);
        return true;
    }
    catch (const std::bad_cast&)
    {
        return false;
    }
}

