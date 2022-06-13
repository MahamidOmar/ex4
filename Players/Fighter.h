//
// Created by omarz on 13/06/2022.
//

#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H
#include "Player.h"
#include <string>

class Fighter :public Player{
    Fighter(const string& name);
    int getAttackStrength()const override;
    void printPlayerInfo(ostream& os) const override;
};


#endif //EX4_FIGHTER_H
