//
// Created by omarz on 13/06/2022.
//

#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H
#include "Player.h"
#include <string>

class Rogue : public Player{
public:
    Rogue(const string& name);
    void addCoins(int coins) override;
    void printPlayerInfo(ostream& os) const override;
    std::unique_ptr<Player> clone() const override;
};


#endif //EX4_ROGUE_H
