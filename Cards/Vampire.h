//
// Created by omarz on 13/06/2022.
//

#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H

#include "Card.h"
#include "Battle.h"

class Vampire : public Battle{
public:
    Vampire();
    bool applyEncounter(Player& player) const override;
};


#endif //EX4_VAMPIRE_H
