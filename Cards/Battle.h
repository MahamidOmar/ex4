//
// Created by omarz on 13/06/2022.
//

#ifndef EX4_BATTLE_H
#define EX4_BATTLE_H

#include "Card.h"


class Battle : public Card{
public:
    Battle(string name, int loot, int force, int damage);
    void applyEncounter(Player& player) const override;
    void printInfo(ostream& os) const override;

protected:
    int m_loot;
    int m_force;
    int m_damage;
};


#endif //EX4_BATTLE_H
