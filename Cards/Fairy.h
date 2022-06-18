//
// Created by omarz on 13/06/2022.
//

#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H

#include "Card.h"

class Fairy : public Card{
public:
    Fairy();
    bool applyEncounter(Player& player) const override;

};


#endif //EX4_FAIRY_H
