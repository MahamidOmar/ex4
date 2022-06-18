//
// Created by omarz on 13/06/2022.
//

#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

#include "Card.h"

class Treasure : public Card {
public:
    Treasure();
    bool applyEncounter(Player& player) const override;

};


#endif //EX4_TREASURE_H
