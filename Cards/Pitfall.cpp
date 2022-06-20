//
// Created by omarz on 13/06/2022.
//

#include "Pitfall.h"
#include "../Players/Rouge.h"
#include <iostream>
#include <memory>

Pitfall::Pitfall(): Card("Pitfall"){}
bool Pitfall::applyEncounter(Player& player) const
{
    try
    {
        Rouge& tmp = dynamic_cast<Rouge&>(player);
        tmp.damage(10);
        return true;
    }
    catch (const std::bad_cast&)
    {
        return false;
    }
}
