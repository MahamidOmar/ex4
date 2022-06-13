//
// Created by omarz on 13/06/2022.
//

#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H
#include "Player.h"
#include <string>

class Wizard : public Player{
    Wizard(string name);
    void heal(int hp) override;
    void printPlayerInfo(ostream& os) const override;
};


#endif //EX4_WIZARD_H
