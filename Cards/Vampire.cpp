//
// Created by omarz on 13/06/2022.
//

#include "Vampire.h"

Vampire::Vampire(): Battle("Vampire", 2, 10, 10){}
bool Vampire::applyEncounter(Player& player) const
{
    if(!Battle::applyEncounter(player))
    {
        player.damageForce();
    }
}
