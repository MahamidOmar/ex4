//
// Created by omarz on 13/06/2022.
//

#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"

class Barfight : public Card{
public:
    Barfight();
    bool applyEncounter(std::shared_ptr<Player> player) const override;

};


#endif //EX4_BARFIGHT_H
