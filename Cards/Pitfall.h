//
// Created by omarz on 13/06/2022.
//

#ifndef EX4_PITFALL_H
#define EX4_PITFALL_H

#include "Card.h"

class Pitfall : public Card{
public:
    Pitfall();
    bool applyEncounter(Player& player) const override;
};


#endif //EX4_PITFALL_H
