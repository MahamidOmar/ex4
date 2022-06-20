//
// Created by omarz on 13/06/2022.
//

#include "Fairy.h"
#include "../Players/Wizard.h"

Fairy::Fairy(): Card("Fairy"){}
bool Fairy::applyEncounter(Player& player) const
{
    try
    {
        Wizard& tmp = dynamic_cast<Wizard&>(player);
        tmp.heal(10);
        printFairyMessage(true);
        return true;
    }
    catch (const std::bad_cast&)
    {
        printFairyMessage(false);
        return false;
    }
}

